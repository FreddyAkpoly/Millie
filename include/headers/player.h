#pragma once
#include <headers/Characters.h>
#include <headers/TextureManager.h>
#include <sdl/SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.h>
#include <Animation.h>
#include <RigidBody.h>
#include <Collider.h>

#define JUMP_TIME 15.0f
#define JUMP_FORCE 10.0f

class Player : public Characters
{
    public:
        Player(Properties* props);
        virtual void Draw();
        virtual void Clean();
        virtual void Update(float dt);

    private:

        bool m_IsJumping;
        bool m_IsGrounded;

        float m_JumpTime;
        float m_JumpForce;

        Collider* m_Collider;
        Vector2D m_LastSafePosition;
        Animation* m_Animation;
        RigidBody* m_RigidBody;
};