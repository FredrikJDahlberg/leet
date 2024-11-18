//
// Created by Fredrik Dahlberg on 2024-10-16.
//

#ifndef PRINT_H
#define PRINT_H

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values)
{
    os << "[ ";
    if (!values.empty())
    {
        for (const auto& v: values)
        {
            os << v << " ";
        }
    }
    os << "]";
    return os;
}

template <typename S, typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::pair<S, T>> &values)
{
    os << "[ ";
    if (!values.empty())
    {
        for (const auto& v: values)
        {
            os << "(" << v.first << ", " << v.second << "), ";
        }
    }
    os << "]";
    return os;
}

#endif //PRINT_H
