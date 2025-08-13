#include "DoublyLinkedListImplement.h"

/**
 * @brief This version insert a new data into the list from back
 */

template <typename T>
void Doubly_LL<T>::push_back(T data) {
    // now check the base case
    // if list is empty then new node will be the head

    DoublyNode<T> *newNode = new DoublyNode(data);

    if (isEmpty()) {
        head = tail = newNode;
    }

    newNode->previous = tail;
    tail->next = newNode;
    newNode->next = nullptr;
    tail = newNode;
}