#include <TileLayer.h>

TileLayer::TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TilesetList tilesets) : m_Tilesets(tilesize)
{
    m_RowCount = rowcount;
    m_ColCount = colcount;
    m_TileMap = tilemap;
    m_Tilesets = tilesets;
}

void TileLayer::Render(){

    for(unsigned int i =0; i < m_RowCount;i++){
        for(unsigned int j = 0; j<m_ColCount;j++){
            
        }
    }

}

void TileLayer::Update(){

}