// There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

// Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

// You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

// Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

// Example 1:

// Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
// Output: 2
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 2.

// Example 2:

// Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
// Output: 1
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 1.

// Example 3:

// Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
// Output: 3
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 3.

// Constraints:

//     2 <= row, col <= 2 * 10^4
//     4 <= row * col <= 2 * 10^4
//     cells.length == row * col
//     1 <= ri <= row
//     1 <= ci <= col
//     All the values of cells are unique.

// Question Link : https://leetcode.com/problems/last-day-where-you-can-still-cross/?envType=daily-question&envId=2025-12-31

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        vector<vector<int>> vis(row, vector<int>(col, 0));

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        queue<pair<int, int>> q;

        for (int i = 0; i < col; i++) {
            if(grid[0][i]==0)
            q.push({0, i});
        }

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;

            if(r==row-1){
                return true;
            }
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = r +dx[k];
                int ncol = c + dy[k];

                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && !vis[nrow][ncol] && grid[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int low =0;
        int high = cells.size();
        int ans =0;

        while(low<=high){
            int mid =(low +high)/2;

            if(check(mid,row,col,cells)){
                ans =max(ans,mid);
                low =mid+1;
            }else{
                high =mid-1;
            }
        }

        return ans;
    }
};