#include "DoublyLinkedListImplement.h"

/**
 * @brief This version return the head node's value
 */

template <typename T>
T Doubly_LL<T>::front() {
    // check the base case
    if (isEmpty()) {
        throw std::runtime_error("the list is empty");
    }

    std::cout << "The front value from the list is : " << head->data << std::endl;
    return head->data;
}