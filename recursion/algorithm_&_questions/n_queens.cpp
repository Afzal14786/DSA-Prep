// Question Link : https://leetcode.com/problems/n-queens/

#include <iostream>
#include <vector>
#include <string>

class Solution2 {
public:
    /**
     * @Function
     */

    bool isSafe(int row, int column, int n, std::vector<std::vector<std::string>> &board) {
        int i = row, j = column;  // store the values in some constant so we can use it latter 
        /**
         * Now let if the queen is safe in the upper diagonal
         */

        while (row >= 0 && column >= 0) {
            if (board[row][column] == "Q") return false;
            row--; column--;
        }

        /**
         * Now check if the queen is safe in the left side
         */

        row = i;
        column = j;
        while (column >= 0) {
            if (board[row][column] == "Q") return false;
            column--;
        }

        /**
         * Now check if the queen is safe in the lower diagonal
         */

        row = i;
        column = j;

        while (row < n && column >= 0) {
            if (board[row][column] == "Q") return false;
            row++;
            column--;
        }

        return true;
    }

    void solve(int column, int n, std::vector<std::vector<std::string>> &board, std::vector<std::vector<std::string>> &ans) {
        /**
         * Base Case : The moment column == n-1 means we found a possible solution
         */

        if (column == n) {
            std::vector<std::string> temp;
            for (int i = 0; i < n; ++i) {
                std::string rowStr = "";
                for (int j = 0; j < n; ++j) {
                    rowStr += board[i][j];
                }
                temp.push_back(rowStr);
            }
            ans.push_back(temp);
            return;
        }

        /**
         * Now try to place each queen in a safe place where no queens can attach each other
         */

        for (int row = 0; row < n; ++row) {
            if (isSafe(row, column, n, board)) {  // it this function is true then we go ahead
                board[row][column] = "Q";
                // now move to the next column
                solve(column+1, n, board, ans);
                // now in backtrack makesure the queen should omit from board[row][column]
                board[row][column] = ".";
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        /**
         * @Data Structure Requirement : 
         * 
         *  1. 2D Array of string for storing answer
         *  2. 2D Arrys of string for forming a borad
         */

        std::vector<std::vector<std::string>> ans;
        std::vector<std::vector<std::string>> board(n, std::vector<std::string>(n, "."));

        /**
         * @Function solve(column, size, board, ans)
         * 
         *  <column> : We are start filling queens from 0th column and move ahead in recursion call
         *  <size> : passing number of queens need to place in the board
         */

        solve(0, n, board, ans);
        return ans;
    }
};


/**
 * Optimize Soluiton : 
 * In this solution we are redusing time while checking if the place is safe of not for queen 
 * We are using concept of hashing 
 */

class Solution {
public:
    void solve(int column, int n, std::vector<std::string> &board, std::vector<bool> &leftRow, std::vector<bool> &lowerDiag, std::vector<bool> &upperDiag, std::vector<std::vector<std::string>> &ans) {
        if (column == n) {
            ans.push_back(board);
            return;
        }

        /**
         * Now check here the place is safe or not
         */

        for (int row = 0; row < n; ++row) {
            if (!leftRow[row] && !lowerDiag[row+column] && !upperDiag[n-1 + column-row]) {
                board[row][column] = 'Q';
                leftRow[row] = true;
                lowerDiag[row + column] = true;
                upperDiag[n-1 + column - row] = true;
                solve(column+1, n, board, leftRow, lowerDiag, upperDiag, ans);
                board[row][column] = '.';
                leftRow[row] = false;
                lowerDiag[row + column] = false;
                upperDiag[n-1 + column-row] = false;
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> board(n);
        std::string s(n, '.');
        
        for (int i = 0; i < n; ++i) board[i] = s;

        std::vector<bool> leftRow(n, false), upperDiag(2 * n - 1, false), lowerDiag(2 * n - 1, false);
        solve(0, n, board, leftRow, lowerDiag, upperDiag, ans);
        return ans;
    }
};
