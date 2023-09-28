#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int val){
    value = val;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int val, Node* left, Node* right){
    value = val;
    this->left = left;
    this->right = right;
}

Node* Node::add(int newVal){
    if(this->value < newVal){
        // add to the right
        if(this->right != nullptr){
            return this->right->add(newVal);
        }else{
            Node* newNode = new Node(newVal, nullptr, nullptr);
            this->right = newNode;
            return this->right;
        }
    }else if(this->value > newVal){
        // add to the left
        if(this->left != nullptr){
            return this->left->add(newVal);
        }else{
            Node* newNode = new Node(newVal, nullptr, nullptr);
            this->left = newNode;
            return this->left;
        }
    }
    
    return nullptr;
}

Node* Node::get(int value){
    if(this->value == value) return this;
    if(this->value > value) return (this->right == nullptr ? nullptr : this->right->get(value));
    if(this->value < value) return (this->left == nullptr ? nullptr : this->left->get(value));

    return nullptr;
}

string Node::to_string(){
    string current = "";
    if(this->left != nullptr){
        current += this->left->to_string();
    }
    current += " (" + std::to_string(value) + ")";
    if(this->right != nullptr){
        current += this->right->to_string();
    }
    if(this->right == nullptr && this->left == nullptr) current += "*";
    return current;
}

// maybe not that bad of a lanuage
Node** whichChild(Node* parent, int val){
    return val > parent->value ? &(parent->right) : &(parent->left);
}


// how TF do you remove a node from a binary search tree
// self-balancing trees must be so complicated
// although tbf you could just not have a remove method
Node* Node::remove(Node* root, Node* parent, int val){
    // I really don't know how pointer lifetimes work
    // does c++ even have gc
    // shit, it doesn't have garbage collection
    // well I guess it does have a garbage compiler
    // what an absolute clown language

    // (3 days later) I've learned how pointer lifetimes work
    // what an absolute clown language
    if(this->value == val){
        if(!this->right && !this->left){ // 0 children
            // took me so long to
            //      1. figure out how to remove nodes from a bst
            //      2. figure out how to write the remove method
            //      3. C++ reflections (**)
            Node** ptr = whichChild(parent, val);
            *ptr = nullptr;
            delete this;
            return root;
        }

        if(this->right && !this->left){ // 1 children
            Node** ptr = whichChild(parent, val);
            *ptr = this->right;
            delete this;
            return root;
        }

        if(this->left && !this->right){ // 1 child
            Node** ptr = whichChild(parent, val);
            *ptr = this->left;
            delete this;
            return root;
        }
        // 1.64 children

        // 2 children
        Node* temp = this->left;
        Node* tempParent = this;

        while(temp->right != nullptr){
            tempParent = temp;
            temp = temp->right;
        }

        tempParent->right = nullptr;
        if(temp != this->left) temp->left = this->left;
        temp->right = this->right;

        // whole thing breks if it's root
        // idk why
        // problem for some other time
        if(this == root){
            delete this;
            return temp;
        }

        delete this;
        return root;
    }

    if(this->value > val){
        if(this->left != nullptr) return this->left->remove(root, this, val);
    }else{
        if(this->right != nullptr) return this->right->remove(root, this, val);
    }

    return nullptr;
}