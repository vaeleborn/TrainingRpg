#include "GraphicsEngine.h"

void GraphicsEngine::AddTexture(std::string fPath, std::string key)
{
	sf::Texture temp;
	if (!temp.loadFromFile(fPath))
	{
		std::cout << "Error";
		return;
	}
	mTextureMap.insert(std::make_pair(key, sf::Texture(temp)));
}

void GraphicsEngine::AddTexture(std::string fPath, std::string key, sf::IntRect intRect)
{
	sf::Texture temp;
	if (!temp.loadFromFile(fPath, intRect))
	{
		std::cout << "Error";
		return;
	}
	mTextureMap.insert(std::make_pair(key, sf::Texture(temp)));
}

sf::Texture* GraphicsEngine::GetTexture(std::string key)
{
	if (mTextureMap.find(key) != mTextureMap.end())
	{
		return &mTextureMap.find(key)->second;
	}
	else
	{
		return nullptr;
	}
}

std::vector<sf::Sprite> GraphicsEngine::GetSpriteSheet(std::string key)
{
	if (mSpriteSheets.find(key) != mSpriteSheets.end())
	{
		return mSpriteSheets.find(key)->second;
	}
	else
	{
		std::vector<sf::Sprite> t;
		return t;
	}
}

void GraphicsEngine::AddSpriteSheet(std::string key, std::vector<sf::Sprite> sprites)
{
	mSpriteSheets.insert(std::make_pair(key, sprites));
}

std::vector<sf::Sprite> GraphicsEngine::CreateAndAddSpriteSheet(SpriteSheetData* data)
{
	std::vector<sf::Sprite> sprites;
	sf::Texture* texture;
	texture = GetTexture(data->textureKey);
	int numSprites = data->texturePositions.size();

	if (texture != nullptr)
	{
		for (int i = 0; i < numSprites; i++)
		{
			sf::Sprite temp(*texture, sf::IntRect(data->texturePositions[i], data->spriteSizes[i]));
			temp.setPosition(data->spritePositions[i].x, data->spritePositions[i].y);
			sprites.push_back(sf::Sprite(temp));
		}
		AddSpriteSheet(data->spriteKey, sprites);
	}
	else
	{
		std::cout << "Error";
	}
	return sprites;

}

sf::Font* GraphicsEngine::GetFont(std::string key)
{
	if (mFonts.find(key) != mFonts.end())
	{
		return &mFonts.find(key)->second;
	}
	else
	{
		return nullptr;
	}

}

void GraphicsEngine::AddFont(std::string fPath, std::string key)
{
	sf::Font tempFont;
	if (!tempFont.loadFromFile(fPath))
	{
		std::cout << "Error";
		return;
	}
	else
	{
		mFonts.insert(std::make_pair(key, sf::Font(tempFont)));
	}
}

