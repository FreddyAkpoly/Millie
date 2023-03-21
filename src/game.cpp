#include <headers/game.h>

Game::Game(){
    _window = nullptr;
    _renderer = nullptr;
    _screenWidth  = 1024;
    _screenHeight = 600;
    _gameState = GameState::PLAY;

   
 
};
Game::~Game(){};

void Game ::run(){
    init("Millie",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_screenWidth, _screenHeight,SDL_WINDOW_SHOWN);
    gameLoop();
}

void Game :: init(const char* title, int x, int y, int w, int h, Uint32 flags){
    SDL_Init(SDL_INIT_EVERYTHING);

    _window = SDL_CreateWindow(title,x,y,w,h,flags);
    _renderer = SDL_CreateRenderer(_window,-1,0);

}

void Game::gameLoop(){
    const float FRAME_TIME = 1.0f / 60.0f;
    Uint32 previousTime = SDL_GetTicks();
    float lag = 0.0f;

    while(_gameState != GameState::EXIT){
        Uint32 currentTime = SDL_GetTicks();
        float elapsed = (currentTime - previousTime) / 1000.0f;
        previousTime = currentTime;
        lag += elapsed;

        handleEvents();

        while (lag >= FRAME_TIME){
            update(FRAME_TIME);
            lag -= FRAME_TIME;
        }

        render();

        Uint32 frameTime = SDL_GetTicks() - currentTime;

        if (frameTime < FRAME_TIME * 1000.0f){
            SDL_Delay((Uint32)((FRAME_TIME * 1000.0f) - frameTime));
        }
    }
}


void Game:: handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            _gameState = GameState::EXIT;
            break;
        case SDL_MOUSEBUTTONDOWN:
            createRect(event.button.x, event.button.y);
            break;
    }
}

void Game::draw(){
  // SDL_RenderClear(_renderer);
   SDL_RenderPresent(_renderer);
}


void Game::createRect(int x, int y) {
    int r = rand() % 255, g = rand() % 255, b = rand() % 255;
    SDL_SetRenderDrawColor(_renderer, r, g, b, 255);
    SDL_Rect rect = {x, y, 50, 50};
    SDL_RenderFillRect(_renderer, &rect);
    printf("Rect(x=%d, y=%d, w=%d, h=%d)\n", rect.x, rect.y, rect.w, rect.h);
    draw();
}

void Game:: update(float deltaTime){

}

void Game::render(){
   
}