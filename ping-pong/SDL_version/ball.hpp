#ifndef BALL_H_
#define BALL_H_

#include "entity.hpp"

struct Ball: public Entity
{
  Ball()=default;
  ~Ball() =default;
  Ball(float x, float y , float w ,float h,Uint32 speed):Entity(x,y,w,h,speed){}


   void move( float dt )override;

};


#endif
