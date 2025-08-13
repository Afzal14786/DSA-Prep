#include "DoublyLinkedListImplement.h"

/**
 * @brief This version of code return the value of tail's 
 */

template <typename T>
T Doubly_LL<T>::back() {
    // check base cases

    if (isEmpty()) {
        throw std::runtime_error("list is empty.");
    }

    std::cout << "back value form the linked list is : " << tail->data << std::endl;
    return tail->data;
}