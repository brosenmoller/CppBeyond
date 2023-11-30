#include "Matrix.hpp"

Matrix::Matrix(sf::RenderWindow* window) : window(window)
{
	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			int random = std::rand() % 5;

			if (random == 1) { grid[x][y] = 1; }
			else { grid[x][y] = 0; }
		}
	}

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


}

void Matrix::Update()
{
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
