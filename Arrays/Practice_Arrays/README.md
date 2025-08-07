# Question Based On Arrays  

In this section we'll look into various types of problems which is based on arrays.  

## Top Question  

**Easy Problems**

-   [Second Largest Element](#second-largest-element)
-   [Third Largest Element](#third-largest-element)
-   [K-th Largest Element](#k-th-largest-element)
-   [Three Great Candidates](#three-great-candidates)








### Second Largest Element  

We have an array of positive integers, and we have to find $2^{nd}$ largest element in the arrays . And if you don't find the element then return -1.

**Example:**  
```cpp
Input : A[] = [11, 44, 32, 54, 32, 89]  
O/P : 54

Input : A[] = [99, 99, 99]  
O/P : -1  
```

___Solution Approach___  
We have to variable `max` and `secMax` and both assign with `-1` value.  
Now run a loop from `0` to `n-1` and check the following conditions  
-   ```cpp
    if A[i] > first 
        secMax = first;
        first = A[i];
    else if A[i] > secMax && A[i] < first
        secMax = A[i]
    ```

Now finally return secMax. 

**Time Complexity :** = O(n)  
**Space Complexity :** = O(1)  

***[Check Out The Solution Code](./secondLargestElement.cpp)*** 

### Third Largest Element  
We have a given array of n integers, we have to find the third largest element. All the elements in the array are distinct integers. 

**Example :**  
```cpp
Input: arr[] = {1, 14, 2, 16, 10, 20}  
O/P: 14  

Largest element = 20, Second Largest Element = 16 & Third Largest Element = 14  

Input: arr[] = {19, -10, 20, 14, 2, 16, 10}  
O/P: 16  

Largest Element = 20, Second Largest Element = 19, Third Largest Element = 16  
```

_**We can solve this question with three different approach:**_  
1. First sort the array and get the third element from end of the array, 

    -   If **n** is the size, the after sort, third element will be **A[n-3]**
    -   **Time Complexity :** _O(n* log(n))_
    -   **Space Complexity :** _O(1)_

2. Using Three Different Loop We Can Calculate The Largest Loop,

    - In first loop, we get first largest element .
    - In seconf loop, we get second largest element .
    - In third loop, we get third largest element .
    - **Time Complexity :** O(n)
    - **Space Complexity :** O(1)

3. Using three different variable, in a single loop we can solve this question.

    - We have three variable **first, second & third**  and all are assign to min value .
    - run a loop from 0 to n-1 . _n is the size of the array_ 
    - now we have to check the condition for getting ___third largest element___.  
        ```cpp
        if A[i] > first
            third = second
            second = first
            first = A[i]
        
        else if A[i] > second
            third = second
            second = A[i]

        else if A[i] > third-   [K-th Largest Element](#k-th-largest-element)
            third = A[i]
        ```

4. Now **return third** variable.    

_**[See The Solution Code In Different Approach](./thirdLargestElement.cpp)**_  

### K-th Largest Element  
We have an array of integers of **n** size and an integer **k**, now we have to find $K^{th}$ largest element. 

Note that it is the $K^{th}$ largest element in the sorted order, not the $K^{th}$ distinct element .  

**_<a href="https://leetcode.com/problems/kth-largest-element-in-an-array/description/" target="_blank">Let's Code In LeetCode</a>_**

```cpp
I/P: nums = [3,2,1,5,6,4], k = 2  
O/P: 5  

I/P: nums = [3,2,3,1,2,4,5,5,6], k = 4  
O/P: 4  
```
_**[Find The Solution Code](./Kth_LargestElement.cpp)**_

### Three Great Candidates  