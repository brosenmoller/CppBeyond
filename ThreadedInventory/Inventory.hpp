#pragma once

#include <vector>
#include <mutex>

class Inventory
{
private:
	std::vector<int> items;
	std::mutex mutex;

public:
	Inventory() = default;
	~Inventory() = default;

	void Add(int item);
	void Remove(int item);
	int Get(int index);
	int GetLast();

	void PrintAllItems();
};