#include <headers/Engine.h>


Engine* Engine::s_Instance = nullptr;
Player* player = nullptr;

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

    TextureManager::GetInstance()->Load("Player_Idle", "sprites/Player_Idle.png");
    TextureManager::GetInstance()->Load("Player_Run", "sprites/Player_Run.png");

    player = new Player(new Properties("Player_Run", 100, 200, 80, 80));

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
   
    player -> Update(0);
}

void Engine::Render(){

SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
SDL_RenderClear(m_Renderer);

player->Draw();
SDL_RenderPresent(m_Renderer);

}

void Engine::Events(){
    Input::GetInstance()->Listen();
   
}