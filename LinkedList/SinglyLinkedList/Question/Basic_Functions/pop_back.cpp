#include "LinkedList.h"

template <typename T>
T List<T>::pop_back() {

    // check the base and return error if the list is empty
    if (isEmpty()) {
        throw std::runtime_error("Cannot pop from back in an empty list.\n");
    }

    Node<T> *nodeToDelete = tail;
    T deletedValue = tail->data;


    // check is there only one node in the list
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T> *current = head;
        while (current->nextPointer != tail) {
            current = current->nextPointer;
        }

        tail = current;
        tail->nextPointer = nullptr;
    }

    delete nodeToDelete;
    return deletedValue;
}