#include "paddle.hpp"
#include "algorithm"
void Paddle::move(float dt)
  {

    switch(m_direction)
      {
        //move up
        case Entity::Direction::UP:
          m_textureManager.m_rect.y -= dt*m_velocity;
        //m_textureManager.m_rect.y = (float)std::clamp(static_cast<int>(m_textureManager.m_rect.y),0,SCREEN_HEIGHT);
          break;
        //move down
        case Entity::Direction::DOWN:
        m_textureManager.m_rect.y +=  dt*m_velocity;
        //m_textureManager.m_rect.y = (float)std::clamp(static_cast<int>(m_textureManager.m_rect.y),0,SCREEN_HEIGHT - (int)m_textureManager.m_rect.h);
        break;
      }
  }
