#pragma once

#include "Constants.hpp"

class Strategy
{
public:
	virtual int operator()(const int currentState, const int neightbourCount) const = 0;
};

class OverpopulationStrategy : public Strategy
{
public:
	int operator()(const int currentState, const int neightbourCount) const override
	{
		if (currentState == 1)
		{
			if (neightbourCount > 3)
			{
				return 0;
			}
		}
		return currentState;
	}
};

class UnderpopulationStrategy : public Strategy
{
	int operator()(const int currentState, const int neightbourCount) const override
	{
		if (currentState == 1)
		{
			if (neightbourCount < 2)
			{
				return 0;
			}
		}
		return currentState;
	}
};

class ReproductionStrategy : public Strategy
{
public:
	int operator()(const int currentState, const int neightbourCount) const override
	{
		if (currentState == 0)
		{
			if (neightbourCount == 3)
			{
				return 1;
			}
		}
		return currentState;
	}
};