#include "DoublyLinkedListImplement.h"

template <typename T>
void Doubly_LL<T>::push_front(T data) {
    // base cases
    // what if the list is empty, then insert the new node will be the head

    // create a new node
    DoublyNode<T> *newNode = new DoublyNode(data);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->previous = newNode;
        newNode->previous = nullptr;
        head = newNode;
    }
}