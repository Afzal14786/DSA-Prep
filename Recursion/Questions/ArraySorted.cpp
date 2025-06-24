#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &nums, int i) {
    if (i == nums.size()-1) {
        return true;
    }

    if (nums[i] > nums[i+1]) {
        return false;
    }

    return isSorted(nums, i+1);
}

bool isSorted2(vector<int> &nums, int size) {
    if (size == 1) {
        return true;
    }

    return (nums[size-1] < nums[size-2]) ? 0 : isSorted2(nums, size-1);
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    vector<int> nums2 = {1,2,3,3,4,5};
    
    cout << isSorted(nums, nums.size()) << endl;    // sorted   // 0
    cout << isSorted2(nums2, nums2.size()) << endl; // not sorted   // 1
    
    return 0;
}