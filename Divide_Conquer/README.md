# Divide & Conquer Algorithm  

### Divide and Conquer is an algorithm technique for solving a problem.  

`Divide and Conquer Algorithm first divide a Big problem into sub problems until the sub problem is small enougf to solve it . If the sub-problem is also big then the sub problem is also divided into sub-sub problem and we'll find the solution for this.`  


_Divide and conquer algorithm is used `recursion`  for solving a particular problem._  

**We can only apply divide and conquer algorithm when the problem statement of the sub-problem is remain same then it divides the problem into sub-problems.**  

**We must have a base case, while applying the divide and conquer algorithm.**  

**Example on Divide & Conquer Algorithm :**  

****  
**Question 1 :** _`Binary Search Using Divide & Conquer Algorithm`_  

```cpp
// Binary Search
int BinarySearch(vector<int> &nums, int start, int end, int target) {
    // base case 
    if (start > end) {
        return -1;  // means the target element is not found .
    }

    int mid = start + (end - start)/2;  // calculate the mid

    if (nums[mid] == target) {  // target found
        return mid; // return the index where target is found
    }

    if (nums[mid] > target) {
        // binary Search From start to mid-1
        return BinarySearch(nums, start, mid-1, target);
    } else {
        // binary search from mid+1 to end
        return BinarySearch(nums, mid+1, end, target);
    }
}
```

**Question 2:** _`Merge Sort -Divide & Conquer`_  
We can merge two sorted using **Divide & Conquer Approach**.  

**In merge sort we use two functions** one for `merge two sorted array` and another one function is used to `sorting the arrays`.  



