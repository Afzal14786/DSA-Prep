#include "DoublyLinkedListImplement.h"

/**
 * @brief This version delete the node and return the value
 * @return T
 */

template <typename T>
T Doubly_LL<T>::pop_front() {
    //check the base what if the list is empty
    if (isEmpty()) {
        throw std::runtime_error("cannot delete from an empty list.");
    }

    // create a new node `temp` and assign it to head
    DoublyNode<T> *current = head;
    T deletedValue = current->data;
    head = head->next;
    head->previous = nullptr;
    delete current;
    // std::cout << "Node Deletd From Front Successfully : " << deletedValue << std::endl;
    return deletedValue;
}