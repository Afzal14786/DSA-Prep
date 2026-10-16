#include "LinkedList.h"

/**
 * @brief this function search a given value in the list
 * @return the position in find
 */

template <typename T>
int List<T>::search(T value) {
    // base case
    if (isEmpty()) {
        return -1;      // if not find or empty list
    }

    int position = 0;

    Node<T> *temp = head;
    while (temp->nextPointer != nullptr) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->nextPointer;
        position++;
    }

    return -1;      // if not find
}