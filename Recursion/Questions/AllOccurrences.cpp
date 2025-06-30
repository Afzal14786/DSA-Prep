/**
    For a given integer array of size `N` . We have to find all the occurrences (indices) of given element (key) and print them .
    Example : 
    arr[] = {3,2,4,5,6,2,7,2,2}, key = 2;
    O/P : 1 5 7 8

    Solution Approach //
    base case // if we reached till end means we search for the entire array so return -1 => not found

    recursive case =>
        the problem is reduce to f(n-1)
*/

#include <iostream>
#include <vector>
using namespace std;

void AllOccurrences(vector<int> &nums, int i, int target) {
    if (i == nums.size()) {
        return;
    }

    if (nums[i] == target) {
        cout << i << " ";
    }

    AllOccurrences(nums, i+1, target);

}

int main() {
    vector<int> nums = {3,2,4,5,6,2,7,2,2};
    int key = 2;

    AllOccurrences(nums, 0, key);
    cout << endl;
    return 0;
}