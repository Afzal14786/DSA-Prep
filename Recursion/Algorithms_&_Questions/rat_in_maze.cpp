// Question Link : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Question Link : https://www.naukri.com/code360/problems/rat-in-a-maze-all-paths

#include <iostream>
#include <vector>
#include <string>

class Solution {
  public:
    void solve(int i, int j, std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>> &visited, const std::string &move, std::vector<std::string> &ans) {
        int n = maze.size();
        // base case 
        if (i == n-1 && j == n-1) {
            ans.push_back(move);
            return;
        }

        // go down
        if (i+1 < n && !visited[i+1][j] && maze[i+1][j] == 1) {
            visited[i][j] = true;
            solve(i+1, j, maze, visited, move + 'D', ans);
            visited[i][j] = false;
        }

        // go left 
        if (j-1 >= 0 && !visited[i][j-1] && maze[i][j-1] == 1) {
            visited[i][j] = true;
            solve(i, j-1, maze, visited, move + 'L', ans);
            visited[i][j] = false;
        }

        // go right 
        if (j+1 < n && !visited[i][j+1] && maze[i][j+1] == 1) {
            visited[i][j] = true;
            solve(i, j+1, maze, visited, move + 'R', ans);
            visited[i][j] = false;
        }

        // go up
        if (i-1 >= 0 && !visited[i-1][j] && maze[i-1][j] == 1) {
            visited[i][j] = true;
            solve(i-1, j, maze, visited, move + 'U', ans);
            visited[i][j] = false;
        }
    }

    /**
     * Another better code comparision in just one if statement 
     */

    void solve2(int i, int j, std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>> visited, const std::string &move, std::vector<std::string> &ans, std::vector<int> &di, std::vector<int> &dj){
        int n = maze.size();
        if (i == n-1 && j == n-1) {
            ans.push_back(move);
            return;
        }

        std::string direction = "DLRU";
        for (int idx = 0; idx < 4; ++idx) {
            int nextI = i + di[idx];
            int nextJ = j + dj[idx];

            if (nextI >= 0 && nextJ >= 0 && nextI < n && nextJ < n && !visited[nextI][nextJ] && maze[nextI][nextJ] == 1) {
                visited[i][j] = true;
                solve2(nextI, nextJ,maze, visited, move + direction[idx], ans, di, dj);
                visited[i][j] = false;
            }
        }
    }

    std::vector<std::string> ratInMaze(std::vector<std::vector<int>>& maze) {
        // code here
        int n = maze.size();
        std::vector<std::string> ans;

        if (n == 0 || maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

        std::vector<int> di = {+1, 0, 0, -1};
        std::vector<int> dj = {0, -1, 1, 0};

        solve2(0,0, maze, visited, "", ans, di, dj);
        return ans;
    }
};