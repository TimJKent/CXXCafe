#pragma once

template <typename T>
class Node
{
public:
    Node(const T& value)
    : value(value)
    {}

    T value;
    Node<T>* next = nullptr;
};

template<typename T>
class LinkedList
{
public:
    LinkedList(){}

    LinkedList(const T& value)
    : head(new Node(value))
    {
    }
    
    bool IsEmpty()
    {
        return head == nullptr;
    }

    void Push(const T& value)
    {
        if(IsEmpty()){head = new Node<T>(value);}

        Node<T>* previousNode = head;
        Node<T>* currentNode = head;

        while(currentNode != nullptr)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        previousNode->next = new Node<T>(value);
    }

    Node<T>* End()
    {
        Node<T>* currNode = head;
        if(currNode == nullptr)
        {
            return currNode;
        }

        while(currNode->next != nullptr)
        {
            currNode = currNode->next;
        }

        return currNode;
    }

    Node<T>* Begin()
    {
        return head;
    }

    #include <iostream>

    size_t Size()
    {
        if(!head){ return 0; }

        size_t size = 1;

        Node<T>* currNode = head;
        while(currNode->next)
        {
            ++size;
            currNode = currNode->next;
        }
        return size;
    }

    Node<T>* head = nullptr;
};