#include <headers/Player.h>


Player::Player(Properties* props): Characters(props){
    // m_FrameCount = 1;
    // m_row = 1;
    // m_AnimeSpeed = 60;
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID,1, 6, 80, SDL_FLIP_HORIZONTAL);
}

void Player::Draw(){
    //TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_row, m_Frame);
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Player::Update(float dt){
     //m_Frame = (SDL_GetTicks() / m_AnimeSpeed) % m_FrameCount;
        m_Animation->Update();
}

void Player::Clean(){
    TextureManager::GetInstance()->Clean();
}