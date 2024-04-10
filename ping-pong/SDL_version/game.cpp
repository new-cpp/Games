#include "game.hpp"

void Game::init()
{
  if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
      puts("init");
      LOG_ERROR();
      m_running = false;
    }
  if(!(m_window = SDL_CreateWindow(TITLE,WINDOW_POSITION,WINDOW_POSITION,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN)))
    {
      puts("window");
      LOG_ERROR();
      m_running = false;
    }

  if(!(m_render = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED)))
    {
      puts("render");
      LOG_ERROR();
      m_running = false;
    }

  m_player1.set_type(Entity::TYPE::LEFT_PADDELE);
  m_player2.set_type(Entity::TYPE::RIGHT_PADDELE);
  m_ball.set_type(Entity::TYPE::BALL);
}

void Game::input( float dt)
  {
    SDL_Event e;

    while(SDL_PollEvent(&e))
      {
        if(e.type == SDL_QUIT)
          {
            m_running = false;
          }
        else if(e.type == SDL_KEYDOWN)
          {
            if(e.key.keysym.sym == SDLK_UP)
              {
                m_player2.set_direction(Vector2D{0,-1});
                m_player2.move(dt);

              }
            else if(e.key.keysym.sym == SDLK_DOWN)
              {
                m_player2.set_direction(Vector2D{0,1});
                m_player2.move(dt);
              }

          }
      }
  }



void Game::update( float dt)
  {

    if(m_ball.collide(m_player2))
      {

      }
    else if(m_ball.collide(m_player1))
      {

      }
    else if(m_ball.passed_right())
      {
        m_player2.score();
        m_ball.set_direction(Vector2D{-1,0});
        m_ball.reset_position();
      }
    else if(m_ball.passed_left())
      {
         m_player1.score();
         m_ball.set_direction(Vector2D{1,0});
         m_ball.reset_position();
      }
    else if(m_ball.hit_wall())
      {

      }

    m_ball.move(dt);
    m_player1.set_y(m_ball.get_y()+ m_ball.get_h()/2 - PADDELE_HEIGHT/2 );//ai hhhh!

  }

void Game::render()
  {
    SDL_SetRenderDrawColor(m_render,0xff,0xff,0xff,0xff);
    SDL_RenderClear(m_render);

    //draw
    m_player1.render(m_render);
    m_player2.render(m_render);
    m_ball.render(m_render);

    SDL_RenderPresent(m_render);
  }

void Game::close()
  {
     SDL_DestroyRenderer(m_render);
     SDL_DestroyWindow(m_window);

     m_render  = nullptr;
     m_window = nullptr;

     SDL_Quit();
  }
