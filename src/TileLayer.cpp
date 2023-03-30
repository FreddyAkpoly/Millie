#include <TileLayer.h>

TileLayer::TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TilesetList tilesets)
{
    m_TileSize = tilesize;
    m_RowCount = rowcount;
    m_ColCount = colcount;
    m_TileMap = tilemap;
    m_Tilesets = tilesets;
}

void TileLayer::Render(){

}

void TileLayer::Update(){

}
