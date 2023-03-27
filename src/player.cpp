#include <headers/Player.h>


Player::Player(Properties* props): Characters(props){
    m_FrameCount = 1;
    m_row = 1;
    m_AnimeSpeed = 60;
}

void Player::Draw(){
    TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_row, m_Frame);
}

void Player::Update(float dt){
     m_Frame = (SDL_GetTicks() / m_AnimeSpeed) % m_FrameCount;
}

void Player::Clean(){
    TextureManager::GetInstance()->Clean();
}