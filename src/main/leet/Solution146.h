//
// Created by Fredrik Dahlberg on 2024-11-13.
//
#ifndef SOLUTION146_H
#define SOLUTION146_H

namespace Solution146 {
class LRUCache
{
    struct Item
    {
        int key;
        int value;

        Item *prev;
        Item *next;

        Item(const int key, const int value, const int sequence)
        {
            this->key = key;
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    std::unordered_map<int, Item *> cache;
    Item *head;
    Item *tail;

    int count;
    int capacity;

public:
    explicit LRUCache(const int capacity)
    {
        count = 0;
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(const int key)
    {
        if (count == -1)
        {
            return -1;
        }
        const auto entry = cache.find(key);
        const auto result = entry != cache.end() ? entry->second->value : -1;
        std::cout << "get: key = " << key << " val = " << result << std::endl;
        return entry != cache.end() ? entry->second->value : -1;
    }

    void put(int key, const int value)
    {
        std::cout << "put: key = " << key << " val = " << value << std::endl;
        const auto it = cache.find(key);
        Item *item = nullptr;
        if (it != cache.end())
        {
            // found
            item = it->second;
        } else
        {
            // missing
            if (count < capacity)
            {
                ++count;
                item = new Item(key, value, count);
                if (head == nullptr)
                {
                    head = item;
                }
                if (tail == nullptr)
                {
                    tail = item;
                }
                cache.insert(std::pair(key, item));
            } else
            {
                //std::printf("replace: (%d, %d) -> (%d, %d)\n", tail->key, tail->value, key, value);
                cache.erase(tail->key);
                tail->key = key;
                tail->value = value;
                cache.insert(std::pair(key, tail));
                if (tail->prev != nullptr)
                {
                    tail = tail->prev;
                    tail->next = item;
                }
                tail->next = head;
                item = tail;
                head = tail;
            }
        }
        item->next = head;
        head->prev = item;
    }
};
}
#endif //SOLUTION146_H
