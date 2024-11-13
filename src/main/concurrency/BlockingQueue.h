//
// Created by Fredrik Dahlberg on 2024-10-06.
//

#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include <condition_variable>

template <typename T>
class BlockingQueue
{
private:

    std::queue<T> values;

    std::mutex lock{};
    std::condition_variable notEmpty;
    std::condition_variable notFull;

    const int MAX = 6;

public:

    BlockingQueue() = default;

    const BlockingQueue& push(T& value)
    {
        std::unique_lock uniqueLock(lock);
        notFull.wait(uniqueLock,[this]{ return values.size() < MAX; });
        values.push(value);
        uniqueLock.unlock();
        notEmpty.notify_one();
        return *this;
    }

    T pop()
    {
        std::unique_lock uniqueLock(lock);
        notEmpty.wait(uniqueLock, [this] { return !values.empty(); });
        auto value = values.front();
        values.pop();
        notFull.notify_one();
        return value;
    }

    T peek()
    {
        std::unique_lock uniqueLock(lock);
        notEmpty.wait(uniqueLock, [this] { return !values.empty(); });
        return values.front();
    }

    bool empty()
    {
        std::unique_lock uniqueLock(lock);
        return values.empty();
    }
};

#endif //BLOCKINGQUEUE_H
