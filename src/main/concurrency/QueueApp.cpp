//
// Created by Fredrik Dahlberg on 2024-10-06.
//
#include <iostream>
#include <thread>

#include "BlockingQueue.h"


int main(int argc, char *argv[])
{
    BlockingQueue<int> queue;

    std::thread thread1([&] {
        int value = 0;
        while (++value <= 10)
        {
            std::cout << "push = " << value << std::endl;
            queue.push(value);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "produce done\n";
    });

    std::thread thread2([&] {
        int value = 0;
        while (value < 10)
        {
            if (!queue.empty())
            {
                value = queue.pop();
                std::cout << "pop = " <<  value << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "consume done\n";
    });

    thread1.join();
    thread2.join();
}
