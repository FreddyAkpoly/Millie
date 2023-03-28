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

    TextureManager::GetInstance()->Load("player", "sprites/player2.jpg");
    player = new Player(new Properties("player", 100, 200, 136, 96));

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
    if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {SDL_Log("KEY PRESSED");}
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