#include "Matrix.hpp"

Matrix::Matrix(sf::RenderWindow* window, std::vector<Strategy*> &strategies) : window(window), strategies(strategies)
{
	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			int random = std::rand() % RANDOM;

			if (random == 1) { grid[x][y] = 1; }
			else { grid[x][y] = 0; }

			sf::CircleShape shape = sf::CircleShape((SCREEN_SIZE / GRID_SIZE) / 2);
			shape.setFillColor(OBJECT_COLOR);
			shape.setPosition(sf::Vector2f(x * (SCREEN_SIZE / GRID_SIZE), y * (SCREEN_SIZE / GRID_SIZE)));

			shapeGrid[x][y] = shape;
		}
	}
}

void Matrix::Update()
{
	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			int neightbourCount = GetNeighbourCount(x, y);

			for (int i = 0; i < strategies.size(); i++)
			{
				grid[x][y] = strategies[i]->operator()(grid[x][y], neightbourCount);
			}
		}
	}
}

void Matrix::Render()
{
	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			if (grid[x][y] == 1)
			{
				window->draw(shapeGrid[x][y]);
			}
		}
	}
}

int Matrix::GetNeighbourCount(const int x, const int y) const
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
}
