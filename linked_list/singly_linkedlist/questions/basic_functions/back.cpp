#include "LinkedList.h"

/***
 * @brief this function it returns the last node's value
 * @return T
 */
template <typename T>
T List<T>::back() {
    // base case 
    if (isEmpty()) {
        throw std::runtime_error("list is empty");
    }

    return tail->data;
}