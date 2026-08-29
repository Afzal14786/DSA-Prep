// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/?envType=daily-question&envId=2026-08-29
// optmimal solution 

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();      
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        int group_num = 0;
        unordered_map<int, int> num_to_group;
        num_to_group[vec[0]] = group_num;

        unordered_map<int, list<int>> group_to_list;
        group_to_list[group_num].push_back(vec[0]);

        for (int i = 1; i < n; ++i) {
            if (abs(vec[i] - vec[i-1]) > limit) group_num++;
            num_to_group[vec[i]] = group_num;
            group_to_list[group_num].push_back(vec[i]);
        }

        // now build the answer 
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int group = num_to_group[num];
            res[i] = *(group_to_list[group].begin());
            group_to_list[group].pop_front();
        }

        return res;
    }
};

// brute force solution
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        // too much time consuming
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
    
                    if (nums[i] > nums[j] && abs(nums[i] - nums[j]) <= limit) {
                        swap(nums[i], nums[j]);
                        changed = true;
                    }
                }
            }
        }
        return nums;
    }
};


class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        // another solution
        for (int i = 0; i < n; ++i) {

            while (true) {
                int smalled_value = nums[i];
                int idx = -1;
                for (int j = i + 1; j < n; ++j) {
                    if (abs(nums[i] - nums[j]) <= limit && nums[j] < smalled_value) {
                        smalled_value = nums[j];
                        idx = j;
                    }
                }

                if (idx != -1) {
                    swap(nums[idx], nums[i]);
                } else break;
            }
        }

        return nums;
    }
};
