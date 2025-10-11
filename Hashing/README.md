# 🔑 Hashing: The Key to Fast Data Retrieval

![Hash Table](../assets/hash-table.png)  

## What is Hashing?

Hashing is a technique used to **map** data of arbitrary size (like a large string, file, or object) to a fixed-size value, known as a **hash value**, **hash code**, or simply **hash**.

At its core, Hashing provides a powerful mechanism for data storage and retrieval that is dramatically **faster** than **searching** through a sequential list.

## Hashing vs. Arrays

| Feature | Array | Hashing (Hash Table/Map) |
| :--- | :--- | :--- |
| **Indexing** | Indexed by **integers** (e.g., `array[0]`, `array[1]`). | Indexed by **keys** of any data type (e.g., strings, objects). |
| **Data Structure** | Sequential data structure. | **Associative Array** (Key-Value pairs). |
| **Lookup Time** | $O(n)$ average (if unsorted) | $O(1)$ average (Constant Time) |

## The Hash Table Data Structure

A **hash table** is a collection of items which are stored in such a way to make it easy to find them later . Each position of the hash table, often called a `slot` _(or a bucket)_, that can hold an item and is named by an integer value starting at 0.

Or also we can say that, a **hash table** or **hash map** is a _data structure_ that store the keys and their associated values, and hash table use hash function to map keys to their associated values . The general convention is that we use a hash table when the number of keys actually stored in small relative to the number of possible keys.

A Hash Table uses two main components:

1.  **Buckets (or Slots):** An array structure that holds the stored data.
2.  **Hash Function:** A mathematical function that takes an input **Key** and computes an **index** (a hash value) within the array of buckets where the corresponding **Value** should be stored.

### The Hashing Process  

**Hashing** is a process that converts an input of arbitrary size (such as a string, file, or object) into a fixed-size value, called a hash value, hash code, or simply a hash.

1.  **Input:** A key (e.g., `"apple"`).
2.  **Hash Function:** The key is passed to the hash function: `hash_function("apple")`.
3.  **Output:** The function returns an integer index (e.g., `5`).
4.  **Storage/Retrieval:** The value associated with `"apple"` is stored in (or retrieved from) the array at index `5`.

## Collision Resolution

A **collision** occurs when two different keys hash to the *same* array index. Since the hash function maps a virtually infinite set of possible keys to a finite number of buckets, collisions are inevitable.

Common methods to resolve collisions include:

* **Open Hashing**
    * **Chaining:** Storing a linked list of all key-value pairs at the colliding index.  
* **Close Hashing**
    * **Open Addressing (Probing):** Searching for the next available empty slot in the array if the initial calculated index is already occupied.
        * Linear Probing
        * Quadratic Probing
        * Double Hashing  

    * **Linear Probing** - It is one of the open addressing technique for solving the collision resolution . 
        - In linear probing it check for the next free space linearly, and the function look like : 
        - $h(x) = (h(key) + f(i))$, where $i=$ 0,1,2,3,4 ...  
        - In this linear probing the searching is quite expensive then $O(1)$, becauae if the key is not found at index we have to move to the next index until we found the key or the next space is free . If we found the next step is free then it means that the key is not present .  
        - And also the loding factor ($\lambda <= 0.5$).
        - And the deletion is not suggesable in linear probing because it comes with too many complications. 
        - Time Complexity :  
            - Avg Successfull Search = $Psuccessfull ≈ \frac{1}{2} (1+\frac{1}{1-\lambda})$
            - Avg Unsuccessful Search = $Punsuccessful ≈ \frac{1}{2} (1+\frac{1}{(1-\lambda)^2})$

    * **Quadratic Probing** : There is a drawback in linear probing and that is, the key's form a cluster or say key's are accumulating at the same space. And also another disadvantage in linear probing is space westage, because loding factor ($\lambda <= 0.5$), then there must be $\frac{n}{2}$ free spaces . And this is for efficient searching . 
    - This is why for avoiding this problem there is another method called **quadratic probing** and this method also store the element in the next free space but the calculation of the next free space is quite difference from linear probing.  


## Common Applications of Hashing

| Application | Role of Hashing |
| :--- | :--- |
| **Databases** | Used for **indexing** data to provide near-instantaneous record lookups. |
| **Security/Cryptography** | Used for creating fixed-size **checksums** (message digests) to verify data integrity and for secure password storage. |
| **Caches** | Mapping frequently accessed data to memory locations for fast access. |
| **Programming Languages**| Powering built-in data structures like **Dictionaries** (Python), **Maps** (Go/C++), and **Objects** (JavaScript). |

## Time Complexity (Big O Notation)

| Operation | Average Case | Worst Case |
| :--- | :--- | :--- |
| **Insertion** | $O(1)$ | $O(n)$ |
| **Deletion** | $O(1)$ | $O(n)$ |
| **Search** | $O(1)$ | $O(n)$ |

> **Note:** The worst-case complexity occurs when all keys collide and end up in a single bucket, essentially degrading the hash table into a linked list. A good hash function is crucial to minimize collisions and maintain $O(1)$ performance.