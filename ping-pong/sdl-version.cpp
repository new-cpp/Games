#include <SDL2/SDL.h>
#include <cstdint>
#include <cstdio>
#include <algorithm>

#define LOG_ERROR() perror( SDL_GetError());


constexpr int  SCREEN_HEIGHT {480};
constexpr int  SCREEN_WIDTH  {720};
constexpr const char* TITLE       {"ping pong"};
constexpr int   WINDOW_POSITION {SDL_WINDOWPOS_UNDEFINED};


struct TextureManager
{
  //SDL_Texture* m_texture{nullptr};
  TextureManager() = default;
  TextureManager(int x , int y, int w, int h):m_rect{x,y,w,h}{}


  SDL_Rect m_rect{};
};

struct Entity
{
  Entity() = default;
  Entity(int x ,int y,int w ,int h) : m_textureManager(x,y,w,h){}
 // void update(int key_pressed){};
  void render(SDL_Renderer*& t_render);
  void move_up();
  void move_down();
  TextureManager m_textureManager{};

  enum class Keys: bool
  {
    UP = 0,
    DOWN = 1
  };
};


void Entity::render(SDL_Renderer*& t_render)
{
  SDL_SetRenderDrawColor(t_render,0,0,0,0xff);
  SDL_RenderFillRect(t_render,&m_textureManager.m_rect);
}

void Entity::move_up()
  {
    std::clamp(m_textureManager.m_rect.y-=4,0,SCREEN_HEIGHT - m_textureManager.m_rect.h);
  }

void Entity::move_down()
  {
    std::clamp(m_textureManager.m_rect.y+=4,0,SCREEN_HEIGHT - m_textureManager.m_rect.h);
  }

struct Game
{

  void init();
  void input();
  void update();
  void render();
  void close();
  bool isRunning(){ return m_running;}

  void collision();

  //rendering attribute
  SDL_Window* m_window{nullptr};
  SDL_Renderer* m_render{nullptr};


  //logical attribute
  bool m_running{true};
  uint32_t m_delta_time{0};

  Entity m_player1{50,SCREEN_HEIGHT/2 - 20,10,40};
  Entity m_player2{SCREEN_WIDTH - 50,SCREEN_HEIGHT/2,10,40};
  Entity m_ball   {SCREEN_WIDTH/2-10,SCREEN_HEIGHT/2, 10,10};
};

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
        else
          {
            if(e.key.keysym.sym == SDLK_UP)
              {
                //move player1
                m_player2.move_up();
              }
            else if(e.key.keysym.sym == SDLK_DOWN)
              {
                m_player2.move_down();
              }
          }
      }
  }


void Game::update()
  {
    //m_player1.update();
    //m_player2.update();
    //m_ball.update();
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

int main(int argc, char* argv[])
  {

    Game game;
    game.init();
    while( game.isRunning() )
      {
        game.input();
        game.update();
        game.render();
      }
    game.close();
    return 0;
  }
