#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class List {
    Node<T> *head;
    Node<T> *tail;

    public:
        List() {
            head = nullptr;
            tail = nullptr;
        }

        ~List() {
            Node<T> *current = head;
            Node<T> *nextNode = nullptr;

            while (current != nullptr) {
                nextNode = current->nextPointer;
                delete current;
                current = nextNode;
            }

            head = nullptr;
            tail = nullptr;
        } 

        // implementation of basic and all the other function like

        void DisplayList() {
            Node<T> *curr = head;
            while (curr != nullptr) {
                std::cout << curr->data;
                if (curr->nextPointer != nullptr) {
                    std::cout << " -> ";
                }
                curr = curr->nextPointer;
            }
            std::cout << std::endl;
        }

        // chekc for empty
        bool isEmpty() {
            if (head == nullptr) {
                return true;
            }
            return false;
        }

        int size() {
            Node<T> *current = head;
            int count = 0;
            while (current != nullptr) {
                count++;
                current = current->nextPointer;
            }
            // return count of the list
            return count;
        }

        // helper function for recursive search
        int helper(Node<T> *head, int value) {
            if (head == nullptr) {
                return -1;
            }

            if (head->data == value) {
                return 0;
            }

            int idx = helper(head->nextPointer, value);

            if (idx == -1) {
                return -1;
            }

            return idx + 1;
        }

        void makeCycle() {
            if (head == nullptr) {
                return;
            }
            tail->nextPointer = head;
        }

        void push_front(T data);    // adding in the head
        void push_back(T data);     // adding in the tail
        T pop_front();           // deleting from head and return deleted value
        T pop_back();            // deleting from tail and return deleted value
        T front();                // return head's data
        T back();                 // return tail's data
        void insert(T data, int position);  // insert in a position
        int search(T value);      // search a value and return the position
        int recursiveSearch(T value);   // using recursive we can search 
        void reverse();              // reverse the list
        int deleteNthNode(int N);   // delete a node which is present in Nth position
        bool isCycle();         // check if is there any cycle in the list
        void removeCycle();     // remove a cycle 
        void mergeSort();       // merge two sorted list
        Node<T> *splitListInMid(Node<T> *head);     // spleeting the list in half
        Node<T> *mergingList(Node<T> *left, Node<T> *right);     // just for merging
        Node<T> *mergeSortHelper(Node<T> *head);     // this will help to call merge sort, so from main we can call only list.mergeSort() without parameter
};

#include "Basic_Functions/push_front.cpp"       // done
#include "Basic_Functions/push_back.cpp"        // in-process -> Done
#include "Basic_Functions/pop_front.cpp"        // in-process -> Done
#include "Basic_Functions/pop_back.cpp"         // in-process -> Done
#include "Basic_Functions/front.cpp"            // in-process -> Done
#include "Basic_Functions/back.cpp"             // in-process -> Done
#include "Basic_Functions/insert.cpp"           // in-process -> Done
#include "Basic_Functions/search.cpp"           // in-process -> Done
#include "Basic_Functions/recursiveSearch.cpp"  // in-process -> Done
#include "Basic_Functions/reverse.cpp"
#include "Basic_Functions/deleteNthNode.cpp"
#include "Basic_Functions/isCycle.cpp"
#include "Basic_Functions/removeCycle.cpp"
#include "Basic_Functions/mergeSort.cpp"

#endif