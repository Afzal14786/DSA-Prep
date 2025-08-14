
#include "LinkedList.h"

/**
 * @brief This version remove duplicates from list as well as display the position at which position the duplicate is present 
 * @return T
 */

template <typename T>
T List<T>::duplicate() {
    // check basic condition
    if (isEmpty()) {
        throw std::runtime_error("list is empty.\n");
    }

    // now check for duplicate and also count the position in which it is present 
    int position = 0;
    Node<T> *previous = head;
    Node<T> *current = head->nextPointer;

    while (current != nullptr) {
        if (previous->data != current->data) {
            previous = current;
            position++;
            current = current->nextPointer;
        } else {
            position++;
            // means that we found that there is a duplicate
            previous->nextPointer = current->nextPointer;
            delete current;
            current = previous->nextPointer;
        }
    }
    std::cout << "The Value Is Deleted From Position : " << position << std::endl;
    return position;

}

