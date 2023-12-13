#include <queue>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

int counter = 0;
bool done = false;
std::mutex mutex;
std::condition_variable condition_variable;

std::queue<int> goods;

void producer()
{
    std::cout << "Starting producer..." << std::endl;

    for (int i = 0; i < 500; ++i)
    {
        {
            std::lock_guard<std::mutex> lock(mutex);
            goods.push(i);
            counter++;
        }

        condition_variable.notify_one();
    }

    {
        std::lock_guard<std::mutex> lock(mutex);
        done = true;
    }

    condition_variable.notify_one();

    std::cout << "Finished producer..." << std::endl;
}

void consumer()
{
    std::cout << "Starting consumer..." << std::endl;

    while (true)
    {
        std::unique_lock<std::mutex> lock(mutex);
        condition_variable.wait(lock, [&]() { return done || !goods.empty(); });

        while (!goods.empty())
        {
            goods.pop();
            counter--;
        }

        if (done && goods.empty())
        {
            break;
        }
    }
    
    std::cout << "Finished consumer..." << std::endl;
}

int main()
{
    counter = 0;
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << " " << goods.size() << std::endl;
}
