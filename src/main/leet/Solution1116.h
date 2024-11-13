//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION1116_H
#define SOLUTION1116_H

class ZeroEvenOdd
{
private:
    int max;
    int value;
    int state = 0;

    std::mutex lock;

public:
    explicit ZeroEvenOdd(const int n) : max(n), value(0)
    {
    }

    void zero(std::function<void(int)>&& printNumber) {
        for (int index = 0; index < max; )
        {
            lock.lock();
            if (state == 0)
            {
                printNumber(0);
                index = ++value;
                state = index % 2 + 1;
            }
            lock.unlock();
        }
    }

    void odd(std::function<void(int)>&& printNumber) {
        for (int index = 0; index < max; )
        {
            lock.lock();
            if (state == 2)
            {
                printNumber(value);
                state = 0;
            }
            index = value;
            lock.unlock();
        }
    }

    void even(std::function<void(int)>&& printNumber) {
        for (int index = 0; index < max; )
        {
            lock.lock();
            if (state == 1)
            {
                printNumber(value);
                state = 0;
            }
            index = value;
            lock.unlock();
        }
    }
};

#endif //SOLUTION1116_H
