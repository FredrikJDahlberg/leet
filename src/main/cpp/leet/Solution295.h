//
// Created by Fredrik Dahlberg on 2024-11-18.
//

#ifndef SOLUTION295_H
#define SOLUTION295_H

namespace solution295 {

class MedianFinder
{
private:

    int lo = INT32_MIN;
    int hi = INT32_MAX;
    int count = 0;

public:
    MedianFinder()  = default;

    void addNum(const int num) {
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

    double findMedian() const {
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


