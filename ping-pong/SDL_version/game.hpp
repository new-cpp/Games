#ifndef GAME_H_
#define GAME_H_

#include "commun.hpp"
#include "ball.hpp"
#include "paddle.hpp"

struct Game
{

  void init();
  void input(float dt);
  void update(float dt);
  void render();
  void close();
  bool isRunning(){ return m_running;}


// frame rate and ,dt management
  void setFPS(Uint32 fps)
    {
      m_fps = fps;
    }

  float getFPS()
    {
      return m_fps;
    }

  Uint32 getLastUpdate()
    {
      return m_lastUpdate;
    }
  void   setLastUpdate(Uint32 time)
    {
      m_lastUpdate = time;
    }



  //rendering attribute
  SDL_Window* m_window{nullptr};
  SDL_Renderer* m_render{nullptr};

  // game logic attribute
  bool m_running{true};
  uint32_t m_total_frames{0};
  Uint32   m_lastUpdate{};
  float    m_fps{};

  Paddle m_player1{50,(SCREEN_HEIGHT - PADDELE_HEIGHT)/2, PADDELE_WIDTH,PADDELE_HEIGHT,PADDLE_SPEED};
  Paddle m_player2{SCREEN_WIDTH - 50,(SCREEN_HEIGHT - PADDELE_HEIGHT)/2,PADDELE_WIDTH,PADDELE_HEIGHT,PADDLE_SPEED};
  Ball m_ball   {(SCREEN_WIDTH - BALL_WIDTH)/2,(SCREEN_HEIGHT - BALL_HEIGHT)/2, BALL_WIDTH,BALL_HEIGHT,BALL_SPEED};
};


#endif
