#include "BaseCharacter.h"

uint BaseCharacter::mNEXT_ID = 0;

BaseCharacter::BaseCharacter()
{
	mName = "Placeholder Name";
	mID = mNEXT_ID;
	mNEXT_ID++;
}

BaseCharacter::BaseCharacter(std::string name, Stats stats) : mName(name), mStats(&stats)
{
	mID = mNEXT_ID;
	mNEXT_ID++;
}

void BaseCharacter::Draw(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(*mCurrentSprite);
	renderWindow->draw(mNameText);
}

void BaseCharacter::CreateSpriteSheet(GraphicsEngine* gEngine, SpriteSheetData* data, int currentIndex)
{

	mSpriteSheet = gEngine->CreateAndAddSpriteSheet(data);
	mCurrentSprite = &mSpriteSheet[currentIndex];
}

void BaseCharacter::SetSpriteIndex(int index)
{
	mCurrentSprite = &mSpriteSheet[index];
}

void BaseCharacter::Update()
{
	sf::Vector2f position = mCurrentSprite->getPosition();
	mNameText.setPosition(position.x + mCurrentSprite->getGlobalBounds().width / 3, position.y - 6 - mNameText.getGlobalBounds().height);
}

void BaseCharacter::SetScale(sf::Vector2f scale)
{
	for (sf::Sprite& sprite : mSpriteSheet)
	{
		float height = sprite.getGlobalBounds().height;
		float width = sprite.getGlobalBounds().width;
		sprite.setScale(scale);
		sf::Vector2f curPos = sprite.getPosition();
		sf::Vector2f adjPos;
		adjPos.x = curPos.x - scale.x * width;
		adjPos.y = curPos.y - scale.y * height;
		sprite.setPosition(adjPos);
	}
}

void BaseCharacter::InitText(GraphicsEngine* gEngine, std::string fontKey, int fontSize, sf::Color fontColor)
{
	mNameText.setFont(*gEngine->GetFont(fontKey));
	mNameText.setString(mName);
	mNameText.setFillColor(fontColor);
	mNameText.setCharacterSize(fontSize);
}

