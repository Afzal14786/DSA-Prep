#include "DoublyLinkedListImplement.h"

/**
 * @brief This version will delete a node from back side of the list
 * @return T
 */

template <typename T>
T Doubly_LL<T>::pop_back() {
    // check the base case : what if the list is empty
    if (isEmpty()) {
        throw std::runtime_error("cannot delete from an empty list.");
    }

    // now best easy way to delete a node from back,
    // create a temp node and assign it to tail
    DoublyNode<T> *temp = tail;
    // now modify the tail;
    tail = tail->previous;
    tail->next = nullptr;
    T deletedValue = temp->data;
    // std::cout << "Deleted value from back is : " << deletedValue << std::endl;
    delete temp;
    return deletedValue;
}