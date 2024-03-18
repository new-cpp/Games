#include "ball.hpp"

void Ball::move( float dt )
  {
    if(m_direction == Entity::Direction::Right)//right
    {
      this->m_textureManager.m_rect.x += dt*m_velocity;
    }
    else
    {
      this->m_textureManager.m_rect.x  -= dt*m_velocity;
    }
  }
