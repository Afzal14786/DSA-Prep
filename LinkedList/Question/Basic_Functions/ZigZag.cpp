#include "LinkedList.h"

template <typename T>
void alternativeMerge(Node<T> *left, Node<T> *right) {
    
    Node<T> *tail = nullptr;

    while (left != nullptr && right != nullptr) {
        Node<T> *leftHeadNextPointer = left->nextPointer;
        Node<T> *rightHeadNextPointer = right->nextPointer;
        left->nextPointer = right;
        right->nextPointer = leftHeadNextPointer;
        tail = right;
        left = leftHeadNextPointer;
        right = rightHeadNextPointer;   
    }

    tail->nextPointer = right;
}

template <typename T>
void List<T>::ZigZag() {
    Node<T> *rightHead = splitListInMid(head);  // first this will split the reverse and return the right head for the second half list
    Node<T> *rightHeadMid = reverse2(rightHead);    // this will then reverse from second half

    //  now we have to merge alternative so it will create ZigZag
    alternativeMerge(head, rightHeadMid);
}