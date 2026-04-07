#include <iostream>
#include <vector>

using namespace std;

/**
 * reversing an array using recursion
 */

vector<int> reverse(int left, int right, vector<int> &nums) {
    if (left >= right) {
        return nums;
    }
    swap(nums[left], nums[right]);
    return reverse(left + 1, right - 1, nums);
}

// another way using one pointer
vector<int> reverse_arr(int i, vector<int> &nums) {
    int n = nums.size();
    if (i >= n/2) return nums;
    swap(nums[i], nums[n-i-1]);
    return reverse_arr(i+1, nums);
}

void reverse_void(int i, vector<int> &nums) {
    int n = nums.size();
    if (i >= n/2) return;
    swap(nums[i], nums[n-i-1]);
    reverse_void(i+1, nums);
}

int main() {
    vector<int> nums = {1,2,3,4,5,6};
    // vector<int> ans = reverse_arr(0, nums);
    // for (int i = 0; i < ans.size(); ++i) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    // reverse function
    reverse_void(0, nums);
    cout << "After reversing the array look like: ";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}