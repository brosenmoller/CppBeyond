#pragma once

#include "Constants.hpp"

class Strategy
{
protected:
	int requiredNeighbours;
public:
	Strategy(int requiredNeighbours) : requiredNeighbours(requiredNeighbours) {}

	virtual int operator()(const int currentState, const int neightbourCount) const = 0;
};

class OverpopulationStrategy : public Strategy
{
public:
	OverpopulationStrategy(int requiredNeighbours) : Strategy(requiredNeighbours) {}

	int operator()(const int currentState, const int neightbourCount) const override
	{
		if (currentState == 1)
		{
			if (neightbourCount > requiredNeighbours)
			{
				return 0;
			}
		}
		return currentState;
	}
};

class UnderpopulationStrategy : public Strategy
{
public:
	UnderpopulationStrategy(int requiredNeighbours) : Strategy(requiredNeighbours) {}

	int operator()(const int currentState, const int neightbourCount) const override
	{
		if (currentState == 1)
		{
			if (neightbourCount < requiredNeighbours)
			{
				return 0;
			}
		}
		return currentState;
	}
};

class EqualsReproductionStrategy : public Strategy
{
public:
	EqualsReproductionStrategy(int requiredNeighbours) : Strategy(requiredNeighbours) {}

	int operator()(const int currentState, const int neightbourCount) const override
	{
		if (currentState == 0)
		{
			if (neightbourCount == requiredNeighbours)
			{
				return 1;
			}
		}
		return currentState;
	}
};

class CompareReproductionStrategy : public Strategy
{
public:
	CompareReproductionStrategy(int requiredNeighbours) : Strategy(requiredNeighbours) {}

	int operator()(const int currentState, const int neightbourCount) const override
	{
		if (currentState == 0)
		{
			if (neightbourCount > requiredNeighbours)
			{
				return 1;
			}
		}
		return currentState;
	}
};