#include "BST.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    BST tree;
    Node* root = tree.add(1);
    cout << tree.to_string() << endl;
    tree.add(3);
    cout << tree.to_string() << endl;
    tree.add(2);
    tree.add(0);
    tree.add(-1);
    tree.add(4);
    cout << tree.to_string() << endl;

    // test removal of 0 children
    bool removed = tree.remove(2);
    cout << removed << endl;
    cout << tree.to_string() << endl;
    
    // test removal of 1 child
    removed = tree.remove(-1);
    cout << removed << endl;
    cout << tree.to_string() << endl;
    
    // test removal of 2 children
    removed = tree.remove(1);
    cout << removed << endl;
    cout << tree.to_string() << endl;
    return 0;
}