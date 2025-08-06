# Linked List  

A **linked list** is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.  

![Linked list image](https://framerusercontent.com/images/tLmeI11H447kbfs3gNzhsLt5hLE.png)

1. It is a **linear dynamic data structure**  
2. The number of **nodes** in a linked list is not fixed, means that it can grow and shrink on demand.  
3. Each linked list is made-up of two items:  
    -  **The Data**
    - **A referance to the next node**
4. The last node has a referance to `null`.
5. The entry point of a linked list is called `head` of the list. (If the list is empty then the head is a null referance)  

## Why Linked List  
_Both `linked list` and `arrays` are used to store data or the collection of data, since both are used for same purpose_  

- _**We should know in which cases `array` are suitable and in which cases `linked list` is suitable.**_  

## Linked List v/s Arrays  

**Arrays**  
_Arrays is also a liner data structure and used to store data or collection of data / information but in the memory arrays store the data in contiguous, **means that each data or element is uniquely identified by an index or key, typically start from `0`**_.  

_Arrays store elements of the same data type, such as **integers**, **characters**, or **objects**._  

_**Arrays has it's own advantages or disadvantages:**_  

_Advantages:_
- __a. Simple and easy to use__
- __b. Faster access to the element (constant access)__  
    * Elements are accessed using an index, which represents their position within the array. This allows for constant-time access to any element, regardless of the array's size.


_Disadvantages:_  
-   **a. Fixed Size:**  
    *   _This is the major disadvantage of arrays, it can not grow and shrink on demand. Once memory is created, it's size cannot be changed_.
-  **b. Memory Wastage:**
    *   _If we declare an array with large size and let say the entire array is not used then the unused memory is wasted_.
-   **c. Overflow:**
    *   _If we need to store more elements than the array's declared capacity, we can't simply add more space. We have to create a new, larger array and copy all the elements from the old one to the new one, which is an inefficient process_.
-   **Inefficient Insertion and Deletion 🐢**  
    *   _Insertion and deletion in an arrays is very difficult in a given position compare to linked list or any other data structure_  


**Linked List**  
_**Linked List also comes with it's own advantages and disadvantages:**_  

_Advantages:_  

- In linked list it can be **expanded** in constant time.  
- We can start with space for just one allocated element and _add_ new element easily without the need to do any copying and reallocating.  

_Disadvantages:_  
There are list of issues with linked list. The main disadvantage of linked lists is that:  

- The _**access time**_ to individual element . Linked list takes `O(n)` time for access to an element in the list in the wrost case.
- Linked list also waste memory in terms of extra referance pointers.

## Important Concepts  
-   _Every `node` represent two things **Data** & **A referance pointer to next node**_  
-   _Every node has a **head** and a **tail** pointer in singly linked list_  
-   * **Head Node** : _The very first node is known as head node_  
    * **Tail Node** : _The node which has no referance pointer for next node is known as tail node_  

In short, `HEAD` pointer represent the first node in the list and `TAIL` node represent the last node.  


## Type Of Linked List  
-   1. Singly Linked List ➡️
-   2. Doubly Linked List ↔️  
-   3. Circular Linked List 🔄  

**Singly Linked List**  

_A **singly linked list** is the most basic type. Each node contains two parts: **the data** and a **single pointer** (or link) that references the **next node** in the sequence. Traversal is `unidirectional`, meaning we can only move forward through the list, from `head` to `tail`. The last node's pointer is typically set to `null`, indicating the end of the list._  
-    **Structure:** [Data | Next]

**Doubly Linked List**  
_In a **doubly linked list**, each node has **two pointers**. One pointer links to the **next node** in the sequence, and the **other links** to the `previous node`. This structure allows for `bidirectional traversal`, meaning you can **navigate both forward and backward through the list**. While this provides more flexibility than a singly linked list, it requires more memory to store the additional pointer in each node._  

-   **Structure:** [Previous | Data | Next]  

**Circular Linked List**  
_A **circular linked list** is a variation in which the **last node** of the list points back to the **first node**, instead of pointing to null. This creates a `continuous loop`. A circular linked list can be either `singly or doubly linked`._  

-   **Singly Circular Linked List:** The last node's **next** pointer points to the head of the list.  
-   **Doubly Circular Linked List:** The last node's **next** pointer points to the head, and the head's "previous" pointer points to the last node, creating a complete circle in both directions.


## Implementation Of Linked List  
We can implement linked list using `classes` and `STL`**(Standerd Template Library)**

-   **In this section we'll first use own defined classes for implementing the Linked List then latter on we'll be using `STL` for solving any problems in LL.**  


**Some Important Function That Is Used In Linked List Frequently**  

-   **push_front(int data)** : _Inserting data into the LL_  
-   **push_back(int data)** : _Inserting data in the end of the LL_  
-   **push_middle(int data, int position)** : _Inserting data in a given position_  
-   **pop_front()** : _Deleting a node from front_  
-   **pop_back()** : _Deleting a node fron back_  
-   **search(int value)**  _Searchin a particular value_  
-   **isSorted()**  _check if the list is sorted or not_
-   **duplicate()** _Check is there any duplicate in the list_
-   **reverse()**   _Reverse the list_  
-   **merge()**     _Merge or Concat two lists_  


**_Here is the implementation of above functions using own class_**  

_First we need to implement the linked list_  
```cpp
#include <iostream>
using namespace std;

// this Node class contain data and referance to next pointer
class Node {
    int data;
    Node *nextPtr;
    friend class List;  // means List class can access my private information

    public:
        Node(int data) {
            this->data = data;
            nextPtr = nullptr;
        }

        // it will delete the allocated node memory
        ~Node() {
            if (nextPtr != nullptr) {
                delete nextPtr;
                nextPtr = nullptr;
            }
        }
};

// this List class is actually creating the function

class List {
    Node *head;
    Node *tail;

    public:
        List() {
            head = nullptr;
            tail = nullptr;
        }

        // it will delete the list
        ~List() {
            if (head != nullptr) {
                delete head;
                head = nullptr;
            }
        }

        void push_front(int data);
        void push_back(int data);
        void push_middle(int data, int position);
        int pop_front();
        int pop_back();
        void print_LL();
};
```

**Here we'll implementing each function clearly**  
1. **push_front(int data)**  
```cpp
void List::push_front(int data) {
    // first create a new Node
    Node *newNode = new Node(data);

    // if LL is empty
    if (head == nullptr) {
        // means this is the first node
        head = tail = newNode;
    } else {
        // if this is not the first node then
        newNode->nextPtr = head;
        head = newNode;
    }
}
```

2. **push_back(int data)**  
```cpp
void List::push_back(int data) {
    // create a new Node
    Node *newNode = new Node(data);
    // if LL is empty
    if (head == nullptr) {
        // means this is the first node
        head = tail = newNode;
    } else {
        // create a temp node and point to head 
        tail->nextPtr = newNode;
        tail = newNode;
    }
}
```

3. **push_middle(int data, int position)**  
```cpp
void List::push_middle(int data, int position) {
    // check if it null or not
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        // create a temp node & assign to it head and move till position-1
        Node *temp = head;
        for (int i = 0; i < position-1; ++i) {
            if (temp == nullptr) {
                // invalid position
                cout << "Invalid Position\n";
                return;     // -> Go Back
            }
            // move to the next pointer till position-1
            temp = temp->nextPtr;
        }
        newNode->nextPtr = temp->nextPtr;
        temp->nextPtr = newNode;
    }
}
```

4. **pop_front()**  _return poped data_
```cpp
int pop_front() {
    // base cases
    if (head == nullptr) {
        cout << "List is empty\n";
        return -1;
    }
    int pop_data = -1;
    if (head == tail) {
        pop_data = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    Node *temp = head;
    pop_data = head->data;
    head = head->next;  // move head to next
    temp->nextPtr = nullptr;
    delete temp;

    return pop_data;
}
```

5. **pop_back()** _return the poped value_
```cpp
int pop_back() {
    // base case
    if (head == nullptr) {
        cout << "List is empty\n";
        return -1;
    }

    int pop_data = -1;
    if (head == tail) {
        pop_data = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    Node *temp = head;
    while (temp->nextPtr != tail) {
        temp = temp->nextPtr;
    }

    pop_data = tail->data;
    temp->nextPtr = nullptr;
    delete tail;
    tail = temp;

    return pop_data;
}
```
6. **search(int key)** _Searching a value in the list, found ? position : -1_
```cpp
int search(int key) {
    // base case
    if (head == nullptr) {
        cout << "List is empty\n";
        return -1;
    }

    Node *temp = head;
    int pos = 0;
    while (temp != nullptr) {
        if (temp->data == key) {
            return pos;
        }
        temp = temp->nextPtr;
        pos++;
    }

    return -1;
}
```