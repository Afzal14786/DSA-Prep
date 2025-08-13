#ifndef NODE_H
#define NODE_H

// we are using templates so out node can use any data types

template <typename T>
class Node {
    public:
        T data;
        Node<T> *nextPointer;
        Node(T data) {
            this->data = data;
            this->nextPointer = nullptr;
        }

        ~Node() {
            // just for testing purpose
            // std::cout << "Node With Data" << data << " Destructor" << std::endl;
        }
};


#endif