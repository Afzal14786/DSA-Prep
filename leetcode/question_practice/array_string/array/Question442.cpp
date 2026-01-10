
// Question Link : https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// solution approach 1
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == nums[i+1]) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};


// solution approach 2 :
// Solution Link : https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/1872125767/
class Solution2 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        set<int> s;

        for (int i : nums) {
            if (s.find(i) != s.end()) {
                ans.push_back(i);
            }
            s.insert(i);
        }

        return ans;
    }
};

class Solution3 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(int i=0; i<n; i++) {
            int curr = abs(nums[i]);

            if(nums[curr - 1] < 0) {
                res.push_back(curr);
            } else {
                nums[curr - 1] = -nums[curr - 1];
            }
        }

        return res;
    }
};

int main() {
    Solution3 s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = s.findDuplicates(nums);

    cout << "Output : [";
    for (int i : ans) {
        cout << i << " ";
    }

    cout << ']' << endl;
    return 0;
}