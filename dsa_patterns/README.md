# DSA Patterns  
This folder will contain all the important DSA patterns with practice question and their solution using `C++` . 

### Table of contents  

-   [Two Pointers](#two-pointers)


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

