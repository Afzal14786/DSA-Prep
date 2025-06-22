#include <iostream>
using namespace std;

int diagonalSum1(int nums[][4], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                sum += nums[i][j];
            } else if (j == n-i-1) {
                sum += nums[i][j];
            }
        }
    }
    cout << "Sum is " << sum << endl;
    return sum;
}

int main() {
    int matrix[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int matrix2[][4] = {{1,2,3}, {4,5,6}, {7,8,9}};

    cout << diagonalSum1(matrix, 4);
    cout << endl;
    return 0;
}