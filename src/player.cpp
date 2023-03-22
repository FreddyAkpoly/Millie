#include "player.h"
#include <iostream>


Player::Player(){};
Player::Player(SDL_Renderer* renderer)
{
    // How fast does Bob move?
    m_Speed = 400;

    // Associate a texture with the sprite
    m_Texture = IMG_LoadTexture(renderer, "sprites\\playerCat.jpg");
    if (!m_Texture)
    {
        std::cout << "Error: Failed to load texture\n";
    }
    m_SpriteRect.x = 500;
    m_SpriteRect.y = 800;
    SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_SpriteRect.w, &m_SpriteRect.h);
}

Player::~Player()
{
    SDL_DestroyTexture(m_Texture);
}

// Make the private sprite available to the draw() function
SDL_Rect Player::getSpriteRect()
{
    return m_SpriteRect;
}

SDL_Texture* Player::getTexture()
{
   return m_Texture;
}

void Player::moveLeft()
{
    m_LeftPressed = true;
}

void Player::moveRight()
{
    m_RightPressed = true;
}

void Player::stopLeft()
{
    m_LeftPressed = false;
}

void Player::stopRight()
{
    m_RightPressed = false;
}

// Move Player based on the input this frame,
// the time elapsed, and the speed
void Player::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        m_SpriteRect.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed)
    {
        m_SpriteRect.x -= m_Speed * elapsedTime;
    }
}

