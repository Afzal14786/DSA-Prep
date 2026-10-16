#include <iostream>
#include <vector>
using namespace std;

/**
 * @param
 * Implementing merge sort using recursion
 */

void Merge(int nums[], int start, int mid, int end) {
    int i = start, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= end) {
        if (nums[i] < nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i++]);
    }

    while (j <= end) {
        temp.push_back(nums[j++]);
    }

    // copy all the element to the orignal array
    for (int idx = start, k = 0; idx <= end; ++idx) {
        nums[idx] = temp[k++];
    }
}


// recurrence relation for this merge sort is T(n) = 2T(n/2) + n
// Time Complexity Is = T(nlogn)
void MergeSort(int nums[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start)/2;

        MergeSort(nums, start, mid);
        MergeSort(nums, mid+1, end);

        Merge(nums, start, mid , end);
    }
}

// void iMergeSort(int nums[], int n) {
//     int lastSize;
//     for (int size = 1; size <= n/2; size = size * 2) {    // calculating the no of passes
//         lastSize = size;
//         for (int low = 0, h = 2*size-1; h <= n-1; low = h+1, h = 2*size-1) {
//             Merge(nums, low, (low + h)/2, h);
//         }
//     }

//     if (lastSize < n) {
//         Merge(nums, 0, 2*lastSize-1, n-1);
//     }
// }

void printArr(int nums[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

int main() {
    // int nums[] = {4,3,2,6,9,55,1};
    int nums[] = {3,7,12,16,20,5,9,13,15,19};
    cout << "The Array Before Sorting.\n";
    printArr(nums, 9);

    cout << "The Array After Sorting Using Merge Sort.\n";
    MergeSort(nums, 0, 9);
    // iMergeSort(nums, 9);
    printArr(nums, 9);
    return 0;
}