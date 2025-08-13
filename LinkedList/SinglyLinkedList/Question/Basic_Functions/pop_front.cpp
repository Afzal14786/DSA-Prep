#include "LinkedList.h"

template <typename T>

/**
 * @brief pop_front : deleting a node from head and 
 * @return the head's value
 */

T List<T>::pop_front() {
    // first check the base case
    if (isEmpty()) {
        // if the list is empty then return an error
        throw std::runtime_error("Cannot pop from an empty list");
    }

    // create a temp node that hold the head
    Node<T> *curr = head;
    T deletedData = head->data;
    head = head->nextPointer;       // now heads points to the next pointer

    // if the next is null then tail also points to null
    if (head == nullptr) {
        tail = nullptr;
    }

    curr->nextPointer = nullptr;    // break the connection
    
    delete curr;        // avoid memory lead

    return deletedData;
}