#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// time complexity is O(n) because the value is unsorted
vector<int> pairSum(vector<int>& nums, int k) {
    if (nums.size() == 0) {
        return {};
    }
    // using two pointers as well as can also solve this 
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size()-1;
    vector<int> ans;
    while (left < right) {
        int currSum = nums[left] + nums[right];
        if (currSum == k) {
            ans.push_back(left);
            ans.push_back(right);
            return ans;
        }

        if (currSum < k) {
            left++;
        } else {
            right--;
        }
    }

    return ans;
}

// solution approact

// leet code question :  https://leetcode.com/problems/two-sum/description/

vector<int> pair_sum(vector<int>&nums, int k) {
    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
        // get he complement first
        int compliment = k - nums[i];
        // now check if it is exist or not
        if (m.count(compliment)) {
            ans.push_back(m[compliment]);
            ans.push_back(i);
            return ans;
        }

        m[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {1,2,7,11,5,9};
    vector<int> ans = pair_sum(nums, 9);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}