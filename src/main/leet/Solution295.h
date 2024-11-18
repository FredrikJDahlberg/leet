//
// Created by Fredrik Dahlberg on 2024-11-18.
//

#ifndef SOLUTION295_H
#define SOLUTION295_H
#include <limits>

namespace solution295 {

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder
{
private:

    int lo = INT32_MIN;
    int hi = INT32_MAX;
    int count = 0;

public:
    MedianFinder()  = default;

    void addNum(int num) {
        ++count;
        if (count == 1)
        {
            lo = num;
            hi = num;
        }
        else
        {
            if (num > lo && num < hi)
            {
                lo = num;
            }
            if (hi < num && num > lo)
            {
                hi = num;
            }
        }
    }

    double findMedian() {
        if (count == 0)
        {
            return 0.0;
        }
        if (count == 1)
        {
            return lo;
        }
        return (hi + lo) / 2.0;
    }
};

}

#endif //SOLUTION295_H


