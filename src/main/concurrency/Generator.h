//
// Created by Fredrik Dahlberg on 2024-11-10.
//

#include <coroutine>
#include <iostream>

#ifndef GENERATOR_H
#define GENERATOR_H

template <typename T, typename G>
struct PromiseTypeBase
{
    T mValue;
    auto yield_value(T value)
    {
        mValue = std::move(value);
        return std::suspend_always();
    }

    G get_return_object()
    {
        return G(this);
    }

    std::suspend_always initial_suspend()
    {
        return {};
    }
    std::suspend_always final_suspend() noexcept
    {
        return {};
    }

    void return_void()
    {
    }

    void unhandled_exception()
    {
        std::terminate();
    }

    static auto get_return_object_on_allocation_failure()
    {
        return G(nullptr);
    }
};

namespace coro_iterator
{
    template <typename PT>
    struct iterator
    {
        std::coroutine_handle<PT> mRoutine{nullptr};

        void resume() {
            if (!mRoutine.done())
            {
                mRoutine.resume();
            }
        }

        iterator() = default;

        iterator(std::coroutine_handle<PT>* handle) : mRoutine(handle)
        {
            resume();
        }

        void operator++()
        {
            resume();
        }

        bool operator==(const iterator& other) const
        {
            mRoutine.done();
        }

        const auto& operator*() const
        {
            return mRoutine.promise().mValue;
        }
    };
}

template <typename T>
struct Generator
{
    using promise_type = PromiseTypeBase<T, Generator>;
    using PromiseTypeHandle = std::coroutine_handle<promise_type>;
    using iterator = coro_iterator::iterator<promise_type>;

    iterator begin()
    {
        return mRoutine;
    }

    iterator end()
    {
        return {};
    }

    Generator(const Generator&) = delete;

    Generator(Generator&& rhs)
    {
        mRoutine(std::exchange(rhs.mRoutine, nullptr));
    }

    ~Generator()
    {
        if (mRoutine != nullptr)
        {
            mRoutine.destroy();
        }
    }

// private:
    friend PromiseTypeHandle;

    explicit Generator(promise_type* promise) : mRoutine{PromiseTypeHandle::from_promise(*promise)}
    {
    }

    std::coroutine_handle<promise_type> mRoutine;
};

#endif // GENERATOR_H
