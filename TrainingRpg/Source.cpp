#include "BaseCharacter.h"
#include <vector>
#include "GraphicsEngine.h"
#include "Logger.h"
#include "Map.h"

const int WINX = 1200;
const int WINY = 600;
const float FRAMERATE = 9;

// 38 x 19

//Function to test sfml graphics
void GraphicsTest();

//Function used in DisplayTest to output data to console
void DisplayStats(BaseCharacter* character);

//Test function to make sure character variables are working correctly
void DisplayTest();

void MakeTestSpriteData(SpriteSheetData& data);

int main()
{
	srand(time(NULL)); //random seed
	//DisplayTest();

	GraphicsTest();

	//TileMap testMap;
	//testMap.LoadTileSetData("TestTileSetData.txt");
	//testMap.TestData();

	system("pause");
	return 0;
}

void DisplayStats(BaseCharacter* character)
{
	std::cout << "Name: " << character->GetName() << "\nID: " << character->GetID() <<
		"\nHealth: " << character->GetStats()->GetHealth() << "\nStrength: " 
		<< character->GetStats()->GetStrength() << "\n\n";

}

void DisplayTest()
{
	//Region tests default Constructor
	BaseCharacter testChar;

	//Region tests functions
	testChar.SetName("Seph");
	testChar.SetStats(Stats::RandomInitialStats());
	DisplayStats(&testChar);

	//Region tests custom constructor
	BaseCharacter testCharTwo("Sapphire", Stats(90, 15));
	DisplayStats(&testCharTwo);

	//Region tests id iterator
	for (int i = 0; i < 6; i++)
	{
		BaseCharacter c;
		c.SetStats(Stats::RandomInitialStats());
		DisplayStats(&c);
	}
	DisplayStats(&BaseCharacter());
}

void GraphicsTest() 
{
	sf::RenderWindow window(sf::VideoMode(WINX, WINY), "Window Title!");

#pragma region Graphics Engine Startup
	//Instantiate the graphics engine and load in needed textures here
	GraphicsEngine gEngine;
	gEngine.AddTexture("Textures/Wood_Texture.png", "Platform");
	gEngine.AddTexture("Textures/CarpetTexture.png", "Sky");
	gEngine.AddTexture("Textures/Basic_Stone.png", "Underground", sf::IntRect(0, 32, 32, 32));
	gEngine.AddTexture("Textures/Basic_Stone.png", "Ground", sf::IntRect(32, 0, 32, 32));
	gEngine.AddTexture("Textures/Soldier.png", "Soldier Texture");
	gEngine.AddTexture("Textures/Platformer_With_Weapon.png", "Platformer");

	
	//Test loading font
	gEngine.AddFont("Fonts/Plain Germanica.ttf", "Germanica");
	gEngine.AddFont("Fonts/font2.ttf", "Primary");


#pragma endregion

	//Testing the background struct
	SingleTextureTileMap backgroundTest(&gEngine, "Ground", sf::Vector2i(WINX, WINY));

	Map backgroundTileTest;
	backgroundTileTest.LoadTileSetData("TestTileSetData.txt", &gEngine);
	backgroundTileTest.LoadMap("FullMap01.txt", &gEngine);

	//Making a simple character
	BaseCharacter character;
	character.SetName("Caius");
	character.SetStats(Stats::RandomInitialStats());
	character.InitText(&gEngine, "Primary", 20, sf::Color::White);
	


	//Data for the characters sprite sheet
	SpriteSheetData testData;

	//Populates the data for the sprite sheet see function definition to change and test data differently
	MakeTestSpriteData(testData);

	//Give our character a spritesheet that we just got data for then set the current sprite to the 0 index
	character.CreateSpriteSheet(&gEngine, SpriteSheetData(testData).GetThis(), 0);

	character.SetScale(sf::Vector2f(5.f, 5.f));

	//Test text
	sf::Text testText;
	testText.setFont(*gEngine.GetFont("Germanica"));
	testText.setString("Welcome to the game!");
	testText.setCharacterSize(24); //in pixels
	testText.setFillColor(sf::Color::White);
	testText.setStyle(sf::Text::Bold);
	
	testText.setPosition((WINX / 2) - testText.getGlobalBounds().width / 2, 50);

	int testIndex = 0;
	bool changeAnimationFrame = false;

	window.setFramerateLimit(FRAMERATE);
	//Main game loop
	while (window.isOpen())
	{
		//Primary event
		sf::Event ev;

		//Event Loop
		while (window.pollEvent(ev))
		{
			//Conditions to close game
			if (ev.type == sf::Event::Closed || ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			{
				window.close();
			} 
			//Key Press Events
			else if (ev.type == sf::Event::KeyPressed)
			{
				switch (ev.key.code)
				{
					//Set our characters sprite index to 0 when 'w' is pressed
					case sf::Keyboard::W:
						character.SetSpriteIndex(0);
						break;
					//Set our characters sprite index to 2 when 's' is pressed
					case sf::Keyboard::S:
						character.SetSpriteIndex(7);
						break;
					case sf::Keyboard::D:
						if (!changeAnimationFrame)
							changeAnimationFrame = true;
						break;
				default:
					break;
				}
			}
			//Key Release Events
			else if (ev.type == sf::Event::KeyReleased)
			{
				switch (ev.key.code)
				{
				case sf::Keyboard::D:
					if (changeAnimationFrame)
						changeAnimationFrame = false;
					break;
				default:
					break;
				}
			}
		}

		//HANDLE UPDATES HERE
		if (changeAnimationFrame)
		{
			if (testIndex < 7)
				testIndex = testIndex + 1;
			else
				testIndex = 0;

			character.SetSpriteIndex(testIndex);
		}

		character.Update();

		//Clears the window to white
		window.clear(sf::Color(165, 150, 103));

		//Loop through the sprites that make up the background and draw them to the buffer
		/*for (auto &sprite : bgMap)
		{
			window.draw(sprite);
		}*/
		//backgroundTest.Draw(&window);
		backgroundTileTest.Draw(&window);
		//Draw our character to the buffer
		character.Draw(&window);

		//Draw some text
		window.draw(testText);

		//Display the buffer to the window
		window.display();
	}
}

void MakeTestSpriteData(SpriteSheetData& data)
{
	//Variables that will be used for the spritesheet
	std::vector<sf::Vector2i> charPositions;
	std::vector<sf::Vector2i> sizes;
	std::vector<sf::Vector2i> sPos;

	//Loops 3times to make data from a texture with 3 columns, j used as number of sprites in sheet
	for (int i = 0, j = 0; i < 3; i++)
	{
		//Loops through the rows
		for (int k = 0; k < 3 && j < 8; k++)
		{
			charPositions.push_back(sf::Vector2i(32 * k, 32 * i));
			sizes.push_back(sf::Vector2i(32, 32));
			sPos.push_back(sf::Vector2i((WINX / 2) - 16, (WINY) - 32));
			j++;
		}
		
	}

	//assigns the data the values obtained prior
	data.spriteKey = "Platformer Sprite";
	data.textureKey = "Platformer";
	data.texturePositions = charPositions;
	data.spriteSizes = sizes;
	data.spritePositions = sPos;

}