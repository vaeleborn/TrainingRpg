#ifndef MAP_H
#define MAP_H

/*********************************************************************
*	Programmer: Dylan Morgan
*	Last Edit: 04/16/2020
*
*	Description: Contains the Map class, a map is made up of
*		multiple sprites with various textures that can then
*		be drawn to a render window
*********************************************************************/

#include "GameRenderObject.h"
#include "Logger.h"

class Map : GameRenderObject
{
public:
	/* Function that will load information about a tileset such as the number and what
	 Tile that number represents, ie 0 - sky */
	void LoadTileSetData(std::string fileName, GraphicsEngine* gEngine);

	//Function that will load map data from a file and fill the tiles vector
	void LoadMap(std::string fileName, GraphicsEngine* gEngine);

	//Function that will draw the map to a render window
	void Draw(sf::RenderWindow* renderWindow);
private:
	//Variable that holds all the individual tile sprites that make up the map
	std::vector<sf::Sprite> mTiles;

	//Variable that holds the tileset data for which number represents which tile
	std::map<int, std::string> mTilesetTexturePairs;

	//Variables that hold dimensional data for the map
	int mRows;
	int mCols;
	sf::Vector2f mTileSize;

	//Function will create a sprite given a tileid and a position
	sf::Sprite CreateSprite(GraphicsEngine* gEngine, int tileID, sf::Vector2f pos);

};

#endif