#include "LinkedList.h"
#include <iostream>

// genius-level shit right here
using std::cout;
using std::endl;

// `String[] args` was so much simpler I swear
int main(int argv, char** argc){
    LinkedList<int> list;
    cout << list.toString() << endl;
    list.push(1);
    Node<int>* three = list.push(3);
    cout << list.toString() << endl;
    list.add(4, 1);
    cout << list.toString() << endl;
    Node<int>* refToThree = list.get(2);
    
    // realised that assert() in java is something I didn't miss till I lost it
    cout << "does get work: " + std::to_string(three == refToThree) << endl;

    list.remove(3);
    cout << list.toString() << endl;
    bool removed = list.remove(3);
    cout << "removed value 3 from linked list: " + std::to_string(removed) << endl;
    return 0;
}