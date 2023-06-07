#include "LinkedList.hpp"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList(): list(nullptr), size(0)
{}

template <typename T>
LinkedList<T>::~LinkedList()
{
    if (list == nullptr) return;

    Node* tmp = list;

    while(tmp != nullptr)
    {
        tmp = tmp->next;
        delete list;
        list = tmp;
    }
}

template <typename T>
bool
LinkedList<T>::push_back(T data)
{
    Node* element { new Node{.data = data, .next = nullptr} };
    if (element == nullptr)
        return false;

    size++;

    if (list == nullptr) {
        list = element;
        return true;
    }

    Node* tmp = list;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = element;
    return true;
}

template<typename T>
bool
LinkedList<T>::push_top(T data)
{
    Node* element { new Node{.data = data, .next = list}};
    if (element == nullptr)
        return false;

    size++;

    list = element;
    return true;
}

template <typename T>
bool
LinkedList<T>::pop_back()
{    
    if (size == 0)
        return false;

    if (size == 1) {
        delete list;
        list = nullptr;
    } else {
        Node* tmp = list;
        Node* tmp2 = list;
        while (tmp->next != nullptr) {
            tmp2 = tmp;
            tmp = tmp->next;
        }   
        delete tmp;
        tmp2->next = nullptr;
    }
    
    size--;
    return true;
}

template <typename T>
bool
LinkedList<T>::pop_first()
{
    if (size == 0)
        return false;
    
    Node* tmp = list->next; //it can be nullptr or memory address
    delete list;
    list = tmp;
    size--;
    return true;
}

template <typename T>
void
LinkedList<T>::print()
{
    Node* tmp = list;

    while (tmp != nullptr)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

template <typename T>
T
LinkedList<T>::get(size_t position)
{
    if (position < 0 || position >= size)
        exit(EXIT_FAILURE);

    size_t i = 0;
    Node* tmp = list;

    while (i < position)
    {
        tmp = tmp->next;
        i++;
    }

    return tmp->data;
}

template <typename T>
size_t
LinkedList<T>::lenght()
{
    return size;
}

template <typename T>
bool
LinkedList<T>::push(size_t position, T data)
{
    if (position < 0 || position > size)
        return false;

    Node* element = new Node{.data = data, .next = nullptr};
    if (element == nullptr)
        return false;

    size++;


    if (list == nullptr) { //if no element
        list = element;
    }
    else if (position == 0 && list != nullptr) { //if already element in the list but position 0
        element->next = list;
        list = element;
    }
    else if (position != 0 && list != nullptr) {
        size_t i = 0;
        Node* tmp = list;
        Node* tmp2 = list;

        while (i < position)
        {
            tmp2 = tmp;
            tmp = tmp->next;
            i++;
        }
        element->next = tmp;
        tmp2->next = element;
    }
    
    return true;
}

template <typename T>
bool
LinkedList<T>::pop(size_t position)
{
    if (size == 0)
        return false;

    if (position < 0 || position >= size)
        return false;

    if (position == 0) {
        Node* tmp = list->next;
        delete list;
        list = tmp;
    } else {
        size_t i = 0;
        Node* tmp = list;
        Node* tmp2 = list;

        while (i < position)
        {
            tmp2 = tmp;
            tmp = tmp->next;
            i++;
        }

        tmp2->next = tmp->next;
        delete tmp;
    }

    size--;
    return true;
}

template <typename T>
bool
LinkedList<T>::set(size_t position, T data)
{
    if (size == 0)
        return false;
    
    if (position < 0 || position >= size)
        return false;
    
    Node* tmp = list;
    size_t i = 0;
    while (i < position) {
        tmp = tmp->next;
        i++;
    }

    tmp->data = data;
    return true;
}

template <typename T>
bool
LinkedList<T>::empty()
{
    if (size == 0)
        return true;
    
    return false;
}

template <typename T>
bool
LinkedList<T>::clear()
{
    if (size == 0)
        return false;
    
    Node* tmp = list;

    while (tmp != nullptr) {
        list = tmp;
        tmp = tmp->next;
        delete list;
    }

    list = nullptr;
    size = 0;
    return true;
}
