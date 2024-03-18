#include "game.hpp"

int main(int argc, char* argv[])
  {

    Game game;
    game.init();
    game.setFPS(60.f);
    game.setLastUpdate( SDL_GetTicks());
    while( game.isRunning() )
      {
        ++game.m_total_frames;
        {
          game.input();

          Uint32 current_time = SDL_GetTicks();
          float dt = (float)(current_time - game.getLastUpdate()) / 1000.0f; //ms

          game.update(dt);
          game.render();

          game.setLastUpdate(current_time);

        /* capping frame rate */
        float elapsedMS = (dt) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(std::floor((1/game.getFPS()) - elapsedMS));

        }

      }
    game.close();
    return 0;
  }
