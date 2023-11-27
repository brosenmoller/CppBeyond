#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>
#include <vector>

const int GRID_SIZE = 50;
const int SCREEN_SIZE = 1000;
const int FRAME_RATE = 10;


int WinMain()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	auto window = std::make_unique<sf::RenderWindow>(sf::VideoMode(SCREEN_SIZE, SCREEN_SIZE), "Game Of Life");
	window->setFramerateLimit(FRAME_RATE);

	bool isRunning = true;

	int grid[GRID_SIZE][GRID_SIZE]{};

	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			int random = std::rand() % 5;

			if (random == 1)
			{
				grid[x][y] = 1;
			}
		}
	}

	//sf::CircleShape shape(5);
	//shape.setFillColor(sf::Color(150, 50, 250));

	sf::CircleShape shapeGrid[GRID_SIZE][GRID_SIZE];

	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			sf::CircleShape shape = sf::CircleShape((SCREEN_SIZE / GRID_SIZE) / 2);
			shape.setFillColor(sf::Color(150, 50, 250));
			shape.setPosition(sf::Vector2f(x * (SCREEN_SIZE / GRID_SIZE), y * (SCREEN_SIZE / GRID_SIZE)));

			shapeGrid[x][y] = shape;
		}
	}

	auto GetNeighbourCount = [&grid](int x, int y) -> int
	{
		int count = 0;

		for (int diffX = -1; diffX <= 1; diffX++)
		{
			for (int diffY = -1; diffY <= 1; diffY++)
			{
				if (diffX == 0 && diffY == 0) { continue; }

				if (grid[x + diffX][y + diffY] == 1)
				{
					count++;
				}
			}
		}

		return count;
	};


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

		
		for (int x = 0; x < GRID_SIZE; x++)
		{
			for (int y = 0; y < GRID_SIZE; y++)
			{
				int count = GetNeighbourCount(x, y);

				if (grid[x][y] == 1)
				{
					if (count < 2 || count > 3)
					{
						grid[x][y] = 0;
					}
				}
				else
				{
					if (count == 3)
					{
						grid[x][y] = 1;
					}
				}

				if (grid[x][y] == 1)
				{
					window->draw(shapeGrid[x][y]);
				}
			}
		}
		
		
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