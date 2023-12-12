#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>
#include <vector>
#include "Constants.hpp"
#include "Matrix.hpp"

int WinMain()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(SCREEN_SIZE, SCREEN_SIZE), "Game Of Life");
	window->setFramerateLimit(FRAME_RATE);

	auto strategies = std::vector<Strategy*>{
		new OverpopulationStrategy(2),
		new UnderpopulationStrategy(),
		new ReproductionStrategy(3)
	};

	Matrix matrix = Matrix(window, strategies);

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

		window->clear();

		matrix.Update();
		matrix.Render();
		
		window->display();
	}

	return 0;
}

#ifdef DEBUG
int main()
{
	return WinMain();
}
#endif