#include "paddle.hpp"
#include "algorithm"
void Paddle::move(float dt)
  {
          m_textureManager.m_rect.x += dt*m_speed*m_direction.x;
          m_textureManager.m_rect.y += dt*m_speed*m_direction.y;
  }
