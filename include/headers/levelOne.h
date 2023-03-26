#pragma once
#include <iostream>
#include <sdl/SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.h>


class LevelOne{
private:

    SDL_Point m_Position;
    SDL_Texture* m_Texture;
    SDL_Rect m_SpriteRect;
    SDL_Renderer* m_renderer;

public:
    
    LevelOne();
    
    SDL_Rect getSpriteRect();
    SDL_Texture* getTexture();
    void setRenderer(SDL_Renderer* renderer);
    void newLevelOne();
    void update(float elapsedTime);
    
};