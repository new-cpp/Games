#ifndef PADDLE_H_
#define PADDLE_H_

#include "entity.hpp"

struct Paddle: public Entity
{
  Paddle()=default;
  ~Paddle() = default;
  Paddle(float x, float y , float w ,float h,Uint32 speed):Entity(x,y,w,h,speed){}


   void move( float dt) override;

};

#endif
