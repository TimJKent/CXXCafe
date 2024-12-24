#pragma once
#include <CXXCafe/Containers/LinkedList.h>
#include <iostream>
#include <stdexcept>

template <typename T1, typename T2>
class PriorityQueueNode
{
public:
    PriorityQueueNode(const T1& value, const T2& priority)
    : value(value)
    , priority(priority)
    {}

    T1 value;
    T2 priority;
};

template <typename T1, typename T2>
class PriorityQueue
{
public:
    PriorityQueue(){}
    void Push(const T1& value, const T2& priority)
    {
        if(linkedList.IsEmpty())
        { 
            linkedList.head = new Node(PriorityQueueNode<T1, T2>(value, priority)); 
            return;
        }

        Node<PriorityQueueNode<T1,T2>>* prevNode = linkedList.Begin();
        Node<PriorityQueueNode<T1,T2>>* lastNode = linkedList.Begin();

        Node<PriorityQueueNode<T1, T2>>* newNode = new Node<PriorityQueueNode<T1, T2>>(PriorityQueueNode<T1, T2>(value, priority));

        while(lastNode->next != nullptr)
        {
            
            if(lastNode->value.priority <= priority)
            {
                if(lastNode == linkedList.Begin())
                {
                    newNode->next = linkedList.head->next;
                    linkedList.head = newNode;
                }
                return;
            }
            prevNode = lastNode;
            lastNode = lastNode->next;
        }
   
        lastNode->next = newNode;
    }

    T1 First()
    {
        if(!linkedList.Begin())
        {
            throw std::out_of_range();
        }
        return linkedList.Begin()->value.value;
    }

    T1 Pop()
    {
        if(!linkedList.Begin())
        {
            throw std::runtime_error("Priority Queue Empty!");
        }

        Node<PriorityQueueNode<T1, T2>>* begin = linkedList.Begin();

        if(begin->next)
        {
            linkedList.head = begin->next;
        }else
        {
            linkedList.head = nullptr;
        }


        T1 output = begin->value.value;
        delete begin;

        return output;
    }

    bool IsEmpty()
    {
        return linkedList.IsEmpty();
    }

    size_t Size()
    {
        return linkedList.Size();
    }

public: 
    LinkedList<PriorityQueueNode<T1, T2>> linkedList;
};