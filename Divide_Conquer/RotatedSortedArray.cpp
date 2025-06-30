#include <iostream>
#include <vector>
using namespace std;

// leet code question no 33
// question link : https://leetcode.com/problems/search-in-rotated-sorted-array/

int RotatedBinarySearch(int nums[], int start, int end , int target) {
    // base case //

    if (start > end) {
        return -1;      // invalid or not found
    } 

    // calculate the mid here 
    int mid = start + (end - start) / 2;

    if (nums[mid] == target) {
        return mid;
    }

    // now check where the mid exist means => In line no 1 or line no 2
    if (nums[start] <= nums[mid]) { // means the mid exist in line no 1.
        // now some cases for line no 1
        if (nums[start] <= target && target <= nums[mid]) {
            return RotatedBinarySearch(nums, start, mid-1, target);     // means search in the left half of line 1
        } else {
            return RotatedBinarySearch(nums, mid+1, end, target);       // means search in the right half of the line 1
        }
    } else {
        // means that the mid value exist in line no 2, so
        if (nums[mid] <= target && target <= nums[end]) {
            return RotatedBinarySearch(nums, mid+1, end, target);       // means search in the right half of the line no 2
        } else {
            return RotatedBinarySearch(nums, start, mid-1, end);        // means search in the left of the line no 2
        }
    }
}

int main() {
    int nums[] = {4,5,6,7,0,1,2};
    int target = 0;


    cout << "The Given " << target << " found at index " << RotatedBinarySearch(nums, 0, 6, target) << endl;
    return 0;
}