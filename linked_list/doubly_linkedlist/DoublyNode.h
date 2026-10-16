#ifndef DOUBLY_NODE_H
#define DOUBLY_NODE_H

template <typename T>
class DoublyNode {
    public:
        DoublyNode *previous;   // points to the previous 
        T data;
        DoublyNode *next;       // pointes to the next 

        DoublyNode (T data) {
            this->data = data;
            this->previous = nullptr;
            this->next = nullptr;
        }
};

#endif