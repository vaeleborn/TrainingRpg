#include "BaseCharacter.h"
#include <vector>

int WINX = 500;
int WINY = 500;

//Function to test sfml graphics
void GraphicsTest();

//Function used in DisplayTest to output data to console
void DisplayStats(BaseCharacter* character);

//Test function to make sure character variables are working correctly
void DisplayTest();

int main()
{
	//DisplayTest();

	GraphicsTest();
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
	DisplayStats(&testChar);	


	//Region tests functions
	testChar.SetName("Seph");
	testChar.GetStats()->AddHealth(200);
	testChar.GetStats()->AddStrength(20);
	DisplayStats(&testChar);

	//Region tests custom constructor
	BaseCharacter testCharTwo("Sapphire", Stats(125, 15));
	DisplayStats(&testCharTwo);

	//Region tests id iterator
	for (int i = 0; i < 1000; i++)
	{
		BaseCharacter c;
	}
	DisplayStats(&BaseCharacter());
}

void GraphicsTest() 
{
	sf::RenderWindow window(sf::VideoMode(WINX, WINY), "Window Title!");
	sf::CircleShape circle(100.f);
	circle.setFillColor(sf::Color::Blue);

	sf::Texture bgTexture;
	sf::Texture testSheet;

	if (!bgTexture.loadFromFile("Textures/Wood_Texture.png"))
	{
		std::cout << "Error!";
	}

	if (!testSheet.loadFromFile("Textures/Soldier.png"))
	{
		std::cout << "Error!";
	}



	std::vector<sf::Sprite> bgMap;
	for (int i = 0; i < static_cast<int>((WINX / bgTexture.getSize().x)); i++)
	{
		sf::Sprite temp(bgTexture);
		int x = 32 * i;
		int y = 0;
		for (int j = 0; j <static_cast<int>( (WINY / bgTexture.getSize().y)); j++)
		{
			y = j * 32;
			temp.setPosition(x, y);
			bgMap.push_back(sf::Sprite(temp));
		}
	}

	sf::Sprite charSprite;
	charSprite.setTexture(testSheet);
	charSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	charSprite.setPosition((WINX / 2) - 16, (WINY / 2) - 16);


	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed || ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}

		window.clear(sf::Color::White);
		for (auto &sprite : bgMap)
		{
			window.draw(sprite);
		}
		window.draw(charSprite);
		window.display();
	}
}