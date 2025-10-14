#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


int subArraySum_with0(vector<int> &arr) {
    unordered_map<int, int> m;  // <sum, index>
    int sum = 0, ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if (m.count(sum)) {
            int curr_len = i - m[sum];
            ans = max(ans, curr_len);
        } else {
            m[sum] = i;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10};
    cout << subArraySum_with0(nums) << endl;
    return 0;
}