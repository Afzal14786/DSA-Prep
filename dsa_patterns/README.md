# DSA Patterns  
This folder will contain all the important DSA patterns with practice question and their solution using `C++` . 

### Table of contents  

-   [Two Pointers](#two-pointers)
-   [Fast & Slow Pointer](#slow-and-fast-pointers)


### Two Pointers  

Two pointers is a technique in which two indices are used to iterate over a data structure (like array or string) to solve problem efficiently by avoiding nested loops.  

**When to use two pointers**  
-   When need to find pairs, triplates or subarrays meeting certain conditions
-   When the data is sorted and can be sorted
-   To optimize the burte force solutions that use nested loop $O(n^2)$ to linear or near to liner time complexity $O(n)$.  

**How it works ?**  

Maintain two pointers that moves through the given data structure according to certain rules: 
-   One pointer start at the beginning of the data structure or another pointer at the end of the data structure . **_(Common in problems like finding the pair with a sum)_**  
-   Or in some cases both the pointers start at the beginning of the data structure, where one pointer moves slow and another one is moving faster . e.g : pointer1 moves by speed `x` and pointer2 moves by speed `2x` . ***(Useful for sliding window problem)***  

-   Moves pointers towards each other or move depending on the problem conditions.  

#### Typically Approach !  
1. Initialize the pointers `left` & `right`.
2. Check the condition based on the current pointers.
3. Moves the pointers accordingly...
    * If the condition met, then hold the answer and move the pointers.
    * if the condition not met. then move the left or right pointer to met the condition.  
4. Repeate until the pointer cross or reach the end of the give data structure.  

### Question Based On Two Pointers !

1. [Two Sum II Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)  
    * Solution
    ```cpp
        class Solution {
        public:
            vector<int> twoSum(vector<int>& numbers, int target) {
                vector<int> ans;
                int i = 0, j = numbers.size()-1;

                while (i < j) {
                    int currSum = numbers[i] + numbers[j];
                    if (currSum == target) {
                        ans.push_back(i+1);
                        ans.push_back(j+1);
                        return ans;
                    }

                    if (currSum > target) {
                        --j;
                    } else {
                        ++i;
                    }
                }

                return {};
            }
        };
    ```
2. [Remove Duplicates From Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
    * Solution:
    ```cpp
        class Solution {
            public:
            int removeDuplicates(vector<int>& nums) {
                int n = nums.size();
                int j = 1;
                for (int i = 1; i< n; ++i) {
                    if (nums[i] != nums[j-1]) {
                        nums[j] = nums[i];
                        j++;
                    }
                }

                return j;
            }
        };
    ```  

3. [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
    * Solution
    ```cpp
    class Solution {
    public:
        bool isPalindrome(string s) {
            if (s.empty()) {
                return true;
            }
            string str;
            // remove the unwanted characters & convert into lower case
            for (char ch : s) {
                // check the character is number or an unwanted character
                if (isalpha(static_cast<unsigned char>(ch)) || isdigit(static_cast<unsigned char>(ch))) {

                    str += tolower(ch);
                }
            }

            int i = 0, j = str.size()-1;
            while (i <= j) {
                if (str[i] != str[j]) return false;
                i++;
                j--;
            }
            return true;
        }
    };
    ```  

4. [Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/)
    * Solution
    ```cpp
    class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0, right = height.size()-1;
            int maxWater = 0;

            while (left < right) {
                int w = right - left;
                int h = min(height[left], height[right]);
                int area = w * h;
                maxWater = max(maxWater, area);

                if (height[left] < height[right]) {
                    left++;
                } else {
                    right--;
                }
            }

            return maxWater;
        }
    };
    ```

### Slow And Fast Pointers  

The slow and fast pointer (also known as floyd's cycle detection or the tortoise and hare technique) is a two pointer strategy used to efficient traverse data structure where : 
-   Element are connected in a sequence (e.g: linked list, number transformation, circular array).
-   We move step by step through the data structure.

We use: 
-   **slow pointer :** move 1 step at 1 time
-   **fast pointer :** move 2 step at 1 time

### Where is this pattern useful?  

This pattern is typically used in problem involving
-   cycle detection (in linked list, number sequence etc)
-   finding the middle of a list
-   detecting palindrome in a linked list
-   Maths based problems that create a repetitive cycle (i.e: Happy Number)

### How To Recognize When To Apply Slow And Fast Pointers?  

#### Look for the Following Patterns

- **Repetitions** – The problem involves repeatedly transforming values (e.g., traversing a linked list, computing the square sum of digits).  
- **Cycle Possibility** – The data structure or transformation could form a loop (e.g., a cycle in a linked list or a repeating sequence in a number chain).  
- **Need for Midpoint** – The task requires finding the middle point in a single pass.  
- **O(1) Space Requirement** – The solution must use constant space; slow and fast pointers are preferred over extra memory or data structures.  

### How to Apply the Pattern Step by Step

**Step 1: Initialize Two Pointers**  
- Set `slow = head`  
- Set `fast = head`  

**Step 2: Traverse the Data Structure**  
- Move `slow` one step at a time  
- Move `fast` two steps at a time  

```cpp
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}
```  

**Step 3: Observe the Meeting Point**  
- If `slow == fast` → A cycle exists (useful for cycle detection problems).  
- If `fast` reaches `null` → No cycle exists (the traversal has ended).  
- This step helps determine whether further logic is needed based on the problem type.  

**Step 4: Apply Specific Logic Based on the Goal**  

- **Finding Cycle Start**:  
  1. Reset `slow` to the head of the list.  
  2. Move both `slow` and `fast` one step at a time.  
  3. When `slow == fast` again, this is the starting node of the cycle.  

- **Finding the Middle of a Linked List**:  
  1. Keep moving `slow` one step and `fast` two steps.  
  2. When `fast` reaches the end (`null`), `slow` will be at the middle.  

- **Detecting Cycle in Transformations (e.g., Happy Numbers)**:  
  1. Treat the transformation function as the "next" step.  
  2. Apply the same slow/fast pointer logic to detect loops.  
  3. If a cycle is detected, it indicates a repeating sequence; otherwise, the sequence terminates.    

### Benefits of Slow and Fast Pointers

| Benefit          | Explanation                                                   |
|-----------------|---------------------------------------------------------------|
| O(n) Time        | Linear traversal; no nested loops.                            |
| O(1) Space       | Only two pointers used; no hashmaps or additional data structures. |
| No Modification  | Works on the original structure without altering it.         |


### Example Use Case Pattern

| Use Case           | Problem Type         | What to Observe / Steps                                                   |
|-------------------|--------------------|---------------------------------------------------------------------------|
| Detect Cycle       | Linked List         | Traverse nodes; check if `slow == fast`.                                  |
| Find Loop Start    | Linked List         | After `slow` and `fast` meet, move `slow` to head; traverse to find start.|
| Find Middle        | Linked List         | Move `fast` 2 steps and `slow` 1 step; stop when `fast == null`.         |
| Happy Number       | Integer Problem     | Apply the next-transform function repeatedly until loop or 1 is found.   |
| Circular Array Loop| Array + Modulo (%)  | Move with `(i + nums[i]) % n`; detect cycles using the cycle logic.      |
