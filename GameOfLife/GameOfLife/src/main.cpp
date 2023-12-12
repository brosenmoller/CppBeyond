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

	auto conwayStrategy = std::vector<Strategy*>{
		new OverpopulationStrategy(3),
		new UnderpopulationStrategy(2),
		new EqualsReproductionStrategy(3)
	};

	auto seedsStrategy = std::vector<Strategy*>{
		new OverpopulationStrategy(-1),
		new EqualsReproductionStrategy(2)
	};

	auto cellularAutomata = std::vector<Strategy*>{
		new CompareReproductionStrategy(4),
		new UnderpopulationStrategy(4)
	};

	Matrix matrix = Matrix(window, cellularAutomata, 2);

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