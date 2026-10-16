#include <iostream>
#include <vector>
using namespace std;


void Merge(int arr[], int start, int mid, int end) {
    int i = start, j = mid + 1; 
    vector<int> temp;

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= end) {
        temp.push_back(arr[j++]);
    }

    // cop all the element to the orignal array
    for (int idx = start, k = 0; idx <= end; idx++) {
        arr[idx] = temp[k++];
    }

}

void MergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start)/2;

    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);

    Merge(arr, start, mid, end);
}

void printArr(int nums[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    int nums[] = {-6,-3,-7,-5,-2,-4};
    int n = 6;

    MergeSort(nums, 0, n-1);
    printArr(nums, n);
    return 0;
}