#pragma once

#include <list>

template<typename T>
class Queue
{
public:
	Queue() = default;
	~Queue() = default;

	void Enqueue(T item)
	{
		items.push_front(item);
	}
	
	T Dequeue()
	{
		T back = items.back();
		items.pop_back();
		return back;
	}

	T Peek()
	{
		return items.back();
	}

	int Size()
	{
		return items.size();
	}

private:
	std::list<T> items;
};