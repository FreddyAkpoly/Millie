#include <sdl/SDL.h>
#include <headers/Engine.h>

int main(int argc, char* argv[]){
    Engine::GetInstance()->Init();
   
    while (Engine::GetInstance()->isRunning())
    {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
    }

    Engine::GetInstance()->Clean();
    return 0;
}