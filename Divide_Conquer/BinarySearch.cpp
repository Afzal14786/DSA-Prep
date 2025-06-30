#include <iostream>
#include <vector>
using namespace std;

/**
 * General Recurrence Relation For Dividing Function = T(n) = aT(n/b) + f(n)
 * Recurrence Relation For Binary Search : T(n) = T(n/2) + 1
 * 
 *      Time Complexity = O(logn)
 */


int BinSearch(vector<int> &nums, int start, int end, int target) {

    if (start > end) {
        return -1;
    }

    int mid = start + (end - start)/2;

    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] > target) {
        return BinSearch(nums, start, mid-1, target);
    } else {
        return BinSearch(nums, mid+1, end, target);
    }
}

int main() {
    vector<int> nums = {-12,-8,-6,-1,3,6,8,11,14,17,20,22,25,29,31};
    cout << "Target Found At Index : " << BinSearch(nums, 0, nums.size()-1, 6) << endl;
    return 0; 
}