#include <iostream>
using namespace std;

int binarySearch(int nums[], int n, int key) {
    int start = 0, end = n-1;
    
    // binary search
    while (start <= end) {
        int mid = start + (end-start)/2;

        if (nums[mid] == key) {
            return mid;       // key found at i;
        } else if (key < nums[mid]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return -1;      // if not found
}

int main() {
    int nums[] = {10,20,30,40,50,60};
    cout << binarySearch(nums, 5, 30) << endl;
    return 0;
}