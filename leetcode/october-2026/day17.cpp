// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/?envType=daily-question&envId=2026-10-17

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int get_digit_sum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> after_sorted(nums);
        auto lambda = [this](int a, int b) {
            int digit1 = get_digit_sum(a);
            int digit2 = get_digit_sum(b);

            if (digit1 != digit2)
                return digit1 < digit2;
            
            return a < b;
        };

        sort(after_sorted.begin(), after_sorted.end(), lambda);

        unordered_map<int, int> value_index_map;
        for (int i = 0; i < n; ++i) value_index_map[nums[i]] = i;

        int swap_count = 0;
        for (int i = 0; i < n; ++i) {
            int expected_val = after_sorted[i];
            int current_val  = nums[i];
            
            if (expected_val == current_val) continue;

            int index = value_index_map[expected_val];
            nums[i] = expected_val;
            nums[index] = current_val;

            value_index_map[expected_val] = i;
            value_index_map[current_val] = index;

            swap_count++;
        }

        return swap_count;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();