#include <iostream>
#include "Queue.hpp"

template<typename T>
void SortArray(T array[], int length)
{
    for (int i = 0; i < length - 1; ++i)
    {
        for (int j = i + 1; j < length; ++j)
        {
            if (array[i] > array[j])
            {
                T item;
                item = array[i];
                array[i] = array[j];
                array[j] = item;
            }
        }
    }
}

template <typename T>
void PrintArray(const T array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void QueueTest()
{
    std::cout << "Queue Test:" << std::endl << "------------------" << std::endl;

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

void ArraySortTest()
{
    std::cout << "Array Sort Test:" << std::endl << "------------------" << std::endl;

    int intArray[] = { 5, 2, 8, 1, 3 };
    int intArraySize = sizeof(intArray) / sizeof(int);
    std::cout << "Unsorted Int Array: " << std::endl;
    PrintArray(intArray, intArraySize);

    std::cout << "Sorted Int Array: " << std::endl;
    SortArray(intArray, intArraySize);
    PrintArray(intArray, intArraySize);

    std::cout << std::endl;

    std::string stringArray[] = { "orange", "banana", "grape", "apple", "kiwi" };
    int stringArraySize = sizeof(stringArray) / sizeof(std::string);
    std::cout << "Unsorted String Array: " << std::endl;
    PrintArray(stringArray, stringArraySize);

    std::cout << "Sorted String Array: " << std::endl;
    SortArray(stringArray, stringArraySize);
    PrintArray(stringArray, stringArraySize);
}


int main()
{
    QueueTest();
    
    std::cout << std::endl << std::endl;

    ArraySortTest();
}
