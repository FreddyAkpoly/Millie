#include <headers/TextureManager.h>
#include <headers/Camera.h>
TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string fileName)
{
   SDL_Surface* surface = IMG_Load(fileName.c_str());
    if (surface == nullptr){
        SDL_Log("Failed to load image: %s, %s", fileName.c_str(), SDL_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
    if (texture == nullptr){
        SDL_Log("Failed to create texture: %s", SDL_GetError());
        return false;
    }

    m_TextureMap[id] = texture;

    return true;
}

void TextureManager::DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {tileSize * row , tileSize * (frame), tileSize, tileSize};
    Vector2D cam = Camera::GetInstance()->GetPosition();
    SDL_Rect destRect = {x - static_cast<int>(cam.X),y- static_cast<int>(cam.Y), tileSize, tileSize};
   
    
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[tilesetID], &srcRect, &destRect, 0, 0, flip);
}




void TextureManager::Drop(std::string id)
{
   SDL_DestroyTexture(m_TextureMap[id]);
   m_TextureMap.erase(id);
}

void TextureManager::Clean()
{
   std::map<std::string, SDL_Texture*>::iterator it;
    for (it = m_TextureMap.begin(); it != m_TextureMap.end(); it++){
         SDL_DestroyTexture(it->second);
    }
    m_TextureMap.clear();

    SDL_Log("Texture Manager Cleaned");
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    Vector2D cam = Camera::GetInstance()->GetPosition()*0.5;
    SDL_Rect destRect = {x - static_cast<int>(cam.X),y- static_cast<int>(cam.Y),  width, height};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {width * frame, height * (row-1), width, height};
    Vector2D cam = Camera::GetInstance()->GetPosition();
    SDL_Rect destRect = {x - static_cast<int>(cam.X),y- static_cast<int>(cam.Y),  width, height};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}