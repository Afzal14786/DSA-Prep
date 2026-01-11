/**
 * Maximum Rectangle
 * Question Link : https://leetcode.com/problems/maximal-rectangle/solutions/?envType=daily-question&envId=2026-01-11
 * Solution Link : https://leetcode.com/problems/maximal-rectangle/submissions/1881424191/?envType=daily-question&envId=2026-01-11
 */

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

// Example 2:

// Input: matrix = [["0"]]
// Output: 0

// Example 3:

// Input: matrix = [["1"]]
// Output: 1

// Constraints:

//   rows == matrix.length
//   cols == matrix[i].length
//   1 <= rows, cols <= 200
//   matrix[i][j] is '0' or '1'.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> prev(vector<int> &height) {
        int n = height.size();
        vector<int> prevSmaller(n, -1);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (s.size() > 0 && height[s.top()] >= height[i])  {
                s.pop();
            }

            if (s.size() != 0) {
                prevSmaller[i] = s.top();
            }

            s.push(i);
        }
        return prevSmaller;
    }

    vector<int> next(vector<int> &height) {
        int n = height.size();
        vector<int> nextSmaller(n, n);

        stack<int> s;

        for (int i = n - 1; i >= 0; --i) {
            while (s.size() > 0 && height[s.top()] >= height[i]) s.pop();
            if (s.size() != 0) {
                nextSmaller[i] = s.top();
            }
            s.push(i);
        }
        return nextSmaller;
    }

    int max_area(vector<int> &height) {
        int n = height.size();
        vector<int> prevSmaller = prev(height);
        vector<int> nextSmaller = next(height);

        int maxi = 0;

        for (int i = 0; i < n; ++i) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            maxi = max(maxi, width * height[i]);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> pre(m, 0);
        vector<int> curr(m, 0);
        int maxi = 0;

        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                for (int j = 0; j < m; ++j) {
                    if (matrix[i][j] == '0') curr[j] = 0;
                    else curr[j] = 1 + pre[j];
                }
            } else {
                for (int j = 0; j < m; ++j) {
                    pre[j] = matrix[i][j] - '0';
                }
            }

            if (i == 0) {
                maxi = max(maxi, max_area(pre));
            } else {
                maxi = max(maxi, max_area(curr));
            }

            if (i != 0) {
                pre = curr;
            }
        }

        return maxi;
    }
};