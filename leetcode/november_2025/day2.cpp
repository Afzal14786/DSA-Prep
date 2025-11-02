// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

// Return the number of unoccupied cells that are not guarded.

// Example 1:
// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
// Output: 7
// Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
// There are a total of 7 unguarded cells, so we return 7.

// Example 2: 
// Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
// Output: 4
// Explanation: The unguarded cells are shown in green in the above diagram.
// There are a total of 4 unguarded cells, so we return 4.

//  Constraints:

//     1 <= m, n <= 105
//     2 <= m * n <= 105
//     1 <= guards.length, walls.length <= 5 * 104
//     2 <= guards.length + walls.length <= m * n
//     guards[i].length == walls[j].length == 2
//     0 <= rowi, rowj < m
//     0 <= coli, colj < n
//     All the positions in guards and walls are unique

// Solution : 

// Question Link :  https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2025-11-02

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = empty, 1 = guard, 2 = wall, 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark walls
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        
        // Mark guards
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        
        // Directions: up, right, down, left
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // For each guard, propagate vision in 4 directions
        for (auto& guard : guards) {
            int r = guard[0], c = guard[1];
            
            for (auto& dir : directions) {
                int dr = dir.first, dc = dir.second;
                int nr = r + dr, nc = c + dc;
                
                // Keep going until we hit boundary, wall, or guard
                while (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                       grid[nr][nc] != 2 && grid[nr][nc] != 1) {
                    // Mark as guarded (if not already a guard/wall)
                    grid[nr][nc] = 3;
                    
                    // Move to next cell in this direction
                    nr += dr;
                    nc += dc;
                }
            }
        }
        
        // Count unguarded empty cells (value = 0)
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};