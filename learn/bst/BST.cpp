#include "BST.h"
#include "Node.h"
#include <string>
using namespace std;

BST::BST(){
    this->size = 0;
    this->root = nullptr;
}

Node* BST::add(int value){
    this->size++;
    if(this->root == nullptr){
        Node* newNode = new Node(value);
        this->root = newNode;
        return this->root;
    }

    return this->root->add(value);
}

Node* BST::get(int value){
    if(this->root == nullptr) return nullptr;
    
    return this->root->get(value);
}

bool BST::remove(int value){
    if(this->root == nullptr) return false;
    if(this->size == 1){
        delete this->root;
        this->root = nullptr;
    }
    Node* newRoot = this->root->remove(this->root, nullptr, value);
    if(newRoot != nullptr){
        this->size--;
        this->root = newRoot;
    }
    return newRoot == nullptr;
}

string BST::to_string(){
    string current = "";
    if(this->root != nullptr){
        current = this->root->to_string();
    }
    return "Binary Search Tree with " + std::to_string(this->size) + " node" + (this->size == 1 ? "" : "s") + current;
}