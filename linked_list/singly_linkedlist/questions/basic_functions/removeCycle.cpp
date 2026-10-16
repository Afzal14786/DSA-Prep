#include "LinkedList.h"

/**
 * @brief This version is removing a cycle or loop from a lis
 */

template <typename T>
void List<T>::removeCycle() {

    // base case is to check if the list is empty or not
    if (isEmpty()) {
        throw std::runtime_error("empty list doesn't have any loop or cycle. You stupied");
    }

    Node<T> *slow = head;
    Node<T> *fast = head;
    bool isCycle = false;
    while (fast != nullptr && fast->nextPointer != nullptr) {
        slow = slow->nextPointer;
        fast = fast->nextPointer->nextPointer;
        if (slow == fast) {
            isCycle = true;
            break;
        }
    }

    if (!isCycle) {
        cout << "Cycle Doesn't Exisit.\n";
        return;
    }

    // now update the slow
    slow = head;

    // now check the special case
    if (slow == head || fast == head) {
        while (fast->nextPointer != slow) {
            fast = fast->nextPointer;
        }

        std::cout << "Cycle Removed.\n";
        fast->nextPointer = nullptr;    // deleting the loop or cycle

    } else {
        // normal case, 
        Node<T> *previou = fast;
        while (slow != fast) {
            slow = slow->nextPointer;
            previou = fast;
            fast = fast->nextPointer;
        }

        std::cout << "Cycle Removed.\n";
        previou->nextPointer = nullptr; // deleting the loop or cycle from list .
    }
}