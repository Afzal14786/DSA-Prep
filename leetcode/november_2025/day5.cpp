// You are given an array nums of n integers and two integers k and x.

// The x-sum of an array is calculated by the following procedure:

//     Count the occurrences of all elements in the array.
//     Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
//     Calculate the sum of the resulting array.

// Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

// Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray  nums[i..i + k - 1].

 

// Example 1:

// Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

// Output: [6,10,12]

// Explanation:

//     For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
//     For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
//     For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.

// Example 2:

// Input: nums = [3,8,7,8,7,5], k = 2, x = 2

// Output: [11,15,15,15,12]

// Explanation:

// Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].

 

// Constraints:

//     nums.length == n
//     1 <= n <= 105
//     1 <= nums[i] <= 109
//     1 <= x <= k <= nums.length


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using pii = pair<int, int>;
    using ll = long long;
    set<pii> topX;
    set<pii> rem;
    unordered_map<int, int> freq;
    ll sum = 0;

    vector<ll> findXSum(vector<int>& nums, int k, int x) {
        int j;
        for (j = 0; j < k; ++j) {
            processSet(nums[j], true, x);
        }

        int i = 0;
        vector<ll> ans;
        ans.push_back(sum);
        while (j < nums.size()) {
            processSet(nums[i], false, x);
            i++;
            processSet(nums[j], true, x);
            j++;
            ans.push_back(sum);
        }

        return ans;
    }

    void processSet(int num, bool isIncrement, int x) {
        if (topX.find({freq[num], num}) != topX.end()) {
            sum -= (ll)num * freq[num];
        }

        topX.erase({freq[num], num});
        rem.erase({freq[num], num});

        if (isIncrement) freq[num]++;
        else freq[num]--;

        if (freq[num] == 0) freq.erase(num);

        if (freq.find(num) != freq.end()) {
            topX.insert({freq[num], num});
            sum += (ll)freq[num] * num;
        }

        // Balance

        if (topX.size() > x) {
            auto [bottomFreq, bottomX] = *topX.begin();
            rem.insert({bottomFreq, bottomX});
            topX.erase({bottomFreq, bottomX});
            sum -= (ll)bottomFreq * bottomX;
        }

        if (topX.size() < x && !rem.empty()) {
            auto [topRemFreq, topRemNum] = * rem.rbegin();
            rem.erase({topRemFreq, topRemNum});
            topX.insert({topRemFreq, topRemNum});
            sum += (ll)topRemFreq * topRemNum;
        }

        if (topX.size() == x && !rem.empty()) {
            auto [bottomXFreq, bottomX] = *topX.begin();
            auto [topRemFreq, topRem] = *rem.rbegin();

            if (bottomXFreq < topRemFreq || (bottomXFreq == topRemFreq && topRem > bottomX)) {
                rem.erase({topRemFreq, topRem});
                topX.insert({topRemFreq, topRem});
                sum += (ll)topRemFreq * topRem;

                rem.insert({bottomXFreq, bottomX});
                topX.erase({bottomXFreq, bottomX});
                sum -= (ll)bottomXFreq * bottomX;
            }
        }
    }
};