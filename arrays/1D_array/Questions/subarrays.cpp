#include <iostream>
using namespace std;

// printing all the possible subarrays in a given arrays,

void printSubArrays(int *arr, int size) {
    // run a outer loop over the array
    for (int i = 0; i < size; ++i) {

        // run an inner loop in the same array, start from i
        for (int j = i; j < size; ++j) {

            // run a third nested loop in the array for printing all the possible subarrays, arr[k]
            // loop start from (i to <= j)
            for (int k = i; k <= j; ++k) {
                cout << arr[k];
            }
            cout << ", ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {3,7,9,6,10,32};
    int size = sizeof(arr) / sizeof(int);

    // printing All The possible subarrays
    printSubArrays(arr, size);

    return 0;
}