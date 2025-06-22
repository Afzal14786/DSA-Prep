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

int main() {
    // method one
    int nums[3][3] = {{1,2,3}, {1,2,3}, {1,2,3}};

    // method two
    int *num2[3];
    num2[0] = new int[3];
    num2[1] = new int[3];
    num2[2] = new int[3];

    printArr(num2, 3,3);

    // method three
    int **nums3;
    nums3 = new int* [3];
    nums3[0] = new int[3];
    nums3[1] = new int[3];
    nums3[2] = new int[3];

    printArr(nums3, 3,3);
    
    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         cout << num2[i][j] << ", ";
    //     }
    //     cout << endl;
    // }
    return 0;
}