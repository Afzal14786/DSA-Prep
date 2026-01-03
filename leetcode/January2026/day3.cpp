/**
 * Number of ways to paint N * 3 Grid
 * Question Link : https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-01-03
 * Solution Link : https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/?envType=daily-question&envId=2026-01-03
 */

// Question 

// You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

// Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

// Example 1 : 

// Input: n = 1
// Output: 12
// Explanation: There are 12 possible way to paint the grid as shown.

// Example 2:

// Input: n = 5000
// Output: 30228214

// Constraints:

// n == grid.length

// 1 <= n <= 5000

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;
    int numOfWays(int n) {
        long long twoColor = 6;
        long long threeColor = 6;

        for (int i = 1; i < n; ++i) {
            long long nextTwoColor = (3 * twoColor + 2 * threeColor) % MOD;
            long long nextThreeColor = (2 * twoColor + 2 * threeColor) % MOD;

            twoColor = nextTwoColor;
            threeColor = nextThreeColor;
        }

        return (twoColor + threeColor) % MOD;
    }
};


int main() {
    Solution s;
    cout << "Total No Of Ways : " << ((s.numOfWays(1))) << endl;
    cout << "Total No Of Ways : " << ((s.numOfWays(5000))) << endl;
    return 0;
}