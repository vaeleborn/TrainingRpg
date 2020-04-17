#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H
/*******************************************************************************
*	Programmer: Dylan Morgan
*	Last Edit: 04/05/2020
*
*	PURPOSE: This class will hold the majority of graphical functions and 
*		base variables, such as storing all the needed textures and groups of 
*		sprites
********************************************************************************/

#include "Globals.h"

/*	Structure that holds all the needed data for a sprite sheet */
struct SpriteSheetData
{
	std::string spriteKey;
	std::string textureKey;
	std::vector<sf::Vector2i> texturePositions;
	std::vector<sf::Vector2i> spriteSizes;
	std::vector<sf::Vector2i> spritePositions;

	SpriteSheetData() {};
	SpriteSheetData(std::string sKey, std::string tKey, std::vector<sf::Vector2i> tPos, std::vector<sf::Vector2i> sSize,
		std::vector<sf::Vector2i> sPos) : spriteKey(sKey), textureKey(tKey), texturePositions(tPos), spriteSizes(sSize), 
											spritePositions(sPos){};

	SpriteSheetData* GetThis() { return this; }
};

/*Grpahics engine class, will hold all textures, fonts, spritesheets, etc */
class GraphicsEngine
{
public:
	//Function that will attempt to load a texture and add it to the available textures
	void AddTexture(std::string fPath, std::string key);
	void AddTexture(std::string fPath, std::string key, sf::IntRect intRect);

	//Function that will return a pointer to a specific texture identified by a key string 
	sf::Texture* GetTexture(std::string key);

	sf::Font* GetFont(std::string key);
	void AddFont(std::string fPath, std::string key);

	void AddSpriteSheet(std::string key, std::vector<sf::Sprite> sprites);

	std::vector<sf::Sprite> GetSpriteSheet(std::string key);

	std::vector<sf::Sprite> CreateAndAddSpriteSheet(SpriteSheetData* data);



private:
	std::map<std::string, sf::Texture> mTextureMap;
	std::map<std::string, std::vector<sf::Sprite>> mSpriteSheets;
	std::map<std::string, sf::Font> mFonts;
};

//Make a struct for a background fill sprite
struct SingleTextureTileMap
{
	std::vector<sf::Sprite> map;

	SingleTextureTileMap(GraphicsEngine* gEngine, std::string textureKey, sf::Vector2i windowSize)
	{
		sf::Vector2u textureSize = gEngine->GetTexture(textureKey)->getSize();

		for (int i = 0; i < static_cast<int>(windowSize.x / textureSize.x); i++)
		{
			sf::Sprite tempSprite(*gEngine->GetTexture(textureKey));
			sf::Vector2i position;
			position.x = textureSize.x * i;
			position.y = 0;

			for (int j = 0; j < static_cast<int>(windowSize.y / textureSize.y); j++)
			{
				position.y = textureSize.y * j;
				tempSprite.setPosition(position.x, position.y);
				map.push_back(sf::Sprite(tempSprite));
			}
		}
	}

	void Draw(sf::RenderWindow* rWindow)
	{
		for (sf::Sprite& sprite : map) {
			rWindow->draw(sprite);
		}
	}
};

#endif

