# Basic Implementation Of LinkedList  



**Some Important Function That Is Used In Linked List Frequently**  

-   **[push_front(int data)](#1-push_frontint-data)** : _Inserting data into the LL_  
-   **[push_back(int data)](#2-push_backint-data)** : _Inserting data in the end of the LL_  
-   **[insert(int data, int position)](#3-insertint-data-int-position)** : _Inserting data in a given position_  
-   **[pop_front()](#4-pop_front--return-poped-data)** : _Deleting a node from front_  
-   **[pop_back()](#5-pop_back-return-the-poped-value)** : _Deleting a node fron back_  
-   **[front()](#6-front-this-function-return-the-value-of-head-node)** : _return the head's value_
-   **[back()](#7-back-this-function-will-return-the-tails-value)** : _return the tail's value_
-   **[search(int value)](#8-searchint-key-searching-a-value-in-the-list-found--position---1)** : _Searchin a particular value_  
-   **[recursiveSearch(int value)](#9-recursivesearchint-key-we-can-use-recursive-approach-as-well-for-searching-because-in-this-seaction-we-cannot-directly-head-inside-the-main-so-well-use-a-helper-function)** : _Using recursive we can search a value_
-   **isSorted()** : _check if the list is sorted or not_
-   **duplicate()** : _Check is there any duplicate in the list_
-   **reverse()**  : _Reverse the list_  
-   **merge()**    : _Merge or Concat two lists_  
-   **[isCycle()](#10-iscycle--check-if-the-list-has-cycle-exist-or-not)** : _Check if is cycle exist or not_


**_Here is the implementation of above functions using own class_**  

_First we need to implement the linked list_  

```cpp
#ifndef NODE_H
#define NODE_H

// we are using templates so out node can use any data types

template <typename T>
class Node {
    public:
        T data;
        Node<T> *nextPointer;
        Node(T data) {
            this->data = data;
            this->nextPointer = nullptr;
        }

        ~Node() {
            // just for testing purpose
            // std::cout << "Node With Data" << data << " Destructor" << std::endl;
        }
};

#endif
```

```cpp
// this List class is actually creating the function

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
```

**I have implemented each function individually. You can refer the code for understanding the implementation .**
  
### 1. [push_front(int data)](./push_front.cpp)  
```cpp
#include "LinkedList.h"
template <typename T>
/**
 * @brief pop_front : deleting a node from head and 
 * @return the head's value
 */

T List<T>::pop_front() {
    // first check the base case
    if (isEmpty()) {
        // if the list is empty then return an error
        throw std::runtime_error("Cannot pop from an empty list");
    }

    // create a temp node that hold the head
    Node<T> *curr = head;
    T deletedData = head->data;
    head = head->nextPointer;       // now heads points to the next pointer

    // if the next is null then tail also points to null
    if (head == nullptr) {
        tail = nullptr;
    }

    curr->nextPointer = nullptr;    // break the connection
    delete curr;        // avoid memory lead
    return deletedData;
}
```

### 2. [push_back(int data)](./push_back.cpp)  
```cpp
#include "LinkedList.h"

/**
 * @brief Pushing data from tail in the list
 * @param T can be any data type : Integer, String etc..
 */
template <typename T>
void List<T>::push_back(T data) {
    Node<T> *newNode = new Node<T>(data);

    // if list is empty then both can point in the same newNode
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->nextPointer = newNode;
        tail = newNode;
    }
}
```

### 3. [insert(int data, int position)](./insert.cpp)  
```cpp
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
```

### 4. [pop_front()](./pop_front.cpp)  _return poped data_
```cpp
#include "LinkedList.h"
template <typename T>

/**
 * @brief pop_front : deleting a node from head and 
 * @return the head's value
 */

T List<T>::pop_front() {
    // first check the base case
    if (isEmpty()) {
        // if the list is empty then return an error
        throw std::runtime_error("Cannot pop from an empty list");
    }

    // create a temp node that hold the head
    Node<T> *curr = head;
    T deletedData = head->data;
    head = head->nextPointer;       // now heads points to the next pointer

    // if the next is null then tail also points to null
    if (head == nullptr) {
        tail = nullptr;
    }

    curr->nextPointer = nullptr;    // break the connection
    
    delete curr;        // avoid memory lead

    return deletedData;
}
```

### 5. [pop_back()](./pop_back.cpp) _return the poped value_
```cpp
#include "LinkedList.h"

template <typename T>
T List<T>::pop_back() {

    // check the base and return error if the list is empty
    if (isEmpty()) {
        throw std::runtime_error("Cannot pop from back in an empty list.\n");
    }

    Node<T> *nodeToDelete = tail;
    T deletedValue = tail->data;


    // check is there only one node in the list
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T> *current = head;
        while (current->nextPointer != tail) {
            current = current->nextPointer;
        }

        tail = current;
        tail->nextPointer = nullptr;
    }

    delete nodeToDelete;
    return deletedValue;
}
```

### 6. [front()](./front.cpp)  _this function return the value of head node_  
```cpp
#include "LinkedList.h"

/**
 * @brief this function front will return the first node's value in the list
 * @return T
 */
template <typename T>
T List<T>::front() {

    // check the base conditions
    if (isEmpty()) {
        // if the list is empty then we give an error
        throw std::runtime_error("The list is empty.\n");
    }

    // T value = head->data;
    return head->data;
}
```

### 7. [back()](./back.cpp) _this function will return the tail's value_  

```cpp
#include "LinkedList.h"
/***
 * @brief this function it returns the last node's value
 * @return T
 */
template <typename T>
T List<T>::back() {
    // base case 
    if (isEmpty()) {
        throw std::runtime_error("list is empty");
    }

    return tail->data;
}
```

### 8. [search(int key)](./search.cpp) _Searching a value in the list, found ? position : -1_
```cpp
#include "LinkedList.h"
/**
 * @brief this function search a given value in the list
 * @return the position in find
 */

template <typename T>
int List<T>::search(T value) {
    // base case
    if (isEmpty()) {
        return -1;      // if not find or empty list
    }

    int position = 0;

    Node<T> *temp = head;
    while (temp->nextPointer != nullptr) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->nextPointer;
        position++;
    }

    return -1;      // if not find
}
```
### 9. [recursiveSearch(int key)](./recursiveSearch.cpp) _We can use recursive approach as well for searching, because in this seaction we cannot directly **head**, inside the `main` so we'll use a helper function._ 
```cpp
#include "LinkedList.h"

template <typename T>
int List<T>::recursiveSearch(T value) {
    return helper(head, value);
}
```

### 10. [isCycle()](./isCycle.cpp) : _Check if the list has cycle exist or not_  
```cpp
#include "LinkedList.h"

/**
 * @brief It check if the list has cycle or not
 * @return true if cycle : false if not
 */
template <typename T>
bool List<T>::isCycle() {
    // check basic condition
    if (isEmpty() || head->nextPointer == nullptr) {
        cout << "List is empty or only one element in the list.\n";
        return false;
    }

    Node<T> *slow = head;
    Node<T> *fast = head;

    while (fast != nullptr && fast->nextPointer != nullptr) {
        slow = slow->nextPointer;
        fast = fast->nextPointer->nextPointer;
        if (slow == fast) {
            cout << "cycle exist.\n";
            return true;
        }
    }

    return false;
}
``` 

### 11. [MergeSort()](./mergeSort.cpp) : _Using Linked List We Can Sort A Given List_ 
```cpp
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
```

