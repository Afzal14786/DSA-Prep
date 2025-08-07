# Question Based On Arrays  

In this section we'll look into various types of problems which is based on arrays.  

## Top Question  

**Easy Problems**

-   [Second Largest Element](#second-largest-element)
-   [Third Largest Element](#third-largest-element)
-   [Three Great Candidates](#three-great-candidates)








### Second Largest Element  

We have an array of positive integers, and we have to find $2^{nd}$ largest element in the arrays . And if you don't find the element then return -1.

**Example:**  
**Input :** _**A[] = [11, 44, 32, 54, 32, 89]**_  
**O/P :** _**54**_  

**Input :** _**A[] = [99, 99, 99]**_  
**O/P :** _**-1**_  


___Solution Approach___  
We have to variable `max` and `secMax` and both assign with `-1` value.  
Now run a loop from `0` to `n-1` and check the following conditions

    if A[i] > max 
        secMax = max
        max = A[i]
    
    else if A[i] < max && A[i] > secMax 
        secMax = A[i]

Now finally return secMax. 

**Time Complexity :** = O(n)  
**Space Complexity :** = O(1)  

***[Check Out The Solution Code](./secondLargestElement.cpp)*** 

### Third Largest Element  
We have a given array of n integers, we have to find the third largest element. All the elements in the array are distinct integers. 

**Example :**  
**Input:** _arr[] = {1, 14, 2, 16, 10, 20}_  
**O/P:** _14_  
Largest element = 20, Second Largest Element = 16 & Third Largest Element = 14  

**Input:** _arr[] = {19, -10, 20, 14, 2, 16, 10}_  
**O/P:** _16_  
Largest Element = 20, Second Largest Element = 19, Third Largest Element = 16  


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
        ```
        if A[i] > first
            third = second
            second = first
            first = A[i]
        
        else if A[i] > second
            third = second
            second = A[i]

        else if A[i] > third
            third = A[i]
        ```

4. Now **return third** variable.    

_**[See The Solution Code In Different Approach](./thirdLargestElement.cpp)**_  

### Three Great Candidates