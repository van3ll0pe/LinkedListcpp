#ifndef LINKEDLISTCPP_HPP
#define LINKEDLISTCPP_HPP



#include <memory>
#include <cstdlib>

template <typename T>
class LinkedList
{
    private:
        struct Node {
            T data;
            Node* next;
        };

        Node* list;
        size_t size;
    
    public:
        LinkedList();
        virtual ~LinkedList();

        bool push_back(T data);
        bool push_top(T data);
        bool push(size_t position, T data);

        bool pop_back();
        bool pop_first();
        bool pop(size_t position);

        T get(size_t position);
        bool set(size_t position, T data);
        size_t lenght();
        void print();
        bool empty();
        bool clear();
        
};

#include "LinkedList.tpp"

#endif