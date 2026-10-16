#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// leet code problem link : https://leetcode.com/problems/majority-element/

vector<int> majorityElem(vector<int>& nums) {
    unordered_map<int, int> m;  // <element, freq>
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.count(nums[i])) {
            // increase the fre
            m[nums[i]]++;
        } else {
            m[nums[i]] = 1;
        }
    }

    for (pair<int, int> p: m) {
        if (p.second > nums.size()/3) {
            ans.push_back(p.first);
        }
    }

    return ans;
}

int main() {

    vector<int> nums = {1,3,2,5,1,3,1,5,1};
    vector<int> num2 = {1,2};

    vector<int> ans1 = majorityElem(nums);
    for (int n : ans1) {
        cout <<  n << " ";
    }
    cout << endl;

    vector<int> ans2 = majorityElem(num2);
    for (int n : num2) {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}