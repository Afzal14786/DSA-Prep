#include "LinkedList.h"

/**
 * @brief Pushing data from tail in the list
 * @param T can be any data type : Integer, String etc..
 */
template <typename T>
void List<T>::push_back(T data) {
    Node<T> *newNode = new Node<T>(data);

    // if list is empty then both can point in the same newNode
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->nextPointer = newNode;
        tail = newNode;
    }
}