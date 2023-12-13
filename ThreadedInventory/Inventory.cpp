#include "Inventory.hpp"
#include <iostream>

void Inventory::Add(int item)
{
	std::lock_guard<std::mutex> lock(mutex);
	items.push_back(item);
}

void Inventory::Remove(int item)
{
	std::lock_guard<std::mutex> lock(mutex);
	items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

int Inventory::Get(int index)
{
	std::lock_guard<std::mutex> lock(mutex);

	if (index >= items.size()) { return 0; }

	return items[index];
}

int Inventory::GetLast()
{
	std::lock_guard<std::mutex> lock(mutex);

	if (items.empty()) { return 0; }

	return items[items.size() - 1];
}

void Inventory::PrintAllItems()
{
	std::cout << std::endl;
	std::cout << "Inventory: " << std::endl;

	for (int i = 0; i < items.size(); i++)
	{
		std::cout << items[i] << std::endl;
	}
}


