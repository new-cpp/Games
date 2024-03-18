#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "commun.hpp"
struct TextureManager
{
  //SDL_Texture* m_texture{nullptr};
  TextureManager() = default;
  TextureManager(float x , float y, float w, float h):m_rect{x,y,w,h}{}

  SDL_FRect m_rect{};
};

#endif
