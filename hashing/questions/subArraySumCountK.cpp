#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int subArraySumCountK(vector<int> &nums, int k) {
    unordered_map<int, int> m;  // <sum, count>
    m[0] = 1;
    int sum = 0, ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (m.count(sum - k)) {
            ans += m[sum-k];
        }

        if (m.count(sum)) {
            m[sum]++;
        } else {
            m[sum] = 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    int k = 3;
    cout << "Count = " << subArraySumCountK(nums, k) << endl;
    return 0;
}