#pragma once
#include <iostream>
#include <sdl/SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.h>
#include <player.h>
#include <levelOne.h>

enum class GameState {PLAY,EXIT};

class Engine
{
private:
    // A regular SDL_Window and SDL_Renderer
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;

    // Declare an SDL_Texture for the background
    SDL_Texture* m_BackgroundTexture;

    // An instance of Bob
    Player m_player;
    LevelOne m_levelOne;

    // Private functions for internal use only
    void input();
    void update(float dtAsSeconds);
    void draw();
    GameState _gameState;

public:
    // The Engine constructor and destructor
    Engine();
    ~Engine();
    // start will call all the private functions
    void start();
    void setRenderer(SDL_Renderer* renderer);
};