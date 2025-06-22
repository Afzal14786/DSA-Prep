#include <iostream>
using namespace std;

void printArr(int **nums, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; ++j) {
            cout << nums[i][j] << ", ";
        }
        cout << endl;
    }
}
// approach 1;
// time complexity :  O(n^2)
void searchMat1(int nums[][4], int n, int key) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (nums[i][j] == key) {
                cout << "The Given Key Found At Index (" << i << "," << j << ")" << endl;
                return;
            }
        }
    }
}

// Approach 2  => time complexity : O(nlogm)
// Function to perform binary search on a single row of the matrix
void bsearch(int nums[][4], int n, int key) {
    int start, end;

    for (int i = 0; i < n; ++i) {  // for first row
        start = 0;
        end = n-1;

        while (start <= end) {
            int mid = start + (end-start)/2;

            if (nums[i][mid] == key) {
                cout << "Key " << key << "is found at index (" << i << ", " << mid << ")" << endl;
                return;
            } else if (nums[i][mid] > key) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }

    cout << "Key " << key << "is not found in the given 2D matrix." << endl;
}

// approach 3.  // staircase algorithm

void staircase(int nums[][4], int n, int key) {
    int row = 0, cols = n-1;

    while (row < n && cols >= 0) {
        if (nums[row][cols] == key) {
            cout << "Key " <<  key << " is found at index (" << row << ", " << cols << ")" << endl;
            return;
        } else if (nums[row][cols] > key) {
            cols--;
        } else {
            row++;
        }
    }
    cout << "Key " << key << "is not found in the given 2D matrix." << endl;
}

int main() {
    // Define the 4x4 matrix
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 30, 45, 60},
        {70, 80, 90, 100}};

    // Print the matrix
    cout << "Matrix:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << mat[i][j] << "\t"; // Use tab for better formatting
        }
        cout << endl;
    }

    cout << endl;
    // Search for the key (e.g., 80)
    staircase(mat, 3, 70);
    cout << endl;

    return 0;
}