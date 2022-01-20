#ifndef singly_linked_list_hpp
#define singly_linked_list_hpp


#include <iostream>

template <typename T>
class SinglyLinkedList
{
    private:
        struct Node
        {
            T data;
            Node* next;
        };
        Node* head;
        Node* tail;
        int size;
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();
        void push_back(T data);
        void push_front(T data);
        void pop_back();
        void pop_front();
        void insert(T data, int index);
        void remove(int index);
        T& operator[](int index);
        int get_size();
        void print();
};


#include "singly_linked_list.cpp"

#endif