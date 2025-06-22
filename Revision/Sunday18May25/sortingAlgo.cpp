#include <iostream>
using namespace std;

// implementing the sorting algorithms 

void printArr(int *nums, int n) {
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << ", ";
    }

    cout << endl;
}

/**
 * Time Complexity : O(n^2)
 *  Best Case If List Is Already Sorted : O(n)
 *  It is stable and adeptive as well as Inplace sorting algorithms
 */
void bubble_sort(int *nums, int n) {
    bool flag = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                flag = true;
            }
        }

        if (flag == false) {
            cout << "The Provided list is already sorted . So time complexity is O(n).\n";
            break;
        }
    }
}

/**
 * Insertion sort
 * Time Complexity : O(n^2)
 * Best Case : O(n)
 * Inplace Sorting Algorithm
 * By nature insertion sort is adeptive . . .
 * And insertion sort is also stable . . .
 * 
 * If the list is already sorted then there is only one comparisions 
 * So if there is n number, then the number of comparisions is : O(n) if list is already sorted
 * and no of swaps if the list is already swaps = O(1)
 */

void insertion_sort(int *nums, int n) {
    int j, key;

    for (int i = 1; i < n; ++i) {
        // assuming the very first element is already sorted . . . 
        j = i-1;

        // 'key' select the current element that is going to inserted into a sorted position in the sublist.
        key = nums[i];

        // shift the element into the right side of the array if it is greater then current value . . .
        while (j > -1 && nums[j] > key) {
            nums[j+1] = nums[j];
            j--;
        }
        // inserting into a sorted place . . . 
        nums[j+1] = key;
    }
}

void selection_sort(int *nums, int n) {
    int k;
    for (int i = 0; i < n-1; ++i) {
        for (int j = k = i; j < n; ++j) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        swap(nums[i], nums[k]);
    }
}

/** 
 * Implementing Quick Sort
 */

int partition(int *nums, int low, int high) {
    int pivot = nums[low];
    int start = low, end = high;

    do {
        do {start++;} while (nums[start] <= pivot);
        do {end--;} while (nums[end] > pivot);

        if (start < end) {
            swap(nums[start], nums[end]);
        }
    } while (start < end);

    swap(nums[low], nums[end]);
    return end;

}

void QuickSort(int *nums, int low, int high) {
    int p_point;
    if (low < high) {
        p_point = partition(nums, low, high);
        QuickSort(nums, low, p_point);
        QuickSort(nums, p_point+1, high);
    }
}

int main() {
    int prices[] = {6,8,2,4,9,1,12,10};
    int n = sizeof(prices)/sizeof(int);

    QuickSort(prices, 0, n);
    printArr(prices, n);

    return 0;
}