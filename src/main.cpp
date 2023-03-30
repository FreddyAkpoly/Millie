#include <sdl/SDL.h>
#include <headers/Engine.h>
#include <headers/Timer.h>
int main(int argc, char* argv[]){
    Engine::GetInstance()->Init();
   
    while (Engine::GetInstance()->isRunning())
    {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
        Timer::GetInstance()->Tick();

    }

    Engine::GetInstance()->Clean();
    return 0;
}