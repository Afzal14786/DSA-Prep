/**
 * @file this file contains the implementation of Range Query and Specifically based on varities of question as well as implement the binary search on this function to calculate the left most index whose elements are greater
 * 
 */

// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class RMIQ {
private:
    int n;
    vector<int> max_tree_indexes, nums;

    void build_tree(int curr_idx, int left, int right) {
        if (left == right) {
            max_tree_indexes[curr_idx] = left;
            return;
        }
        int mid = left + (right - left) / 2;
        build_tree(2 * curr_idx + 1, left, mid);
        build_tree(2 * curr_idx + 2, mid + 1, right);

        int left_idx = max_tree_indexes[2 * curr_idx + 1];
        int right_idx = max_tree_indexes[2 * curr_idx + 2];

        max_tree_indexes[curr_idx] = (nums[left_idx] >= nums[right_idx]) ? left_idx : right_idx;
    }

    int _single_query(int start, int end, int curr_idx, int left, int right) {
        if (start > right || end < left) return -1;
        if (left >= start && right <= end) return max_tree_indexes[curr_idx];

        int mid = left + (right - left) / 2;
        int left_idx = _single_query(start, end, 2 * curr_idx + 1, left, mid);
        int right_idx = _single_query(start, end, 2 * curr_idx + 2, mid + 1, right);

        if (left_idx == -1) return right_idx;
        if (right_idx == -1) return left_idx;

        return (nums[left_idx] >= nums[right_idx]) ? left_idx : right_idx;
    }

public:
    RMIQ(vector<int> &nums) : nums(nums) {
        n = nums.size();
        max_tree_indexes.resize(4*n);
        if (n > 0) build_tree(0, 0, n-1);
    }

    int single_query(int start, int end) {
        if (n == 0 || start < 0 || end >= n || start > end) return -1;
        if (end == n - 1) return -1;   // nothing to the right

        int threshold = max(nums[start], nums[end]);   // need > both
        int lo = end + 1, hi = n - 1;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // Get the index of the maximum in [end+1, mid]
            int maxIdx = _single_query(end + 1, mid, 0, 0, n - 1);
            // maxIdx is guaranteed to be valid because the range is non‑empty
            if (nums[maxIdx] > threshold) {
                ans = mid;          // we found a candidate, but try to move left
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;   // -1 if none found, otherwise the leftmost index
    }
};

int main() {
    // Test 1: Basic functionality
    {
        cout << "=== Test 1: Basic ===" << endl;
        vector<int> nums = {1, 3, 2, 5, 4};
        RMIQ rmiq(nums);

        // Query [0,2] -> max(nums[0],nums[2]) = max(1,2)=2. 
        // Suffix from index 3: [5,4] -> first >2 is index 3 (value 5)
        cout << "single_query(0,2) = " << rmiq.single_query(0, 2) << " (expected 3)" << endl;

        // Query [1,3] -> max(nums[1],nums[3]) = max(3,5)=5. 
        // Suffix from index 4: [4] -> no >5 -> -1
        cout << "single_query(1,3) = " << rmiq.single_query(1, 3) << " (expected -1)" << endl;

        // Query [2,4] -> end == n-1 -> no suffix -> -1
        cout << "single_query(2,4) = " << rmiq.single_query(2, 4) << " (expected -1)" << endl;
    }

    // Test 2: Ties and duplicates
    {
        cout << "\n=== Test 2: Duplicates ===" << endl;
        vector<int> nums = {2, 2, 1, 3, 2};
        RMIQ rmiq(nums);

        // [0,1] -> max(2,2)=2. Suffix: [1,3,2] -> first >2 is index 3 (value 3)
        cout << "single_query(0,1) = " << rmiq.single_query(0, 1) << " (expected 3)" << endl;

        // [1,3] -> max(2,3)=3. Suffix: [2] -> no >3 -> -1
        cout << "single_query(1,3) = " << rmiq.single_query(1, 3) << " (expected -1)" << endl;

        // [2,4] -> max(1,2)=2. No suffix -> -1
        cout << "single_query(2,4) = " << rmiq.single_query(2, 4) << " (expected -1)" << endl;
    }

    // Test 3: All equal
    {
        cout << "\n=== Test 3: All equal ===" << endl;
        vector<int> nums = {5, 5, 5, 5, 5};
        RMIQ rmiq(nums);

        // No element >5 anywhere -> -1
        cout << "single_query(0,2) = " << rmiq.single_query(0, 2) << " (expected -1)" << endl;
        cout << "single_query(1,3) = " << rmiq.single_query(1, 3) << " (expected -1)" << endl;
    }

    // Test 4: Strictly increasing
    {
        cout << "\n=== Test 4: Increasing ===" << endl;
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        RMIQ rmiq(nums);

        // [0,2] -> max(1,3)=3. Suffix: [4,5,6] -> first >3 is index 3 (value 4)
        cout << "single_query(0,2) = " << rmiq.single_query(0, 2) << " (expected 3)" << endl;

        // [2,4] -> max(3,5)=5. Suffix: [6] -> first >5 is index 5
        cout << "single_query(2,4) = " << rmiq.single_query(2, 4) << " (expected 5)" << endl;
    }

    // Test 5: Strictly decreasing
    {
        cout << "\n=== Test 5: Decreasing ===" << endl;
        vector<int> nums = {6, 5, 4, 3, 2, 1};
        RMIQ rmiq(nums);

        // [0,2] -> max(6,4)=6. Suffix: [3,2,1] -> no >6 -> -1
        cout << "single_query(0,2) = " << rmiq.single_query(0, 2) << " (expected -1)" << endl;

        // [1,3] -> max(5,3)=5. Suffix: [2,1] -> no >5 -> -1
        cout << "single_query(1,3) = " << rmiq.single_query(1, 3) << " (expected -1)" << endl;
    }

    // Test 6: Random with expected result
    {
        cout << "\n=== Test 6: Random ===" << endl;
        vector<int> nums = {10, 7, 9, 12, 8, 15, 6, 11};
        RMIQ rmiq(nums);

        // [0,2] -> max(10,9)=10. Suffix: [12,8,15,6,11] -> first >10 is index 3 (value 12)
        cout << "single_query(0,2) = " << rmiq.single_query(0, 2) << " (expected 3)" << endl;

        // [2,4] -> max(9,8)=9. Suffix: [15,6,11] -> first >9 is index 5 (value 15)
        cout << "single_query(2,4) = " << rmiq.single_query(2, 4) << " (expected 5)" << endl;

        // [3,5] -> max(12,15)=15. Suffix: [6,11] -> no >15 -> -1
        cout << "single_query(3,5) = " << rmiq.single_query(3, 5) << " (expected -1)" << endl;

        // [4,6] -> max(8,6)=8. Suffix: [11] -> first >8 is index 7 (value 11)
        cout << "single_query(4,6) = " << rmiq.single_query(4, 6) << " (expected 7)" << endl;
    }

    // Test 7: Edge cases – empty and invalid ranges
    {
        cout << "\n=== Test 7: Edge cases ===" << endl;
        vector<int> nums;
        RMIQ rmiq(nums);
        cout << "Empty array: " << rmiq.single_query(0, 0) << " (expected -1)" << endl;

        vector<int> nums2 = {1, 2};
        RMIQ rmiq2(nums2);
        cout << "Invalid start > end: " << rmiq2.single_query(2, 1) << " (expected -1)" << endl;
        cout << "Start < 0: " << rmiq2.single_query(-1, 0) << " (expected -1)" << endl;
        cout << "End >= n: " << rmiq2.single_query(0, 2) << " (expected -1)" << endl;
        cout << "End == n-1: " << rmiq2.single_query(0, 1) << " (expected -1)" << endl;
    }

    return 0;
}