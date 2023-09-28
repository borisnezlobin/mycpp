#ifndef LL_CPP
#define LL_CPP

#include "LinkedList.h"
#include "Node.h"
#include "../piecetable/Entry.h"
#include <string>

template <class T>
LinkedList<T>::LinkedList(){
    this->root = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <class T>
Node<T>* LinkedList<T>::add(T value, int index){
    if(index < 0 || index > this->size) return nullptr;

    if(index == 0){
        Node<T>* node = new Node(value);
        node->next = this->root;
        this->root = node;
        this->size++;
        return node;
    }

    int current = 1;
    Node<T>* ptr = this->root;
    while(current != index && ptr->next){
        current++;
        ptr = ptr->next;
    }

    if(current != index) return nullptr;
    Node<T>* temp = ptr->next;
    Node<T>* node = new Node(value);
    ptr->next = node;
    node->next = temp;
    this->size++;
    return node;
}

// honestly idfk if this is good practice
// actually I'm almost entirely certain it isn't
// because `prev` doesn't have to be in the linked list
// so I guess a TODO: is use a bloom filter on the linked list
// haha sike I ain't doin shit with a bloom filter
// actually now I kinda want to make a bloom filter
template <class T>
bool LinkedList<T>::add(Node<T>* newNode, Node<T>* prev){
    if(prev == nullptr){
        newNode->next = this->root;
        this->root = newNode;
        this->size++;
        return true;
    }

    newNode->next = prev->next;
    if(newNode->next == nullptr) this->tail = newNode;
    prev->next = newNode;
    this->size++;
    return true;
}

template <class T>
Node<T>* LinkedList<T>::push(T value){
    this->size++;
    if(this->root == nullptr){
        // so this is actually kinda cool
        // using `Node* newNode = new Node()` instead of just `Node newNode()` makes the memory stay
        // and yeah you have to clear it but that actually makes sense
        // neat
        Node<T>* newNode = new Node(value);
        this->root = newNode;
        this->tail = newNode;
        return this->root;
    }

    Node<T>* newNode = new Node(value);
    this->tail->next = newNode;
    this->tail = newNode;
    return newNode;
}

template <class T>
Node<T>* LinkedList<T>::get(int index){
    if(this->root == nullptr) return nullptr;
    if(this->size <= index || index < 0) return nullptr;

    int i = 0;
    Node<T>* current = this->root;
    while(i != index && current->next){
        i++;
        current = current->next;
    }

    if(i != index) return nullptr;
    return current;
}

template <class T>
bool LinkedList<T>::remove(T value){
    if(this->root == nullptr) return false;

    Node<T>* prev = nullptr;
    Node<T>* current = this->root;
    while(current->value != value){
        prev = current;
        current = current->next;
        if(current == nullptr) return false;
    }

    // we has arriven at an node with value = value
    prev->next = current->next;
    delete current;
    this->size--;
    return true;
}

// does it work? beats me
// won't stop me from using it
template <class T>
bool LinkedList<T>::remove(int index){
    if(this->root == nullptr) return false;
    if(index == 0){
        Node<T>* temp = this->root;
        if(this->root->next) this->root = this->root->next;
        else{
            this->tail = nullptr;
        }
        delete temp;
        this->size--;
        return true;
    }

    Node<T>* current = this->root;
    Node<T>* prev;
    int i = 0;
    while(current->next && i != index){
        i++;
        prev = current;
        current = current->next;
    }
    if(i != index) return false;

    if(current->next){
        prev->next = current->next;
    }else{
        prev->next = nullptr;
        this->tail = prev;
    }
    
    delete current;
    this->size--;
    return true;
}

template <class T>
std::string LinkedList<T>::toString() const {
    if(this->root == nullptr){
        return "Empty linked list.";
    }

    // "ret", as in "the string that I am going to return from this function"
    std::string ret;
    Node<T>* current = this->root;
    while(current != nullptr){
        // couldn't figure it out
        // c++ std (haha) library wins this one
        ret += current->value->toString();
        if(current->next != nullptr) ret += "->\n";
        current = current->next;
    }

    return ret;
}

#endif