// platform game.....
// Author :Ceanford Samsin

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h> 
class Game
{
public:
	//create Window
	sf::RenderWindow window;
	sf::View view;
	float randomNum;

	void processEvents();

	sf::RectangleShape playerShape;

	float velocityX = 0, velocityY = 0, gravity = 0.3;

	bool isSlowed = false;
	sf::Clock slowClock;

	static const int numRows = 15;
	static const int numCols = 20;
	int levelData[numRows][numCols] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,5,0,0,0,0,2,0,0,0,0,4,0,0,0,3},
		{1,1,1,1,1,1,0,0,1,1,1,1,1,6,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};


	sf::RectangleShape level[numRows][numCols];

	Game()
	{

		window.create(sf::VideoMode({ 800, 600 }), "Endless Runner Game");
	}
	void init()
	{
		view = window.getDefaultView();
		playerShape.setSize(sf::Vector2f(20, 20));
		int startRow = 6; // Just above the platform row (row 7)
		int startCol = 3; // 3 tiles from the left
		playerShape.setPosition(sf::Vector2f(startCol * 70, startRow * 30));
		playerShape.setFillColor(sf::Color::White);





		for (int row = 0; row < numRows; row++)
		{
			for (int col = 0; col < numCols; col++)
			{
				level[row][col].setSize(sf::Vector2f(70, 30));
				level[row][col].setPosition(sf::Vector2f(col * 70, row * 30));

				if (levelData[row][col] == 1)
    level[row][col].setFillColor(sf::Color::Red);
else if (levelData[row][col] == 0)
    level[row][col].setFillColor(sf::Color::Black);
else if (levelData[row][col] == 2)
    level[row][col].setFillColor(sf::Color::Blue);
else if (levelData[row][col] == 3)
    level[row][col].setFillColor(sf::Color::Green);
else if (levelData[row][col] == 4)
    level[row][col].setFillColor(sf::Color::Yellow);
else if (levelData[row][col] == 5)
    level[row][col].setFillColor(sf::Color::Magenta); // Bouncy
else if (levelData[row][col] == 6)
    level[row][col].setFillColor(sf::Color::Cyan);    // Slow

			}
		}
	

	}
	void run()
	{


		sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);


		sf::Time timeSinceLastUpdate = sf::Time::Zero;


		sf::Clock clock;

		clock.restart();

		while (window.isOpen())
		{


			// check if the close window button is clicked on. 
			while (const std::optional event = window.pollEvent())
			{
				if (event->is<sf::Event::Closed>())
				{
					window.close();
				}
				else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
				{
					if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
						window.close();
				}
			}

			timeSinceLastUpdate += clock.restart();


			if (timeSinceLastUpdate > timePerFrame)
			{

				for (int row = 0; row < numRows; row++)
				{
					for (int col = 0; col < numCols; col++)
					{

						level[row][col].move(sf::Vector2f(-3.7, 0));
					}

				}


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space) && velocityY == 0)
				{
					velocityY = -11.8;
				}

				velocityY = velocityY + gravity;
				playerShape.move(sf::Vector2f(0, velocityY));


				gravity = 0.6;

				for (int row = 0; row < numRows; row++)
				{
					for (int col = 0; col < numCols; col++)
					{
						if (velocityY >= 0)
						{
							if (levelData[row][col] == 1)
							{

								if (playerShape.getGlobalBounds().findIntersection(level[row][col].getGlobalBounds()))
								{
									if (playerShape.getPosition().y < level[row][col].getPosition().y)
									{
										gravity = 0;
										velocityY = 0;
										playerShape.setPosition(sf::Vector2f(playerShape.getPosition().x, level[row][col].getPosition().y));
										playerShape.move(sf::Vector2f(0, -playerShape.getGlobalBounds().size.y));
										break;
									}
									else {
										init();
									}
								}

							}

						}
						if (velocityY >= 0)
						{
							if (levelData[row][col] == 1 || levelData[row][col] == 5) // platform or bouncy
							{
								if (playerShape.getGlobalBounds().findIntersection(level[row][col].getGlobalBounds()))
								{
									if (playerShape.getPosition().y < level[row][col].getPosition().y)
									{
										gravity = 0;
										if (levelData[row][col] == 5)
										{
											velocityY = -18.0f; // Bouncy jump
										}
										else
										{
											velocityY = 0; // Normal platform
										}
										playerShape.setPosition(sf::Vector2f(playerShape.getPosition().x, level[row][col].getPosition().y));
										playerShape.move(sf::Vector2f(0, -playerShape.getGlobalBounds().size.y));
										break;
									}
									else {
										init();
									}
								}
							}
						}

						if (levelData[row][col] == 2)
						{
							if (playerShape.getGlobalBounds().findIntersection(level[row][col].getGlobalBounds()))
							{
								init();
							}
						}
						if (levelData[row][col] == 5)
						{
							if (playerShape.getGlobalBounds().findIntersection(level[row][col].getGlobalBounds()))
							{
								velocityY = -18.0f; // Stronger jump
							}
						}

						// Slow tile
						if (levelData[row][col] == 6)
						{
							if (playerShape.getGlobalBounds().findIntersection(level[row][col].getGlobalBounds()))
							{
								if (!isSlowed)
								{
									isSlowed = true;
									slowClock.restart();
								}
							}
						}
					}
				}

				if (playerShape.getPosition().y > 600)
				{
					init();
				}

				window.clear();

				for (int row = 0; row < numRows; row++)
				{
					for (int col = 0; col < numCols; col++)
					{
						window.draw(level[row][col]);

					}
				}
				window.draw(playerShape);


				window.display();

				timeSinceLastUpdate = sf::Time::Zero;
			}
		}
	}
};
