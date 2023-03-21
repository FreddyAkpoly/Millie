#pragma once
#include <iostream>
#include <sdl/SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.h>
enum class GameState {PLAY,EXIT};
class Game{
    public:
        Game();
        ~Game();
        void run();
    private:
        void init(const char* title, int x, int y, int w, int h, Uint32 flags);
        void gameLoop();
        void handleEvents();
        void draw();
        void update(float deltaTime);
        void render();
        void createRect(int x, int y);
       
        SDL_Window* _window;
        SDL_Renderer* _renderer;

        int _screenWidth;
        int _screenHeight;
        GameState _gameState;

       
};