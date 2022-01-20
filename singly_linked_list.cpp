#include "singly_linked_list.hpp"




template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}


template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}



template <typename T>
void SinglyLinkedList<T>::push_back(T data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}


template <typename T>
void SinglyLinkedList<T>::push_front(T data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    size++;
}


template <typename T>
void SinglyLinkedList<T>::pop_back()
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
        Node* current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    size--;
}


template <typename T>
void SinglyLinkedList<T>::pop_front()
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
        delete temp;
    }
    size--;
}


template <typename T>
void SinglyLinkedList<T>::insert(T data, int index)
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
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;
        Node* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        size++;
    }
}


template <typename T>
void SinglyLinkedList<T>::remove(int index)
{
    if (index < 0 || index >= size)
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
        delete temp;
        size--;
    }
}

template <typename T>
T& SinglyLinkedList<T>::operator[](int index)
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
int SinglyLinkedList<T>::get_size()
{
    return size;
}

template <typename T>
void SinglyLinkedList<T>::print()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
