/**
 * Intersection Of Two Arrays II
 * Question Link : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=problem-list-v2&envId=array
 * Solution Link : https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/1873053013/?envType=problem-list-v2&envId=array
 */

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

// Constraints:

//  1 <= nums1.length, nums2.length <= 1000
//  0 <= nums1[i], nums2[i] <= 1000

// Follow up:

//  What if the given array is already sorted? How would you optimize your algorithm?
//  What if nums1's size is small compared to nums2's size? Which algorithm is better?
//  What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;

        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> A = {4,9,5};
    vector<int> B = {9,4,9,8,4};
    Solution s;

    vector<int> ans = s.intersect(A, B);

    cout <<  "Size of the ans : " << ans.size() << endl;
    for (int n : ans) {
        cout << n << " ";
    }

    cout << endl;
    return 0;
}