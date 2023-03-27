#include <headers/Engine.h>
#include <headers/TextureManager.h>

Engine* Engine::s_Instance = nullptr;


bool Engine::Init(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
       SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
       return false;
    }

    m_Window = SDL_CreateWindow("MILLIE ENGINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (m_Window == nullptr){
       SDL_Log("Failed to create window: %s", SDL_GetError());
       return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == nullptr){
       SDL_Log("Failed to create renderer: %s", SDL_GetError());
       return false;
    }

    TextureManager::GetInstance()->Load("player", "sprites/player2.jpg");

    return m_isRunning = true;
  
}

bool Engine::Clean(){

    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
}

void Engine::Quit(){
    m_isRunning = false;
}

void Engine::Update(){
   
}

void Engine::Render(){

SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
SDL_RenderClear(m_Renderer);

TextureManager::GetInstance()->Draw("player", 100, 100, 100, 100);
SDL_RenderPresent(m_Renderer);

}

void Engine::Events(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        Quit();
        break;
    default:
        break;
    }
}