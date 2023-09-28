#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;


class Node {
    public:
        int value;
        Node* left;
        Node* right;
        Node(int value);
        Node(int value, Node* left, Node* right);
        string to_string();
        Node* add(int value);
        Node* get(int value);
        Node* remove(Node* root, Node* parent, int value);
};

#endif