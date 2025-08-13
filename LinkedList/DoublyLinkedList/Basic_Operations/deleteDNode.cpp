#include "DoublyLinkedListImplement.h"

/**
 * @brief This version will delete a node at given positon
 * return T
 */

template <typename T>
T Doubly_LL<T>::deleteDNode(int position) {
    // check the base cases
    if (isEmpty()) {
        throw std::runtime_error("cannot delete from an empty list.");
    }

    // now check what if the size is invalid
    int size = DoublyListSize();

    if (position < 0 || position >= size) {
        throw std::runtime_error("invalid size.");
    }

    // now what if we are deleting the head means at position 0
    if (position == 0) {
        T deletedValue = pop_front();
        std::cout << "The Deleted Value At Given Position (" << position << ") is " << deletedValue << std::endl;
        return deletedValue;
    }

    if (position == size-1) {
        T deletedValue =  pop_back();
        std::cout << "The Deleted Value At Given Position (" << position << ") is " << deletedValue << std::endl;
        return deletedValue;
    }

    //  now we are checking for a given position
    // create a temp node and assign it to head to it will travel through the list

    DoublyNode<T> *temp = head;

    for (int i = 0; i < position; ++i) {
        temp = temp->next;
    }

    T deletedValue = temp->data;
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    
    delete temp;
    std::cout << "The Deleted Value At Given Position (" << position << ") is " << deletedValue << std::endl;
    return deletedValue;
}