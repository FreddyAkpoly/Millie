#include <headers/Player.h>


Player::Player(Properties* props): Characters(props){
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID,1, 24, 50, SDL_FLIP_NONE);
}

void Player::Draw(){

    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Player::Update(float dt){
        m_Animation->SetProps("Player_Idle", 1, 18, 50,SDL_FLIP_HORIZONTAL);

        m_RigidBody->UnSetForce();
        if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)){
            m_RigidBody->ApplyForceX(4*BACKWARD);
            m_Animation->SetProps("Player_Run", 1, 24, 50, SDL_FLIP_HORIZONTAL);
        }
        if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)){
            m_RigidBody->ApplyForceX(4*FORWARD);
            m_Animation->SetProps("Player_Run", 1, 24, 50);
        }

        

        m_RigidBody->Update(dt);
      
        m_Transform->TranslateX(m_RigidBody->Position().X);
       // m_Transform->TranslateY(m_RigidBody->Position().Y);

        m_Animation->Update();
}

void Player::Clean(){
    TextureManager::GetInstance()->Clean();
}