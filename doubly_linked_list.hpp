#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

template <typename T>
class DoublyLinkedList
{
    private:
        struct Node
        {
            T data;
            Node* next;
            Node* prev;
            Node(int a) : data(a), next(nullptr), prev(nullptr) {}
        };
        Node* head;
        Node* tail;
        int size;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
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


#include "doubly_linked_list.cpp"



#endif