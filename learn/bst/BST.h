#ifndef BST_H
#define BST_H
#include "Node.h"
#include <string>
using namespace std;

class BST {
    public:
        Node* root;
        Node* add(int value);
        Node* get(int value);
        bool remove(int value);
        string to_string();
        BST();

    private:
        int size;
};

#endif