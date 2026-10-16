#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// let board size = 4
const int N = 4;

// now for storing queen's positons
vector<int> answer(N);

void printAns(vector<int> &answer) {
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

/**
 * Now for solving the question we should have two function
 *      1. for recursive calling the NQueen() funtion for next call
 *      2. another for checking the valid position for keeping the queens
 */

// isSafe(int row, int col), this function check if the queen is placing in the safe place or not

bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        // using this we can check the queen moves
        if (answer[i] == col || abs(i-row) == abs(answer[i]-col)) {
            return false;   // if the queen is not safe
        }
    }
    return true;    // if the queen safe
}

// NQueen(k), function call the function recursively for placing next queen

void NQueen(int k) {
    // base case
    if (N == k) {
        printAns(answer);
        return;
    }

    // then
    for (int i = 0; i < N; ++i) {
        if(isSafe(k, i)) {
            answer[k] = i;
            NQueen(k+1);
        }
    }
}

int main() {
    NQueen(0);
    return 0;
}