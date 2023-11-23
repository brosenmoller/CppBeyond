#include <iostream>
#include <SFML/Graphics.hpp>

int WinMain()
{
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(500, 600), "Game Of Life");
	window->setFramerateLimit(60);

	bool isRunning = true;

	while (isRunning)
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
	}

	return 0;
}

#ifdef DEBUG
int main()
{
	return WinMain();
}
#endif