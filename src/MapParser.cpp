#include <MapParser.h>

bool MapParser::Load(){
    return Parse("map1", "assets/map1.tmx");
}

void MapParser::Clean(){
    
}

GameMap* MapParser::GetMaps(){
    
}

bool MapParser::Parse(std::string id, std::string source){
  
}

Tileset MapParser::ParseTileset(TiXmlElement* xmlTileset){
    Tileset tileset;
    tileset.Name = xmlTileset->Attribute("name");
    xmlTileset->Attribute("firstgid", &tileset.FirstID);

    xmlTileset->Attribute("tilecount", &tileset.TileCount);
    tileset.LastID = (tileset.FirstID + tileset.TileCount) - 1;

    xmlTileset->Attribute("columns", &tileset.ColCount);
    tileset.RowCount = tileset.TileCount / tileset.ColCount;
    xmlTileset->Attribute("tilewidth", &tileset.TileSize);

    TiXmlElement* image = xmlTileset->FirstChildElement();
    tileset.Source = image->Attribute("source");
    return tileset;
   
}


TileLayer* MapParser::ParseTileLayer(TiXmlElement* xmlLayer, TilesetList* tilesets,int tileSize, int rowcount, int colcount){
    
}

MapParser::MapParser(){
    
}
