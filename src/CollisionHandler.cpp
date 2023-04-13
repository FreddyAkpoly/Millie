#include <headers/CollisionHandler.h>
#include <Engine.h>

CollisionHandler* CollisionHandler::s_Instance = nullptr;

CollisionHandler:: CollisionHandler(){
    m_CollisionLayer=(TileLayer*)Engine::GetInstance()->GetMap()->GetMapLayers().front();
    m_CollisionTileMap = m_CollisionLayer->GetTileMap();
}

bool CollisionHandler::CheckCollision(SDL_Rect a, SDL_Rect b){
    
    bool x_overLaps = (a.x <b.x +b.w)&&(a.x + a.w > b.w);
    bool y_overLaps = (a.y <b.y +b.h)&&(a.y + a.h > b.h);
    return (x_overLaps && y_overLaps);
}

bool CollisionHandler::MapCollision(SDL_Rect a){
    int tileSize = 32;
    int RowCount = 20;
    int ColCount = 60;

    int left_tile = a.x/tileSize;
    int right_tile = (a.x + a.w)/tileSize;

    int top_tile = a.y/tileSize;
    int bottom_tile = (a.y + a.h)/tileSize;

    if(left_tile < 0) left_tile = 0;
    if(right_tile > ColCount) right_tile = ColCount;

    if(top_tile < 0) top_tile = 0;
    if(bottom_tile > RowCount) bottom_tile = RowCount;

    for(int i = left_tile; i <= right_tile; i++){
        for(int j = top_tile; j <= bottom_tile; j++){
            if(m_CollisionTileMap[j][i]>0){
                return true;
            }
        }
    }

return false;

}