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

	auto conwayStrategy = std::vector<Strategy*>{
		new OverpopulationStrategy(3),
		new UnderpopulationStrategy(2),
		new EqualsReproductionStrategy(3)
	};

	auto seedsStrategy = std::vector<Strategy*>{
		new OverpopulationStrategy(-1),
		new EqualsReproductionStrategy(2)
	};

	auto generationStrategy = std::vector<Strategy*>{
		new CompareReproductionStrategy(4),
		new UnderpopulationStrategy(4)
	};

	int chosenNumber;
	std::cout << "What do you want to run: " << std::endl;
	std::cout << "1: Conway, 2: Seeds, 3: Generation" << std::endl;
	std::cin >> chosenNumber;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(SCREEN_SIZE, SCREEN_SIZE), "Game Of Life");
	window->setFramerateLimit(FRAME_RATE);

	Matrix* matrix;
	if (chosenNumber == 1)
	{
		matrix = new Matrix(window, conwayStrategy, 5);
	}
	else if (chosenNumber == 2)
	{
		matrix = new Matrix(window, seedsStrategy, 5);
	}
	else
	{
		matrix = new Matrix(window, generationStrategy, 2);
	}

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

		matrix->Update();
		matrix->Render();
		
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