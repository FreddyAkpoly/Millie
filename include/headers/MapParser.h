#pragma once
#include <xml\tinyxml.h>
#include <map>
#include <string>
#include <GameMap.h>
#include <TileLayer.h>


class MapParser
{
    public:
        bool Load();
        void Clean();

        inline GameMap* GetMaps(std::string id){return m_MapDict[id];}
        inline static MapParser* GetInstance(){return s_pInstance = (s_pInstance != 0) ? s_pInstance : new MapParser();}
    private:
        bool Parse(std::string id, std::string source);
        Tileset ParseTileset(TiXmlElement* xmlTileset);
        TileLayer* ParseTileLayer(TiXmlElement* xmlLayer, TilesetList tilesets,int tileSize, int rowcount, int colcount);
    
    private:
        MapParser(){};
        static MapParser* s_pInstance;
        std::map<std::string, GameMap*> m_MapDict;
};