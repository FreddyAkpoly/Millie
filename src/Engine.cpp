#include <headers/Engine.h>
#include <headers/Timer.h>
#include <headers/MapParser.h>
#include <iostream>
#include <headers/Camera.h>
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

    if(!MapParser::GetInstance()->Load()){
     std::cout <<" error"<< std::endl;
    }

    m_LevelMap = MapParser::GetInstance()->GetMap("MAP");

    TextureManager::GetInstance()->Load("Player_Idle", "sprites/Player_Idle.png");
    TextureManager::GetInstance()->Load("Player_Run", "sprites/Player_Run.png");
    TextureManager::GetInstance()->Load("bg", "sprites/bg.png");

    player = new Player(new Properties("Player_Idle", 100, 200, 80, 80));
    
    Camera::GetInstance()->SetTarget(player->GetOrigin());
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
    float dt = Timer::GetInstance()->GetDeltaTime();
    m_LevelMap->Update();
    player -> Update(dt);
    Camera::GetInstance()->Update(dt);
}

void Engine::Render(){

SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
SDL_RenderClear(m_Renderer);

TextureManager::GetInstance()->Draw("bg", 0, 0, 1024, 600);
m_LevelMap->Render();

player->Draw();
SDL_RenderPresent(m_Renderer);

}

void Engine::Events(){
    Input::GetInstance()->Listen();
   
}