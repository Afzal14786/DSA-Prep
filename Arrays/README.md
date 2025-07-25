# Arrays

Welcome to the **Arrays** section of our DSA repository! This `README.md` file is designed to help you grasp the core concepts of arrays and explore a collection of problems with their implemented solutions.

---

Below, you'll find various array topics. Each section offers a deeper dive into the concept, accompanied by relevant problems and their solutions for hands-on learning.  

### Arrays  
An array is a fundamental data structure in computer science, used to store a **collection of items**, often of the **same data type**, in a contiguous block of memory. Think of it as a list or a sequence of elements. Each element in an array is identified by an index or subscript, which specifies its position within the array.  

Key characteristics of arrays:

* **Fixed Size (often):** In many programming languages, once an array is created, its size is fixed. This means you cannot easily add or remove elements beyond its declared capacity.

* **Contiguous Memory Allocation:** Elements are stored next to each other in memory, which allows for very efficient access to any element using its index.

* **Zero-Based Indexing (common):** Most programming languages use zero-based indexing, meaning the first element is at index 0, the second at 1, and so on.  

Arrays are incredibly versatile and are used as the basis for many other data structures like **stacks**, **queues**, and sometimes even **strings**.  

### Types of Arrays  
Arrays can be classified by their dimensionality, which refers to the number of indices needed to access an element.  

**1. One-Dimensional (1D) Arrays**  
A one-dimensional (1D) array is the simplest form of an array. It represents a linear list of elements. You need only one index to pinpoint an element.  

**Analogy:** A single row of lockers, where each locker has a unique number.

**Example:**  
If you have an array arr = [10, 20, 30, 40, 50]:  
* `arr[0] is 10`
* `arr[1] is 20`
* `arr[2] is 30`
* `arr[3] ...`
* `arr[4] is 50`  

You can explore more about 1D arrays and questions based on it on [/Arrays](./1DArray/README.md) folder.  

**2. Two-Dimensional (2D) Arrays**  
A **two-dimensional (2D) array** is an array of arrays. It represents a grid or a table of elements, often visualized as rows and columns. To access an element, you typically need two indices: one for the row and one for the column.  

**Analogy:** A chessboard or a spreadsheet, where you specify both the row and column to find a cell.  

**Example:**  
If we have a 2D array `matrix`  
```matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
```
* `matrix[0][0] is 1 (first row & first column)`
* `matrix[0][1] is 2 (first row & second column)`
* `matrix[0][2] is 3 (first row & third column)`
* `and so on ...`   

**3. N-Dimensional (ND) Arrays**  
An **N-dimensional (ND) array** is a generalization of 1D and 2D arrays. It can have any number of dimensions (N). To access an element in an ND array, you need `N` indices. While 1D and 2D arrays are common in everyday programming, higher-dimensional arrays (like 3D for spatial data or images) are also used in specialized fields like scientific computing, image processing, and machine learning.  

**Analogy:**  
* A 3D array could represent a stack of 2D matrices (like layers in a Rubik's Cube), requiring three indices (e.g., `[layer][row][column]`).  

* A 4D array might represent a series of 3D objects over time (e.g., `[time][layer][row][column]`).  


### Other Topics In Arrays  
* **Vectors (Dynamic Arrays):** In languages like C++ are dynamic arrays that can grow or shrink in size, abstracting away the fixed-size limitation of traditional arrays. You can explore this in the [/Vectors](./Vector/) folder.  

* **Questions:** A dedicated folder for various array-based problems and their solutions to help you practice and solidify your understanding. You can find these in the [/Questions](./Questions/README.md) as well as for 2D arrays you can find in the [/2DArrays](./2DArray/README.md) folder.  


