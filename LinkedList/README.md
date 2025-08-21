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

We should choose Linked List over array when we want fast insertions and deletions in the middle of the data sequence and we don't know about the side of the data sequence .  

As we know for getting an element, the array is more advance than linked list, because in array we can access the element is constant time using just it's index value . `(e.g arr[5])` . However if we want to insert and delete in the middle of data sequence in an array, then this point it will not easy task as compare to linked list .  

And we know that linked list store the data in sequence but all the data is stored in different memory locations using Node, And each node hold **the data** and **referance pointer** (memory location) to other **Node** .  

### Application Of Linked Lists  

1. **Implementing Other Data Structures 🧩**  

    - Linked List is often used implementing other abstract data structures.
    - **[Stack Data Structure](../Stack/README.md)** : A stack follows a "Last-In, First-Out" (LIFO) principle. Implementing a stack with a linked list is very efficient. Pushing (adding) and popping (removing) an element just involves adding or removing a node from the head of the list, which is an O(1) operation (constant time). An array-based stack can suffer from overflow if its fixed size is exceeded .  

    - **[Queues Data Structure](../Queues/README.md)** : A queue follows a "First-In, First-Out" (FIFO) principle. A linked list is perfect for this. Enqueue (adding an element) happens at the tail (end) of the list, and dequeue (removing an element) happens at the head (start). Both are O(1) operations. 

2. **Dynamic Memory Allocation 💾**  

    - In operating systems, linked lists are used to manage the available memory (the "free list"). When a program requests a block of memory, the system finds a suitable block in the free list, allocates it to the program, and adjusts the pointers. When the memory is freed, it's added back to the list. Since memory allocation and deallocation happen frequently and unpredictably, the efficient insertion and deletion capabilities of linked lists are crucial. 

3. **Music Players and Image Viewers 🎶**  

Think of a playlist in a music player or a slideshow in an image viewer. You often want to add, remove, or reorder songs/images.  

- **Previous/Next Functionality:** A doubly linked list (where each node points to both the next and the previous node) is ideal here. Moving to the next or previous item is as simple as following a pointer.  

- **Editing Playlists:** Adding a new song in the middle of a playlist or removing one is a fast operation with a linked list, unlike an array where you'd have to shift many elements.

4. **Web Browser History 🌐**  

Your web browser's "back" and "forward" buttons are a classic example of a doubly linked list in action. 

- Each web page you visit becomes a node in the list.
- Clicking "back" moves the current pointer to the previous node.
- Clicking "forward" moves it to the next node.
- Opening a new link from the current page adds a new node after the current one and deletes any "forward" history.

Because the sequence of visited pages is constantly changing, a linked list is a much more natural and efficient fit than a static array.

5. **Polynomial Representation ➕**

Linked lists can represent mathematical polynomials like $3x^2 − 8x + 5$. Each node can store a **coefficient** and an **exponent**, with a pointer to the next term. This method is particularly useful for sparse **polynomials** (those with many zero-coefficient terms), as you only need to store the non-zero terms, saving significant space compared to an array. Operations like ***polynomial addition*** and ***multiplication*** become easier to implement.



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

***Follow the [implementation of basic function in linked list](./SinglyLinkedList/Question/Basic_Functions/README.md)*** 