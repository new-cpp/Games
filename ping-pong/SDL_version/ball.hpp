#ifndef BALL_H_
#define BALL_H_

#include "entity.hpp"

struct Ball: public Entity
{
  Ball()=default;
  ~Ball() =default;
  Ball(float x, float y , float w ,float h,Uint32 speed):Entity(x,y,w,h,speed)
  {
    m_direction = {1,0};
  }

  void move( float dt )override;
  bool  collide(const Entity& other);
  bool passed_right()const;
  bool passed_left() const;
  bool hit_wall();
  bool reset_position();
  // void set_direction(Vector2D dir);

};


#endif
