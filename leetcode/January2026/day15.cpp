/**
 * Maximize Area Of Square Hole In Grid
 * Question Link : https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/?envType=daily-question&envId=2026-01-15
 * Solution Link : https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/submissions/1885506511/?envType=daily-question&envId=2026-01-15
 */

// You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.
// You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.
// Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).

// Example 1:

// Input: n = 2, m = 1, hBars = [2,3], vBars = [2]
// Output: 4

// Explanation:
// The left image shows the initial grid formed by the bars. The horizontal bars are [1,2,3,4], and the vertical bars are [1,2,3].
// One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.

// Example 2:

// Input: n = 1, m = 1, hBars = [2], vBars = [2]
// Output: 4

// Explanation:
// To get the maximum square-shaped hole, we remove horizontal bar 2 and vertical bar 2.

// Example 3:

// Input: n = 2, m = 3, hBars = [2,3], vBars = [2,4]
// Output: 4

// Explanation:
// One way to get the maximum square-shaped hole is by removing horizontal bar 3, and vertical bar 4.

// Constraints:

//  1 <= n <= 10^9
//  1 <= m <= 10^9
//  1 <= hBars.length <= 100
//  2 <= hBars[i] <= n + 1
//  1 <= vBars.length <= 100
//  2 <= vBars[i] <= m + 1
//  All values in hBars are distinct.
//  All values in vBars are distinct.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(int n, vector<int> &bars) {
        int ans = 2;
        sort(bars.begin(), bars.end());
        int count = 1;
        for (int i = 1; i < bars.size(); ++i) {
            if (bars[i] - bars[i - 1] == 1) {
                count++;
                ans = max(ans, count + 1);
            } else {
                count = 1;
            }
        }

        if (count == 1 && bars.back() == n - 1) {
            count++;
            ans = max(ans, count);
        }

        return ans;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int X = maxArea(n, hBars), Y = maxArea(m, vBars);
        int side = min(X, Y);
        int area = side * side;
        return area;
    }
};