#include "LinkedList.h"

/**
 * @brief this function front will return the first node's value in the list
 * @return T
 */
template <typename T>
T List<T>::front() {

    // check the base conditions
    if (isEmpty()) {
        // if the list is empty then we give an error
        throw std::runtime_error("The list is empty.\n");
    }

    // T value = head->data;
    return head->data;
}