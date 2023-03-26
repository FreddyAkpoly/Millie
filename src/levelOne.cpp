#include <levelOne.h>
#include <iostream>

LevelOne::LevelOne(){


}

void LevelOne::newLevelOne(){
    
    // Associate a texture with the sprite
    m_Texture = IMG_LoadTexture(m_renderer, "sprites\\floor.png");
   
   
    if (!m_Texture)
    {
        std::cout << "Error: Failed to load texture\n";
    }
    m_SpriteRect.x = 0;
    m_SpriteRect.y = 550;

    SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_SpriteRect.w, &m_SpriteRect.h);
}

SDL_Rect LevelOne::getSpriteRect()
{
    return m_SpriteRect;
}

SDL_Texture* LevelOne::getTexture()
{
   return m_Texture;
  
}

void LevelOne::setRenderer(SDL_Renderer* renderer)
{
  m_renderer = renderer; 
  newLevelOne();
}

void LevelOne::update(float elapsedTime)
{
   

}