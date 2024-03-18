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

}

void Game::input()
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
                m_player2.set_direction(Entity::Direction::UP);
              }
            else if(e.key.keysym.sym == SDLK_DOWN)
              {
                m_player2.set_direction(Entity::Direction::DOWN);
              }

          }
      }
  }



void Game::update( float dt)
  {


    if(m_ball.collide(m_player2))
      {
        m_ball.set_direction(Entity::Direction::Left);
      }
    if(m_ball.collide(m_player1))
       {
          m_ball.set_direction(Entity::Direction::Right);
       }
    //m_ball.collide(wall);


    m_ball.move(dt);
    m_player2.move(dt);
    m_player1.move(dt);
    m_player2.set_direction(Entity::Direction::NONE);

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
