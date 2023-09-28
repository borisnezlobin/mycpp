#ifndef NODE_LL
#define NODE_LL

template <typename T>
class Node {
    public:
        Node(T value){
            this->value = value;
            this->next = nullptr;
        }
        T value;
        Node<T>* next;
};

#endif