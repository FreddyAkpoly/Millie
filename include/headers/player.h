#pragma once
#include <iostream>
#include <sdl/SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.h>


class Player{
private:
    SDL_Point m_Position;
    SDL_Texture* m_Texture;
    SDL_Rect m_SpriteRect;
    bool m_LeftPressed;
    bool m_RightPressed;
    float m_Speed;
    SDL_Renderer* m_renderer;

    
   

public:
    
    Player();
    ~Player();
    void newPlayer();
    SDL_Rect getSpriteRect();
    SDL_Texture* getTexture();
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void update(float elapsedTime);
    void setRenderer(SDL_Renderer* renderer);
    
    
      
};