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
#include <stdlib.h> 
#include <time.h> 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//recreate the game ..
//
//https://abagames.github.io/crisp-game-lib-11-games/?pakupaku
// see blackboard for sample sprites.
// 
int main()
{

	sf::RenderWindow window(sf::VideoMode({ 600, 600 }, 32), "Sprites", sf::Style::Default);


	window.setFramerateLimit(60);
	sf::RectangleShape simpleRectangle;
	float width = 30;
	float height = 30;
	sf::Texture pacman3tex;
	if (!pacman3tex.loadFromFile("resources/images/pacman3.png"))
	{
		// error...
		std::cout << "failed to load sprite";
	}


	sf::Sprite pacmanSprite(pacman3tex);;

	pacmanSprite.setTextureRect(sf::IntRect({ 0,0 }, { 32, 32 }));
	pacmanSprite.setOrigin(sf::Vector2f(0.5, 0.5));
	simpleRectangle.setSize(sf::Vector2f(width, height));

	simpleRectangle.setFillColor(sf::Color::Red);

	simpleRectangle.setPosition(sf::Vector2f(100, 200));

	srand(time(NULL));

	const int numCircles = 10;
	sf::CircleShape circles[numCircles];

	for (int index = 0; index < numCircles; index++)
	{
		circles[index].setFillColor(sf::Color::White);
		circles[index].setRadius(10);
		circles[index].setOrigin(sf::Vector2f(10, 10));
		circles[index].setPosition(sf::Vector2f(40 * index, 200));


	}

	float xPosition = rand() % 800;
	float yPosition = 200;
	float speed = 1;
	bool spacePressed = false;
	int pacmanframesPerSecond = 10;
	int pacmanNumFramesinAnim = 3;
	int pacmanFrame = 0;
	int pacmanFrameCounter = 0;
	int pacmanWidth = 32;
	int pacmanHeight = 32;


	while (window.isOpen())
	{
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





		if (pacmanFrameCounter >= 60 / pacmanframesPerSecond)
		{
			if (pacmanFrame < pacmanNumFramesinAnim - 1)
			{
				pacmanFrame++;
			}
			else {
				pacmanFrame = 0;
			}
			pacmanFrameCounter = 0;
		}
		else {
			pacmanFrameCounter++;
		}

		// Calculate the texture rectangle for the current frame
		int left = pacmanFrame * pacmanWidth;
		int top = 0; // Assuming all frames are in a single row
		pacmanSprite.setTextureRect(sf::IntRect({ left,top }, { pacmanWidth, pacmanHeight }));
		pacmanSprite.setOrigin(sf::Vector2f(16, 16));
		if (speed < 0)
		{
			pacmanSprite.setScale(sf::Vector2f(-1, -1));
		}
		else {
			pacmanSprite.setScale(sf::Vector2f(1, 1));
		}
		if (speed < 0)
		{

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
		{
			if (spacePressed == false)
			{
				speed *= -1;
				spacePressed = true;
			}
		}
		else {
			spacePressed = false;
		}

		xPosition += speed;
		pacmanSprite.setPosition(sf::Vector2f(xPosition, yPosition));
		simpleRectangle.setPosition(sf::Vector2f(xPosition, yPosition));

		for (int index = 0; index < numCircles; index++)
		{
			if (pacmanSprite.getGlobalBounds().findIntersection(circles[index].getGlobalBounds()))
			{
				circles[index].setPosition(sf::Vector2f(1000, 1000));

			}

		}

		sf::Vector2f pos = simpleRectangle.getPosition();

		if (pos.x < -7)
		{
			xPosition = 610;
		}
		else if (pos.x > 610)
		{
			xPosition = -7;
		}


		window.clear();
		for (int index = 0; index < numCircles; index++)
		{

			window.draw(circles[index]);

		}
		//window.draw(simpleRectangle);
		window.draw(pacmanSprite);


		window.display();



	}

	return 0;
}