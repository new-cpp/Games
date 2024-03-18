#ifndef ENTITY_H_
#define ENTITY_H_

#include "texture_management.hpp"

#include <iostream>
#include <tuple>
struct Entity
{

  Entity() = default;
  Entity(float x ,float y,float w ,float h,Uint32 speed) : m_textureManager(x,y,w,h),
                                                          m_velocity(speed){}

  virtual ~Entity() = default;

  enum class Direction
  {
    NONE,
    UP,
    DOWN,
    Right,
    Left
  };


  // services
  void render(SDL_Renderer* t_render)
    {

      SDL_SetRenderDrawColor(t_render, 0,0,0,0xff);
      SDL_RenderFillRectF(t_render, &m_textureManager.m_rect);
    }

  virtual void move( float dt ) = 0;
  bool  collide(const Entity& other)const
    {
      auto [x,y,w,h]=std::make_tuple<int,int,int,int>(get_x(), get_y(),get_w(),get_h());
      auto [ox,oy,ow,oh]=std::make_tuple<int,int,int,int>(other.get_x(),other.get_y(),
                                        other.get_w(),other.get_h());


      //right colliding
            bool right_collide = (ox >= x && (ox-x) <=w);

      //left colliding
     bool left_collide = (x == ox + ow);

     //y in between
     bool same_line = (y>= oy && (y<= oy + oh));

     return same_line && (right_collide || left_collide );
    }

  //getter
  float get_y()const    { return m_textureManager.m_rect.y;}
  float get_h()const    { return m_textureManager.m_rect.h;}

  float get_w()const    { return m_textureManager.m_rect.w;}
  float get_x()const    { return m_textureManager.m_rect.x;}


  void set_direction(Direction direction)
    {
      m_direction = direction;
    }

  TextureManager m_textureManager{};
  Direction m_direction{ Direction::NONE};
  SDL_Point m_previous_position{};
  Uint32 m_velocity{};

};

#endif
