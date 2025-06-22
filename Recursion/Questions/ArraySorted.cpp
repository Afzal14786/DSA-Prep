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

int main() {
    vector<int> nums = {1,2,3,4,5};
    vector<int> nums2 = {1,2,3,4,5};
    cout << isSorted(nums, 0) << endl;
    return 0;
}