#include "LinkedList.h"

/**
 * @brief This insert function will insert a node in a given positon
 */
template <typename T>
void List<T>::insert(T data, int position) {
    // check the valid position
    if (position < 0) {
        throw std::runtime_error("Position Cannot Be Negative.\n");
    }

    // what if position == 0, means head
    if (position == 0) {
        push_front(data);
        return;
    }

    // now go till position -1 
    Node<T> *currNode = head;
    for (int i = 0; i < position-1; ++i) {
        if (currNode == nullptr) {
            throw std::runtime_error("Position Is Out Of Bound(Size)");
        }
        currNode = currNode->nextPointer;
    }

    // now what if after traversal currNode is null then
    if (currNode == nullptr) {
        throw std::runtime_error("Position Is Out Of Bound(Size)");
    }

    // and what if the position points the last node then
    if (currNode == tail) {
        push_back(data);
        return;
    }

    // if all the cases pass then create a new node 
    Node<T> *newNode = new Node<T>(data);
    newNode->nextPointer = currNode->nextPointer;
    currNode->nextPointer = newNode;
}