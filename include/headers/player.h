#pragma once
#include <headers/Characters.h>
#include <headers/TextureManager.h>
#include <sdl/SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.h>
#include <Animation.h>
class Player : public Characters
{
    public:
        Player(Properties* props);
        virtual void Draw();
        virtual void Clean();
        virtual void Update(float dt);

    private:
        // int m_row, m_Frame, m_FrameCount;
        // int m_AnimeSpeed;

        Animation* m_Animation;
};