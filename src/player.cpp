#include <headers/Player.h>


Player::Player(Properties* props): Characters(props){
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID,1, 8, 120, SDL_FLIP_HORIZONTAL);
}

void Player::Draw(){

    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Player::Update(float dt){
        m_RigidBody->Update(0);
        m_RigidBody->ApplyForceX(0);
        m_Transform->TranslateX(m_RigidBody->Position().X);
        m_Transform->TranslateY(m_RigidBody->Position().Y);

        m_Animation->Update();
}

void Player::Clean(){
    TextureManager::GetInstance()->Clean();
}