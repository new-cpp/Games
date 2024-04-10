#ifndef COMMUN_H_
#define COMMUN_H_


#include <SDL2/SDL.h>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

#define LOG_ERROR() perror( SDL_GetError());

//namespace Constants

 constexpr int  SCREEN_HEIGHT {480};
 constexpr int  SCREEN_WIDTH  {620};
 constexpr const char* TITLE       {"ping pong"};
 constexpr int   WINDOW_POSITION {SDL_WINDOWPOS_UNDEFINED};
 constexpr const double PI{ std::acos(-1)};

 constexpr const int  PADDELE_HEIGHT {40};
 constexpr const int  PADDELE_WIDTH {10};
 constexpr const int PADDLE_SPEED  {8000};

 constexpr const int BALL_HEIGHT {10};
 constexpr const int BALL_WIDTH {10};
 constexpr const int BALL_SPEED {150};

#endif // COMMUN_H_
