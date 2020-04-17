#ifndef BASECHARACTER_H
#define BASECHARACTER_H
/*********************************************************************
*	Programmer: Dylan Morgan
*	Last Edit: 04/16/2020
*
*	Description: Used as a base character that can be expanded for
*		player and npc
*********************************************************************/
#include "Stats.h"
#include "GameRenderObject.h"
#include "GraphicsEngine.h"

class BaseCharacter : public GameRenderObject 
{
public:

	Stats* GetStats() { return &mStats; }
	void SetStats(Stats stats) { mStats = stats; }
	std::string GetName() { return mName; }
	uint GetID() { return mID; }

	void SetName(std::string name) { mName = name; }

	BaseCharacter();
	BaseCharacter(std::string name, Stats stats);

	//SFML functions
	void Draw(sf::RenderWindow* renderWindow);
	void SetSpriteIndex(int index);
	void CreateSpriteSheet(GraphicsEngine* gEngine, SpriteSheetData* data, int currentIndex);
	void SetScale(sf::Vector2f scale);

	//Function to handle indvidual update
	void Update();
	void InitText(GraphicsEngine* gEngine, std::string fontKey, int fontSize, sf::Color fontColor);

	
	


private:
	std::string mName;
	static uint mNEXT_ID;
	uint mID;

	Stats mStats;

	//SFML vars
	std::vector<sf::Sprite> mSpriteSheet;
	sf::Sprite* mCurrentSprite;
	sf::Text mNameText;
	

	
};


#endif // !BASECHARACTER_H


