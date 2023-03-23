#include <headers/game.h>

Game::Game(){
    // Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);
     _gameState = GameState::PLAY;
   
   
    // Get the screen resolution and create an SDL window and renderer
    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    int screenWidth = displayMode.w;
    int screenHeight = displayMode.h;
    m_Window = SDL_CreateWindow("MILLIE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_MAXIMIZED);
    m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
    setRenderer(m_Renderer);
    // Load the background texture
    // Be sure to scale this image to your screen size
    m_BackgroundTexture = IMG_LoadTexture(m_Renderer, "sprites\\background.jpg");

    // Set the texture as the render target
    SDL_SetRenderTarget(m_Renderer, m_BackgroundTexture);

    // Create a rectangle to fill the entire screen
    SDL_Rect screenRect = { 0, 0, screenWidth, screenHeight };

    // Set the renderer color to white and fill the rectangle with it
    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_Renderer, &screenRect);

    // Set the render target back to the window
    SDL_SetRenderTarget(m_Renderer, NULL);
}

Game::~Game(){};

void Game::start()
{
    // Timing
    Uint32 currentTime = SDL_GetTicks();
    Uint32 lastTime = 0;
    float dtAsSeconds = 0.0f;
    while (_gameState != GameState::EXIT)
    {
        // Calculate the delta time
        lastTime = currentTime;
        currentTime = SDL_GetTicks();
        Uint32 deltaTime = currentTime - lastTime;
        dtAsSeconds = (float)deltaTime / 1000.0f;

        input();
        update(dtAsSeconds);
        draw();
    }

}
void Game::input()
{
    SDL_Event event;

    // Handle events on the queue
    while (SDL_PollEvent(&event) != 0)
    {
        // Handle user quitting
        if (event.type == SDL_QUIT)
        {
            _gameState = GameState::EXIT;
        }

        // Handle player moving
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_a:
                    m_player.moveLeft();
                    break;
                case SDLK_d:
                    m_player.moveRight();
                    break;
                default:
                    break;
            }
        }
        else if (event.type == SDL_KEYUP)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_a:
                    m_player.stopLeft();
                    break;
                case SDLK_d:
                    m_player.stopRight();
                    break;
                default:
                    break;
            }
        }
    }
}

void Game::update(float dtAsSeconds)
{

// Update player position based on movement and elapsed time
m_player.update(dtAsSeconds);

}

void Game::draw()
{
    // Rub out the last frame
    SDL_RenderClear(m_Renderer);
 
    // Draw the background
    SDL_RenderCopy(m_Renderer, m_BackgroundTexture, NULL, NULL);
    SDL_Texture* texture = m_player.getTexture();
    SDL_Rect rect = m_player.getSpriteRect();
    SDL_RenderCopy(m_Renderer, texture, NULL, &rect);
 
    // Show everything we have just drawn
    SDL_RenderPresent(m_Renderer);
}

 void Game::setRenderer(SDL_Renderer* renderer){   
     m_player.setRenderer(m_Renderer);
 }