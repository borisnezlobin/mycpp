#ifndef LL_H
#define LL_H

#include "Node.h"
#include <string>

template <class T>
class LinkedList {
    private:
        Node<T>* root;
        Node<T>* tail;
        int size;

    public:
        LinkedList();
        Node<T>* add(T value, int index);
        bool add(Node<T>* newNode, Node<T>* prev);
        Node<T>* push(T value);
        Node<T>* get(int value);
        bool remove(T value);
        bool remove(int index);
        std::string toString() const;
        int getSize(){ return this->size; }
};

#include "LinkedList.tpp"

#endif