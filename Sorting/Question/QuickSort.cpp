#include <iostream>
#include <vector>
using namespace std;


int partition(int nums[], int start, int end) {
    int pivot = nums[start];
    int i = start, j = end;

    do {
        do {++i;} while(nums[i] <= pivot);
        do {--j;} while(nums[j] > pivot);

        if (i < j) {
            swap(nums[i], nums[j]);
        }
    } while (i < j);

    swap(nums[start], nums[j]);
    return j;
}

void QuickSort(int nums[], int start, int end) {
    if (start < end) {
        int partitionPoint = partition(nums, start, end);
        QuickSort(nums, start, partitionPoint);
        QuickSort(nums, partitionPoint+1, end);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int nums[] = {50,70,60,90,40,80,10,20,30};
    int n = sizeof(nums)/sizeof(int);

    cout << "Given Array is :\n";
    printArr(nums, n);

    QuickSort(nums, 0, n);

    cout << "Array After Sorting The Elements :\n";
    printArr(nums, n);
    return 0;
}