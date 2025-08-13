#include "LinkedList.h"
using namespace std;

/**
 * @brief In the list we are pushing data 
 * @param T can be any type (Integer, String, etc...)
 */

template <typename T>
void List<T>::push_front(T data) {
    Node<T> *newNode = new Node<T>(data);

    // check the base case
    if (head == nullptr) {
        // means that the list is empty
        head = tail = newNode;
    } else {
        newNode->nextPointer = head;
        head = newNode;
    }
}