#include <iostream>
using namespace std;

void spiralMatrix(int nums[][4], int n, int m) {
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while (srow <= erow && scol <= ecol) {
        // top
        for (int i = scol; i <= ecol; ++i) {
            cout << nums[srow][i] << " ";
        }

        // right
        for (int j = srow+1; j <= ecol; ++j) {
            cout << nums[j][ecol] << " ";
        }

        // bottom 
        for (int i = ecol-1; i >= scol; --i) {
            if (srow == erow) {
                break;
            }
            cout << nums[erow][i] << " ";
        }

        // left
        for (int j = erow-1; j >= srow+1; --j) {
            if (srow == erow) {
                break;
            }
            cout << nums[j][scol] << " ";
        }

        srow++; scol++;
        erow--; ecol--;
    }
    cout << endl;
}

int main() {
    int matrix[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int matrix2[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    spiralMatrix(matrix, 4,4);
    return 0;
}