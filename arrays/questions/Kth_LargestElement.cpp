#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief In this question we have to find the kth largest element, 
 * In first solution approach we're solving without sorting the array.
 * @param K is an Integer data type, where K > size & K < 0
 */


/**
 * @brief At the moment, we are solving using sort
 */
int kthLargestElement(vector<int> &nums, int K) {

    // base case 
    if (nums.size() == 0 || K < 0 || K > nums.size()) {
        // invalid position or empty array
        return -1;
    }

    sort(nums.begin(), nums.end());
    return nums[nums.size()-K];
}

int main () {
    vector<int> nums = {3,2,1,5,6,4};
    int K = 22;
    cout << "kth Element In The Given Array Is : " << kthLargestElement(nums, K) << endl;
    return 0;
}