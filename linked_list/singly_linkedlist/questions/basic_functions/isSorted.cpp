#include <climits>

#include "LinkedList.h"


/**
 * @brief This version check if the list is sorted or not
 * @return True | False
 */


template <typename T>
bool List<T>::isSorted() {
    // check for the base case if the list is empty
    if (isEmpty()) {
        std::cout << "list is empty.\n";
        return false;
    }

    // what if there is only one node in the list
    if (head->nextPointer == nullptr) {
        // single value is alreadt sorted by default, so 
        std::cout << "list contain a single node, so by default it is sorted.\n";
        return true;
    }

    // we can solve it using a single pointer
    // take a minimum value integer
    // and compare it with the current calue
    Node<T> *current = head;
    int min_value = INT_MIN;

    // now run a loop till null pointer while comparing with the value
    while (current != nullptr) {
        if (current->data < min_value) {
            std::cout << "list is not sorted.\n";
            return false;
        }

        min_value = current->data;          // hold the value of current in the min_value
        current = current->nextPointer;     // and move to the next node
    }

    std::cout << "list is sorted.\n";
    return true;
}