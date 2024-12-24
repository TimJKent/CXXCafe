#pragma once
#include <cstddef>
#include <stdexcept>

template<typename T>
class CircularBuffer
{
public:
    CircularBuffer(size_t bufferSize)
    : bufferSize(bufferSize)
    {
        buffer = new T[bufferSize];
    }

    T Next()
    {
        return buffer[head];
    }

    T Pop()
    {
        if(IsEmpty())
        {
            throw std::out_of_range("Circular Buffer Empty");
        }

        T value = buffer[head];
        head = (head + 1) % bufferSize;
        full = false;
        return value;
    }
    
    void Push(const T& value)
    {
        buffer[tail] = value;
        tail = (tail + 1) % bufferSize;
        if(tail == head)
        {
            full = true;
            head = (head + 1) % bufferSize;
        }
    }

    bool IsEmpty()
    {
        return head == tail && !full;
    }

    bool IsFull()
    {
        return full;
    }

private:
    T* buffer;
    size_t bufferSize;
    size_t tail = 0;
    size_t head = 0;
    bool full = false;
};