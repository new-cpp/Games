#ifndef PADDLE_H_
#define PADDLE_H_

#include "entity.hpp"

struct Paddle: public Entity
{
  Paddle()=default;
  ~Paddle() = default;
  Paddle(float x, float y , float w ,float h,Uint32 speed):Entity(x,y,w,h,speed)
  {
     m_direction = {0,1};
  }

   void move( float dt) override;
   void score(){ ++m_score;}

  Uint32 m_score{0};

};

#endif
