# Question Based On Arrays  

In this section we'll look into various types of problems which is based on arrays.  

## Top Question  

**Easy Problems**

-   [Second Largest Element](#second-largest-element)








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

***Checkout the solution code***  [solution code](./secondLargestElement.cpp)  
