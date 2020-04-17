#include "Map.h"

void Map::TestData(sf::RenderWindow* renderWindow)
{
	//std::map<int, std::string>::iterator cursor;

	//

	//std::cout << "KEY\tELEMENT" << std::endl;
	//for (cursor = mTilesetTexturePairs.begin(); cursor != mTilesetTexturePairs.end(); cursor++)
	//{
	//	std::cout << cursor->first << "\t" << cursor->second << "\n" << std::endl;
	//}


}

void Map::Draw(sf::RenderWindow* renderWindow) {
	for (sf::Sprite& s : mTiles)
	{
		renderWindow->draw(s);
	}
}

void Map::LoadTileSetData(std::string fileName, GraphicsEngine* gEngine)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open()) {
		Logger::Log("Could not open file: " + fileName);
	}
	else {
		int numTiles = 0;
		std::string line = "";
		std::getline(inFile, line);
		numTiles = std::stoi(line);

		int it = 1;
		int tileID = -1;
		std::string tileName = "";

		while (std::getline(inFile, line))
		{
			if (it % 2 == 0)
			{
				tileName = line;
				mTilesetTexturePairs.insert(std::pair<int, std::string>(tileID, tileName));
			}
			else {
				tileID = std::stoi(line);
			}

			it++;
		}
		inFile.close();
	}
}

sf::Sprite Map::CreateSprite(GraphicsEngine* gEngine, int tileID, sf::Vector2f pos)
{
	sf::Sprite rtn;
	rtn.setTexture(*gEngine->GetTexture(mTilesetTexturePairs.find(tileID)->second));
	rtn.setPosition(pos);

	return sf::Sprite(rtn);

}

void Map::LoadMap(std::string fileName, GraphicsEngine* gEngine)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open()) {
		Logger::Log("Could not open file: " + fileName);
	}
	else {
		std::string line;

		std::getline(inFile, line);
		mCols = std::stoi(line);

		std::getline(inFile, line);
		mRows = std::stoi(line);

		std::getline(inFile, line);
		mTileSize.x = std::stoi(line);

		std::getline(inFile, line);
		mTileSize.y = std::stoi(line);

		std::getline(inFile, line);

		for (int i = 0; i < mRows; i++)
		{
			std::getline(inFile, line);
			std::istringstream rowLine(line);
			int id = -1;
			for (int j = 0; j < mCols; j++)
			{
				rowLine >> id;
				sf::Sprite t = CreateSprite(gEngine, id, sf::Vector2f(j * mTileSize.x, i * mTileSize.y));
				mTiles.push_back(sf::Sprite(t));
			}
		}
	}

}