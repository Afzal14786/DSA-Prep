#include "LinkedList.h"

/**
 * @brief This version reverse a given Linked List
 */

 /**
  *         Approach
  * 1. Using Three Pointer, We Can Reverse The Entire List In-Place
  *     * previous : points to previous Node, initially previous = nullptr
  *     * current  : points the current node
  *     * next     : points the next node
  * 
  * 2. First we have to find the value of next pointer
  *     next = current->nextPointer
  * 3. Then we have to modify the current->nextPointer to previous
  *     means if list look like : 1 -> 2 -> 3
  *     then it will look like : nullptr <- 1  (previous = current->nextPointer)
  * 4. Now update the previous and current
  *     previous will point on current  means (previous = current)
  *     and current will point on next  means (current = next)
  */

/**
 * @brief This version reverse2 will help us in reversing a second half list from mid to end
 * @example actual list is 1 -> 2 -> 3 -> 4 -> 5 -> nullptr and in this list, head = 1 and midNode = 3
 * So, newList after reversing look like : 1 -> 2 -> nullptr, 5 -> 4 -> 3 -> nullptr;
 * 
 * This version will help us in ZigZag code
 */
template <typename T>
Node<T>* List<T>::reverse2(Node<T> *midNode) {
    // check the base conditions
    if (isEmpty()) {
        throw std::runtime_error("unable to reverse empty list");
    }

    Node<T> *previous = nullptr;
    Node<T> *current = midNode;
    Node<T> *next = nullptr;

    while (current != nullptr) {
        next = current->nextPointer;
        current->nextPointer = previous;

        previous = current;
        current = next;
    }
    return previous;
}

template <typename T>
void List<T>::reverse() {
   if (isEmpty()) {
        throw std::runtime_error("unable to reverse, since list is empty.\n");
    }

    Node<T> *previous = nullptr;
    Node<T> *current = head;
    

    // what if there is one or two list
    // 1 -> 2
    // 1 = head and 2 = head->nextPointer
    if (current->nextPointer->nextPointer == nullptr) {
        current->nextPointer->nextPointer = current;
        current->nextPointer = nullptr;

        head = current;
        // now it becomes 2 <- 1
    }

    while (current != nullptr) {
        Node<T> *next = current->nextPointer;
        current->nextPointer = previous;

        previous = current;
        current = next;
    }

    head = previous;
}