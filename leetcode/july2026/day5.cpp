/*
 *  PROBLEM: Number of Paths with Max Score
 *  ----------------------------------------------------------------
 *  You are given a square board of characters (n x n).
 *  - Start at the bottom‑right square marked 'S'.
 *  - Target is the top‑left square marked 'E'.
 *  - Other cells contain digits '1'..'9' (collectible scores) or obstacle 'X'.
 *  - Moves allowed: up (i-1, j), left (i, j-1), up‑left (i-1, j-1), 
 *    provided the target cell is not an obstacle.
 *
 *  Goal: Return [maxSum, pathCount] where:
 *    - maxSum = maximum total sum of numeric characters collected along a valid path.
 *    - pathCount = number of distinct paths that achieve that maxSum (mod 1e9+7).
 *    - If no path exists, return [0, 0].
 *
 *  Example 1:
 *    board = ["E23","2X2","12S"]  →  [7, 1]
 *  Example 2:
 *    board = ["E12","1X1","21S"]  →  [4, 2]
 *  Example 3:
 *    board = ["E11","XXX","11S"]  →  [0, 0]
 *
 *  Constraints: 2 ≤ n ≤ 100.
 *  ----------------------------------------------------------------
 * 
 */

/**
 * @see https://leetcode.com/problems/number-of-paths-with-max-score/description/?envType=daily-question&envId=2026-07-05
 */

#include <vector>
#include <string>
#include <utility>
using namespace std;

// APPROACH 1: TOP‑DOWN (MEMOIZED DFS)
class Solution {
private:
    int n;
    const int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>> memo;   // memo[i][j] = {bestScore, ways} from (i,j) to 'E'
    
    // Helper: numeric value of a character (0 for 'S' and 'E')
    int charValue(char c) {
        if (c == 'S' || c == 'E') return 0;
        return c - '0';
    }
    
    // Helper: check if cell is inside board and not an obstacle
    bool isSafe(int i, int j, const vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }
    
    // DFS from cell (i, j) to (0,0) = 'E'
    pair<int,int> dfs(int i, int j, const vector<string>& board) {
        // Base: reached target 'E'
        if (board[i][j] == 'E') {
            return {0, 1};          // score 0, exactly one empty path
        }
        // If obstacle (should not happen due to isSafe) or already computed
        if (board[i][j] == 'X' || memo[i][j] != make_pair(-1, -1)) {
            return memo[i][j];
        }
        
        int bestScore = -1;
        int bestWays = 0;
        int currentValue = charValue(board[i][j]);
        
        // Try all three possible predecessor cells (up, left, up‑left)
        vector<pair<int,int>> predecessors = {{i-1, j}, {i, j-1}, {i-1, j-1}};
        for (auto [pi, pj] : predecessors) {
            if (!isSafe(pi, pj, board)) continue;
            
            auto [prevScore, prevWays] = dfs(pi, pj, board);
            if (prevWays == 0) continue;          // no path from that predecessor
            
            int candidateScore = prevScore + currentValue;
            if (candidateScore > bestScore) {
                bestScore = candidateScore;
                bestWays = prevWays;
            } else if (candidateScore == bestScore) {
                bestWays = (bestWays + prevWays) % MOD;
            }
        }
        
        // Store result (if no path found, stays { -1, -1 } but we return {0,0} later)
        return memo[i][j] = (bestWays > 0) ? make_pair(bestScore, bestWays) : make_pair(0, 0);
    }
    
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        memo.assign(n, vector<pair<int,int>>(n, {-1, -1}));
        
        auto [maxSum, ways] = dfs(n-1, n-1, board);   // start at 'S'
        return {maxSum, ways};
    }
    /*
     * Time Complexity  : O(n²) – each cell is computed once.
     * Space Complexity : O(n²) – for memo table and recursion stack.
     */
};

// APPROACH 2: BOTTOM‑UP (TABULATION)
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = (int)board.size();
        
        // dp[i][j] = {bestScore, ways} from (i,j) to 'E'
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {0, 0}));
        
        // Base: target cell 'E' – empty path with sum 0, one way
        dp[0][0] = {0, 1};
        
        // Helper: numeric value of a cell
        auto cellValue = [&](int i, int j) -> int {
            char c = board[i][j];
            return (c == 'S' || c == 'E') ? 0 : c - '0';
        };
        
        // Helper: cell is inside board and not obstacle
        auto isValid = [&](int i, int j) -> bool {
            return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
        };
        
        // Process cells in increasing order (moves are from larger indices to smaller)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip 'E' (already set) and obstacles
                if (board[i][j] == 'E' || board[i][j] == 'X') continue;
                
                int bestScore = -1;
                int bestWays = 0;
                int currentVal = cellValue(i, j);
                
                // Try coming from up, left, up‑left
                vector<pair<int,int>> predecessors = {{i-1, j}, {i, j-1}, {i-1, j-1}};
                for (auto [pi, pj] : predecessors) {
                    if (!isValid(pi, pj)) continue;
                    
                    int prevScore = dp[pi][pj].first;
                    int prevWays  = dp[pi][pj].second;
                    if (prevWays == 0) continue;        // predecessor not reachable
                    
                    int candidate = prevScore + currentVal;
                    if (candidate > bestScore) {
                        bestScore = candidate;
                        bestWays = prevWays;
                    } else if (candidate == bestScore) {
                        bestWays = (bestWays + prevWays) % MOD;
                    }
                }
                
                // Store only if reachable; otherwise stays {0,0} (unreachable)
                if (bestWays > 0) {
                    dp[i][j] = {bestScore, bestWays};
                }
            }
        }
        
        // Answer is at bottom‑right (start cell 'S')
        return {dp[n-1][n-1].first, dp[n-1][n-1].second};
    }
    /*
     * Time Complexity  : O(n²) – iterates over all cells once.
     * Space Complexity : O(n²) – for the DP table.
     */
};