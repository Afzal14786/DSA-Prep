#include "LinkedList.h"

/**
 * @brief This version will call in the main function
 */
template <typename T>
void List<T>::mergeSort() {
    this->head = mergeSortHelper(this->head);
}


template <typename T>
Node<T> *List<T>::mergeSortHelper(Node<T> *head) {
    // Base case: a list with 0 or 1 element is already sorted.
    if (head == nullptr || head->nextPointer == nullptr) {
        return head;
    }

    // 1. Divide: Split the list into two halves.
    Node<T> *secondHalf = splitListInMid(head);

    // 2. Conquer: Recursively sort the two halves.
    Node<T> *left = mergeSortHelper(head);
    Node<T> *right = mergeSortHelper(secondHalf);

    // 3. Combine: Merge the two sorted halves.
    return mergingList(left, right);
}

/**
 * @brief This version will split a list into two list
 * It finds the node just before the midpoint and severs the link.
 */
template <typename T>
Node<T>* List<T>::splitListInMid(Node<T>* head) {
    // show start from head (0)
    Node<T>* slow = head;
    // and fast start form next after head (1)
    Node<T>* fast = head->nextPointer;

    
    while (fast != nullptr && fast->nextPointer != nullptr) {
        slow = slow->nextPointer;
        fast = fast->nextPointer->nextPointer;
    }

    // 'slow' is now the node just before the midpoint.
    Node<T>* second_half = slow->nextPointer;
    slow->nextPointer = nullptr; // Sever the link to split the list.

    return second_half;
}

/**
 * @brief This version will merg two sorted list
 */
template <typename T>
Node<T>* List<T>::mergingList(Node<T> *left, Node<T> *right) {
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    Node<T>* result = nullptr;
    if (left->data <= right->data) {
        result = left;
        result->nextPointer = mergingList(left->nextPointer, right);
    } else {
        result = right;
        result->nextPointer = mergingList(left, right->nextPointer);
    }
    return result;
}