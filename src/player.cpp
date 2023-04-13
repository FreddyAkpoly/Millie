#include <headers/Player.h>
#include <Camera.h>
#include <headers/CollisionHandler.h>
Player::Player(Properties* props): Characters(props){

    m_JumpTime = JUMP_TIME;
    m_JumpForce = JUMP_FORCE;

    m_Collider = new Collider();
    m_Collider->SetBuffer(0,0,0,0);

    m_RigidBody = new RigidBody();
    m_RigidBody-> SetGravity(3.0f);

    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID,1, 24, 50, SDL_FLIP_NONE);
}

void Player::Draw(){
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);

    Vector2D cam = Camera::GetInstance()->GetPosition();
    SDL_Rect box = m_Collider->Get();
    box.x -= cam.X;
    box.y -= cam.Y;
    SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(),&box);
}

void Player::Update(float dt){
        m_Animation->SetProps("Player_Idle", 1, 18, 50,SDL_FLIP_NONE);

        m_RigidBody->UnSetForce();
        if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)){
            m_RigidBody->ApplyForceX(4*BACKWARD);
            m_Animation->SetProps("Player_Run", 1, 24, 50, SDL_FLIP_HORIZONTAL);
        }
        if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)){
            m_RigidBody->ApplyForceX(4*FORWARD);
            m_Animation->SetProps("Player_Run", 1, 24, 50);
        }

        //jump
        if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W)&& m_IsGrounded){
            m_IsJumping = true;
            m_IsGrounded = false;
            m_RigidBody->ApplyForceY(UPWARD*m_JumpForce);
        }
        if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W)&& m_IsJumping&& m_JumpTime > 0){
            m_JumpTime -= dt;
            m_RigidBody->ApplyForceY(UPWARD*m_JumpForce);
          
        }
        else{
            m_IsJumping = false;
            m_JumpTime = JUMP_TIME;
        }


        m_RigidBody -> Update(dt);
        m_LastSafePosition.X = m_Transform->X;
        m_Transform -> X += m_RigidBody->Position().X;
        m_Collider->Set(m_Transform->X, m_Transform->Y, 96, 96);

        if(CollisionHandler::GetInstance()->MapCollision(m_Collider->Get())){
            m_Transform->X = m_LastSafePosition.X;
        }

        m_RigidBody -> Update(dt);
        m_LastSafePosition.Y = m_Transform->Y;
        m_Transform -> Y += m_RigidBody->Position().Y;
        m_Collider->Set(m_Transform->X, m_Transform->Y, 96, 96);

        if(CollisionHandler::GetInstance()->MapCollision(m_Collider->Get())){
            m_IsGrounded = true;
            m_Transform->Y = m_LastSafePosition.Y;
        }
        else{
            m_IsGrounded = false;
        }

        if(m_IsJumping|| !m_IsGrounded){
                m_Animation->SetProps("Player_Jump", 1, 19, 150);
        }

       // m_RigidBody->Update(dt);
      
       // m_Transform->TranslateX(m_RigidBody->Position().X);
       // m_Transform->TranslateY(m_RigidBody->Position().Y);


        m_Origin -> X = m_Transform -> X+ m_Width/2;
        m_Origin -> Y = m_Transform -> Y+ m_Height/2;
        m_Animation->Update();
}

void Player::Clean(){
    TextureManager::GetInstance()->Drop(m_TextureID);
}