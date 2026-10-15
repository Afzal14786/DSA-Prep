#include <iostream>
#include <vector>
using namespace std;


/**
 *      This process of searching known as linear and time complexity is 
 *      O(1) => In best case
 * 
 *      O(n) => In average case & wrost case time complexity .
 */
int findNum(vector<int> &nums, int key) {
    int size = nums.size();

    for (int i = 0; i < size; ++i) {
        if (nums[i] == key) {
            return i;
        }
    }

    return -1;
}

// Inhansing the Linear search

int findNum2(vector<int> &nums, int key) {
    int start = 0, end = nums.size()-1;

    while (start < end) {
        int mid = start + (end - start)/2;

        if (nums[mid] == key) {
            // key is found
            return mid;
        } else if (nums[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    // not found return -1
    return -1;
}

// in best case : O(1)
// time complexity : O(logn)

int main() {
    vector<int> nums = {1,2,4,6,7,8,43,3};
    vector<int> nums2 = {1,2,4,6,7,8,43,78};
    cout << "The key is found at index : " << findNum(nums, 1) << endl;
    cout << "The key is found at index : " << findNum2(nums2, 43) << endl;
    return 0;
}