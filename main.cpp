#include "CXXCafe/Containers/CircularBuffer.h"
#include <iostream>
#include "CXXCafe/Containers/PriorityQueue.h"

int main()
{
    PriorityQueue<int, int> priorityQueue;
    priorityQueue.Push(0, 0);
    priorityQueue.Push(1, 1);
    priorityQueue.Push(2, 2);
    priorityQueue.Push(3, 3);

    while(!priorityQueue.IsEmpty())
    {
        std::cout <<"T: " << priorityQueue.Pop() << std::endl;
    }

    return 0;
}