#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Strategy.hpp"
#include "Constants.hpp"

class Matrix
{
private:
	sf::RenderWindow* window;
	std::vector<Strategy> strategies;

	int grid[GRID_SIZE][GRID_SIZE];
	sf::CircleShape shapeGrid[GRID_SIZE][GRID_SIZE];

public:
	Matrix(sf::RenderWindow* window);
	~Matrix() = default;

	void Update();
	void Render();

private:
	int GetNeighbourCount(const int x, const int y) const;
};