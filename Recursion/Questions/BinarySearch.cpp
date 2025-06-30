#include <iostream>
using namespace std;


int BinarySearch(int *nums, int start, int end, int target) {
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start)/2;

    if (nums[mid] == target) {
        return mid;
    } else if(nums[mid] > target) {
        return BinarySearch(nums, start, mid - 1, target);
    } else {
        return BinarySearch(nums, mid + 1, end, target);
    }
}

int main() {

    int arr[]={1,2,3,4,5,6,7};
    int n = 7,key = 5;

    cout << BinarySearch(arr, 0, n, key) << endl;
    
    return 0;
}