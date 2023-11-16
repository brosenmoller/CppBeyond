#include <iostream>
#include "Queue.hpp"

int main()
{
    Queue<int> queue = Queue<int>();

    queue.Enqueue(6);
    std::cout << "Enqueued 6" << std::endl;

    std::cout << queue.Peek() << " is at the front of the Queue" << std::endl;

    queue.Enqueue(10);
    std::cout << "Enqueued 10" << std::endl;

    std::cout << queue.Peek() << " is still at the front of the Queue" << std::endl;

    int x = queue.Dequeue();
    std::cout << "Dequeued first queue item into x" << std::endl;

    std::cout << queue.Peek() << " is now at the front of the Queue" << std::endl;
    std::cout << "Variable X contains: " << x << std::endl;
}
