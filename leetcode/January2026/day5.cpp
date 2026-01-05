/**
 * Maximum Matrix Sum
 * Question Link : https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05
 * Solution Link : 
 */

// You are given an n x n integer matrix. You can do the following operation any number of times:
// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.
// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

// Example 1:

// Input: matrix = [[1,-1],[-1,1]]
// Output: 4
// Explanation: We can follow the following steps to reach sum equals 4:
// - Multiply the 2 elements in the first row by -1.
// - Multiply the 2 elements in the first column by -1.

// Example 2:

// Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
// Output: 16
// Explanation: We can follow the following step to reach sum equals 16:
// - Multiply the 2 last elements in the second row by -1.

// Constraints:

//     n == matrix.length == matrix[i].length
//     2 <= n <= 250
//     -105 <= matrix[i][j] <= 105

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long sum = 0;
        int count = 0;
        int mini = 1e9;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] < 0) {
                    count++;
                }
                mini = min(mini, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }

        if (count % 2 == 1) {
            sum -= (2 * mini);
        }

        return sum;
    }
};

int main() {
    Solution S;
    vector<vector<int>> matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};
    cout << "Maximum Sum is : " << (S.maxMatrixSum(matrix)) << endl;  // 16
    return 0;
}
 