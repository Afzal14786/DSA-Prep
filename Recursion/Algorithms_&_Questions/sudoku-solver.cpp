// Question Link : https://leetcode.com/problems/sudoku-solver/

#include <iostream>
#include <vector>

class Solution {
public:
    bool solve(std::vector<std::vector<char>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                // check for the empty place
                if (board[i][j] == '.') {
                    // now try to fill all the possible values
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(std::vector<std::vector<char>> &board, int row, int col, char ch) {
        /**
         * First check the value we are trying to fill, is it valid or not
         */

        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == ch) return false;
            if (board[i][col] == ch) return false;
            // check in the grid 3 * 3
            if (board[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch) return false;
        }
        return true;
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }
};