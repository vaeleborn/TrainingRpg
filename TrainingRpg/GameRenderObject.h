#pragma once
#include "Globals.h"
#include "GraphicsEngine.h"

/*********************************************************************
*	Programmer: Dylan Morgan
*	Last Edit: 04/16/2020
*
*	Description: Base class for all renderable game objects
*********************************************************************/

class GameRenderObject
{
public:
	virtual void Draw(sf::RenderWindow* renderWindow);

protected:
	
private:
};

