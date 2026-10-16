#include "DoublyLinkedListImplement.h"

/**
 * @brief This version insert a new data in a given position
 * We are here consider 1 based indexing, means position = 1 (head)
 */

template <typename T>
void Doubly_LL<T>::insert(T data, int position) {
    // check for the base case
    // first -> size < 0 & position > size
    int size = DoublyListSize();
    if (size < 0 && size > position) {
        throw std::runtime_error("invalid position.");
    }

    // check what if position = 0, means insert in the head
    if (position == 0) {
        push_front(data);
        return;
    }

    // means push in the back
    if (position == size) {
        push_back(data);
        return;
    }

    // now we have to inser at a given positon 
    // using a loop we can move till positon -1
    // create a temp node and assign it to head and create a new node that holds the data
    DoublyNode<T> *newNode = new DoublyNode(data);
    DoublyNode<T> *current = head;
    for (int i = 0; i < position - 1; ++i) {
        current = current->next;
    }

    // 1 -> 2 -> 3 -> 4 -> nullptr

    newNode->next = current->next;
    newNode->previous = current;
    current->next->previous = newNode;
    current->next = newNode;
}