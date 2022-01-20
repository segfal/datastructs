#include "doubly_linked_list.hpp"
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::push_back(T data)
{
    Node* new_node = new Node(data);
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::push_front(T data)
{
    Node* new_node = new Node(data);
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
    size++;
}


template <typename T>
void DoublyLinkedList<T>::pop_back()
{
    if (head == nullptr)
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    size--;
}

template <typename T>
void DoublyLinkedList<T>::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    size--;
}

template <typename T>
void DoublyLinkedList<T>::insert(T data, int index)
{
    if (index < 0 || index > size)
    {
        return;
    }
    else if (index == 0)
    {
        push_front(data);
    }
    else if (index == size)
    {
        push_back(data);
    }
    else
    {
        Node* new_node = new Node(data);
        Node* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
        size++;
    }
}


template <typename T>
void DoublyLinkedList<T>::remove(int index)
{
    if (index < 0 || index > size)
    {
        return;
    }
    else if (index == 0)
    {
        pop_front();
    }
    else if (index == size - 1)
    {
        pop_back();
    }
    else
    {
        Node* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        current->next->prev = current;
        delete temp;
        size--;
    }
}


template    <typename T>
T& DoublyLinkedList<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        return head->data;
    }
    else
    {
        Node* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }
}

template <typename T>
int DoublyLinkedList<T>::get_size()
{
    return size;
}

template <typename T>
void DoublyLinkedList<T>::print()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


