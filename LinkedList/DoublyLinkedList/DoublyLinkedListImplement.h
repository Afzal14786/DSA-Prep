#ifndef DOUBLY_LL
#define DOUBLY_LL

#include "DoublyNode.h"

template <typename T>
class Doubly_LL {
    DoublyNode<T> *head;
    DoublyNode<T> *tail;

    public:
        Doubly_LL() {
            head = nullptr;
            tail = nullptr;
        }

        ~Doubly_LL() {
            // distructore
            DoublyNode<T> *currentNode = head;
            while (currentNode != nullptr) {
                /* code */
                DoublyNode<T> *nextNode = currentNode->next;
                delete currentNode;
                currentNode = nextNode;
            }

        }

        // check empty list or not 
        bool isEmpty() {
            if (head == nullptr) {
                return true;
            }
            return false;
        }

        // display a linked list
        void Display_D_LL() {
            DoublyNode<T> *current = head;
            while (current != nullptr) {
                std::cout << current->data;
                if (current->next != nullptr) {
                    std::cout << " -> ";
                }
                current = current->next;
            }
            std::cout << std::endl;
        }

        // now defining all the function that are going to implement outside of this file
        void push_front(T data);    // inserting in the front 
        void push_back(T data);     // inserting in the back 
        void insert(T data, int position);  // insert node in a given position
        T pop_front();          // delete the head and return the value
        T pop_back();           // delete the tail and return the value
        T deleteDNode(int position);    // delete the node at given position
        int DoublyListSize();
        T front();  // return the first value in the DDL
        T back();   // return the last value in DDL
};

#include "Basic_Operations/push_front.cpp"
#include "Basic_Operations/push_back.cpp"
#include "Basic_Operations/insert.cpp"
#include "Basic_Operations/pop_front.cpp"
#include "Basic_Operations/pop_back.cpp"
#include "Basic_Operations/deleteDNode.cpp"
#include "Basic_Operations/DoublyListSize.cpp"
#include "Basic_Operations/front.cpp"
#include "Basic_Operations/back.cpp"

#endif