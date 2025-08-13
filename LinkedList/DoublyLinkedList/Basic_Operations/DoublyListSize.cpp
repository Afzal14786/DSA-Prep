#include "DoublyLinkedListImplement.h"

template <typename T>
int Doubly_LL<T>::DoublyListSize() {
    DoublyNode<T> *current = head;

    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}