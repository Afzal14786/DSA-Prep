// A square triple (a,b,c) is a triple where a, b, and c are integers and a^2 + b^2 = c^2.

// Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: The square triples are (3,4,5) and (4,3,5).

// Example 2:

// Input: n = 10
// Output: 4
// Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).

// Constraints:

//     1 <= n <= 250

// Question Link : https://leetcode.com/problems/count-square-sum-triples/description/?envType=daily-question&envId=2025-12-08
// Solution Link : 

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                int c = sqrt(a*a + b*b);
                if (c <= n && c * c == (a*a + b * b)) count++;
            }
        }

        return count;
    }
};

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int c = 1; c <= n; ++c) {
            int target = c * c;
            int left = 1;
            int right = c-1;

            while (left < right) {
                int currSum = left * left + right * right;
                if (currSum == target) {
                    count += 2;
                    left++;
                    right--;
                } else if (currSum < target) left++;
                else if (currSum > target) right--;
            }
        }
        return count;
    }
};