#include "LinkedList.h"

/**
 * @brief It check if the list has cycle or not
 * @return true if cycle : false if not
 */
template <typename T>
bool List<T>::isCycle() {
    // check basic condition
    if (isEmpty() || head->nextPointer == nullptr) {
        cout << "List is empty or only one element in the list.\n";
        return false;
    }

    Node<T> *slow = head;
    Node<T> *fast = head;

    while (fast != nullptr && fast->nextPointer != nullptr) {
        slow = slow->nextPointer;
        fast = fast->nextPointer->nextPointer;
        if (slow == fast) {
            cout << "cycle exist.\n";
            return true;
        }
    }

    return false;
}