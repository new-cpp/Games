#ifndef ENTITY_H_
#define ENTITY_H_

#include "texture_management.hpp"
#include "vector2d.h"
#include <iostream>
#include <tuple>
struct Entity
{

   enum class TYPE:short
  {
    BALL,
    LEFT_PADDELE,
    RIGHT_PADDELE
  }m_type;


  Entity() = default;
  Entity(float x ,float y,float w ,float h,Uint32 speed) : m_textureManager(x,y,w,h),
                                                          m_speed(speed){}

  virtual ~Entity() = default;


  // services
  void render(SDL_Renderer* t_render)
    {

      SDL_SetRenderDrawColor(t_render, 0,0,0,0xff);
      SDL_RenderFillRectF(t_render, &m_textureManager.m_rect);
    }

  virtual void move( float dt ) = 0;

  //getter
  float get_y()const    { return m_textureManager.m_rect.y;}
  float get_h()const    { return m_textureManager.m_rect.h;}

  float get_w()const    { return m_textureManager.m_rect.w;}
  float get_x()const    { return m_textureManager.m_rect.x;}

  float get_speed()const { return m_speed;}
  Vector2D& get_direction() { return m_direction;}
  void  set_direction(const Vector2D& dir)
    {
      m_direction = dir;
    }

  void set_type(const TYPE type)
    {
      m_type = type;
    }

  void set_y(const float& y)
    {
      m_textureManager.m_rect.y = y;
    }

  TextureManager m_textureManager{};
  Vector2D  m_direction{};
  float     m_speed{};


};

#endif
