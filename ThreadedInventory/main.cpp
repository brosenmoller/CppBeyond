#include "Inventory.hpp"
#include <thread>
#include <iostream>

Inventory inventory;
std::vector<int> items1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
std::vector<int> items2{ 11, 12, 13, 14, 15, 16, 17, 18, 19 };
std::vector<int> items3{ 1, 2, 3, 4, 5 };

void ItemAdder(std::vector<int> items, long delay)
{
	for (int i = 0; i < items.size(); i++)
	{
		inventory.Add(items[i]);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));  // Simulate difficult calculation
	}
}

void ItemRemover(std::vector<int> items)
{
	for (int i = 0; i < items.size(); i++)
	{
		inventory.Remove(items[i]);
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Simulate difficult calculation
	}
}


int main()
{
	std::thread adder1Thread(ItemAdder, items1, 2);
	std::thread adder2Thread(ItemAdder, items2, 1);

	std::this_thread::sleep_for(std::chrono::milliseconds(5));

	std::thread remover1Thread(ItemRemover, items3);

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	// Check Current and first item of list to see if this is possible during the other threads runtime
	std::cout << "Current First: " << inventory.Get(0) << std::endl;
	std::cout << "Current Last: " << inventory.GetLast() << std::endl;

	adder1Thread.join();
	adder2Thread.join();
	remover1Thread.join();

	inventory.PrintAllItems();

	return 0;
}