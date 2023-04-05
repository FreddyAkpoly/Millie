#pragma once
#include <string>
#include <sdl/SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.h>
#include <Engine.h>
#include <map>
class TextureManager
{
    public:
        static TextureManager* GetInstance(){return s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureManager();}

        bool Load(std::string id, std::string fileName);
        void Drop(std::string id);
        void Clean();

        void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
    private:
        TextureManager(){};
        std::map<std::string, SDL_Texture*> m_TextureMap;
        static TextureManager* s_Instance;

};