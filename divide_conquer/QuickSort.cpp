#include <iostream>
#include <vector>
using namespace std;

void printArr(int nums[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

int partition(int nums[], int start, int end) {
    int pivotElem = nums[start];
    int i = start, j = end;

    do {
        do {
            ++i;
        } while (nums[i] <= pivotElem);

        do {
            --j;
        } while (nums[j] > pivotElem);

        if (i < j) {
            swap(nums[i], nums[j]);
        }

    } while (i < j);

    swap(nums[start], nums[j]);
    return j;
}

void QuickSort(int nums[], int start, int end) {
    if (start > end) {
        return;
    }
    
    if (start < end) {
        int partitionPoint = partition(nums, start, end);
        QuickSort(nums, start, partitionPoint);
        QuickSort(nums, partitionPoint+1, end);
    }
}

/**
 * Time Complexty : O(n^2) in wrost case ..
 * Space Complexity : Constant
 */

int main() {
    int nums[] = {4,3,2,6,9,55,1};
    cout << "The Array Before Sorting.\n";
    printArr(nums, 7);

    cout << "The Array After Sorting Using Quick Sort.\n";
    QuickSort(nums, 0, 7);
    printArr(nums, 7);
    return 0;
}