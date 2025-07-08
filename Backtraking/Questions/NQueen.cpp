#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool foundSolution = false;
// global arrays
int boardSize = 8; // or any N you want to solve for
vector<int> answer(boardSize);
int totalSolution = 0;

vector<vector<char>> board(boardSize, vector<char>(boardSize, '.'));


void printAns(vector<int> &ans) {
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

bool isSafe(int k, int l) {     // k as row, and l as columns
    for (int i = 0; i < k; ++i) {
        if (answer[i] == l || abs(i-k) == abs(answer[i] - l)) {
            return false;int totalCombination = 0;
        }
    }

    return true;
}


void nQueen(int k) {
    if (k == boardSize) {
        totalSolution++;
        printAns(answer);
        return;
    }

    for (int i = 0; i < boardSize; ++i) {
        if (isSafe(k, i)) {
            answer[k] = i;
            nQueen(k+1);
        }
    }
}


// print 2D Matrix

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << "\n----------------------------\n";
}


void nQueen2(int k) {
    if (k == boardSize) {
        totalSolution++;
        printBoard(board);
        return;
    }

    for (int i = 0; i < boardSize; ++i) {
        if (isSafe(k, i)) {
            board[k][i] = 'Q';
            answer[k] = i;
            nQueen2(k+1);
            board[k][i] = '.';
        }
    }
}

void nQueen3(int k) {
    if (foundSolution) {
        return;
    }

    if (k == boardSize) {
        printAns(answer);
        foundSolution = true;
        return;
    }

    for (int i = 0; i < boardSize; ++i) {
        if (isSafe(k, i)) {
            board[k][i] = 'Q';
            answer[k] = i;
            nQueen3(k+1);
            if (foundSolution) {
                return;
            }
            board[k][i] = '.';
        }
    }
}

int main() {

    // nQueen(0);
   // cout << "Total No of possible solutions for N = 8 is " << totalSolution << endl;
    nQueen3(0);     // print one solution only
    cout << "Total No of possible solutions for N = 8 is " << totalSolution << endl;
    return 0;
}