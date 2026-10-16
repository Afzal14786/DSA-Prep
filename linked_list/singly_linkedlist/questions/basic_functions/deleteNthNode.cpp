#include "LinkedList.h"

/**
 * @brief This version will delete a node from back of the list and
 * @return the deleted value
 */

 template <typename T>
 T List<T>::deleteNthNode(int N) {
    int size = listSize();
    if (isEmpty()) {
        throw std::runtime_error("cannot delete from an empty list.\n");
    }

    if (N <= 0 || N > size) {
        throw std::runtime_error("invalid position, please enter a valid position.");
    }

    T deletedValue;

    // delete the  node if N == size()
    if (N == size) {
        deletedValue = head->data;
        Node<T> *nodeToDelete = head;   
        head = head->nextPointer;         // head points to the next node
        delete nodeToDelete;
        //  and check if head == null
        if (head == nullptr) {
            tail = nullptr;
        }
        return deletedValue;
    }

    Node<T> *temp = head;
    for (int i = 0; i < size-N-1; ++i) {
        temp = temp->nextPointer;
    }

    Node<T> *nodeToDelete = temp->nextPointer;
    deletedValue = nodeToDelete->data;
    temp->nextPointer = temp->nextPointer->nextPointer;

    if (temp->nextPointer == nullptr) {
        tail = temp;
    }
    delete nodeToDelete;
    return deletedValue;
 }