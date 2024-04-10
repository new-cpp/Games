#include "ball.hpp"
#include <iostream>
#include <cmath>
void Ball::move( float dt )
  {

      this->m_textureManager.m_rect.x +=  dt * m_speed* m_direction.x;
      this->m_textureManager.m_rect.y +=  dt * m_speed* m_direction.y;

  }

 bool Ball:: collide(const Entity& other)
    {
      auto [x,y,w,h]=    this->m_textureManager.m_rect;
      auto [ox,oy,ow,oh]= other.m_textureManager.m_rect;


      //right colliding
      bool right_collide =  (other.m_type == Entity::TYPE::RIGHT_PADDELE)&&(ox <= (w+x));

     //left colliding
     bool left_collide = (other.m_type == Entity::TYPE::LEFT_PADDELE)&&(x <= ox + ow);

     //y in between
     bool same_line = ( y>=oy-h && (y<= oy + oh));

     bool is_collided =  same_line && (right_collide || left_collide );


     if(right_collide && same_line)// controle for player 1
       {
         // get the collision point beteween [-paddle_height/2 ,paddle_height/2]
         auto collision_y =((oy+oh/2.0f) - (y+h/2.0f));

         //normilzed between[-1,1]
         auto n_collision_y = collision_y/(oh/2);

         //angle between [-MAX_ANgle,MAX_AGNEL]
         constexpr float MAX_ANGLE = PI/4;
         auto angle = n_collision_y * MAX_ANGLE;

         // new position after collision
         double old_sign = m_direction.x / std::abs(m_direction.x);

         m_direction.x = std::abs(std::cos(angle)) * (-old_sign);
         m_direction.y = -std::sin(angle);

       }
     else if(left_collide && same_line) // for ai
       {
         m_direction.x *= -1; // just reflect
       }

     return is_collided;
    }


bool Ball::passed_left()const
  {
    auto x = get_x();
    auto w = get_w();
    return x + w<=0.f;
  }

bool Ball::passed_right()const
  {
    auto x = get_x();
    return x>= static_cast<float>(SCREEN_WIDTH);
  }

bool Ball::hit_wall()
  {
    auto y = get_y();
    auto h = get_h();
    auto res = (y<=0 || (y + h) >= SCREEN_HEIGHT);

    if(res)
      {
        auto y = get_y();
        auto h = get_h();
        y = SCREEN_HEIGHT - h;

        m_direction.y *=-1;

      }

    return res;
  }

bool Ball::reset_position()
  {
    m_textureManager.m_rect.x = (SCREEN_WIDTH - BALL_WIDTH)/2;
    m_textureManager.m_rect.y = (SCREEN_HEIGHT - BALL_HEIGHT)/2;

    return true; //TODO :change this
  }
