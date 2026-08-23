// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Range_Max_Min_Query_Index {
private:
    /**
     * @param n                 the number of values passed in the nums array from user
     * @param min_tree          segment tree that contains the index of minimum values
     * @param max_tree          segment tree that contains the index of maximum values
     */
    int n;
    vector<int> nums;
    vector<int> min_tree, max_tree;

    void build_tree(int curr_idx, int left, int right) {
        // base case bhai
        if (left == right) {
            min_tree[curr_idx] = left;
            max_tree[curr_idx] = left;
            return;
        }

        int mid = left + (right - left) / 2;

        build_tree(2 * curr_idx + 1, left, mid);
        build_tree(2 * curr_idx + 2, mid + 1, right);

        // Minimum
        int left_min_idx = min_tree[2 * curr_idx + 1];
        int right_min_idx = min_tree[2 * curr_idx + 2];

        min_tree[curr_idx] =
            (nums[left_min_idx] <= nums[right_min_idx])
                ? left_min_idx
                : right_min_idx;

        // Maximum
        int left_max_idx = max_tree[2 * curr_idx + 1];
        int right_max_idx = max_tree[2 * curr_idx + 2];

        max_tree[curr_idx] =
            (nums[left_max_idx] >= nums[right_max_idx])
                ? left_max_idx
                : right_max_idx;
    }

    /**
     * @function -- ye function index return krega minimum value ka diye hue given range me
     * @param start         starting range
     * @param end           ending range
     * @param curr_idx      current index, starting from root `0`
     * @param left          starting from 0
     * @param right         ending at n-1
     */
    int query_minimum_index(
        int start,
        int end,
        int curr_idx,
        int left,
        int right
    ) {
        // bilkul apne aukaat ke bahar ka hai ye to
        if (start > right || end < left)
            return -1;

        // current segment completely lies inside query range
        if (left >= start && right <= end)
            return min_tree[curr_idx];

        int mid = left + (right - left) / 2;

        int left_idx = query_minimum_index(
            start,
            end,
            2 * curr_idx + 1,
            left,
            mid
        );

        int right_idx = query_minimum_index(
            start,
            end,
            2 * curr_idx + 2,
            mid + 1,
            right
        );

        if (left_idx == -1)
            return right_idx;

        if (right_idx == -1)
            return left_idx;

        return (nums[left_idx] <= nums[right_idx])
            ? left_idx
            : right_idx;
    }

    /**
     * @function -- ye function index return krega maximum value ka diye hue given range me
     * @param start         starting range
     * @param end           ending range
     * @param curr_idx      current index, starting from root `0`
     * @param left          starting from 0
     * @param right         ending at n-1
     */
    int query_maximum_index(
        int start,
        int end,
        int curr_idx,
        int left,
        int right
    ) {
        // bilkul apne aukaat ke bahar ka hai ye to
        if (start > right || end < left)
            return -1;

        // current segment completely lies inside query range
        if (left >= start && right <= end)
            return max_tree[curr_idx];

        int mid = left + (right - left) / 2;

        int left_idx = query_maximum_index(
            start,
            end,
            2 * curr_idx + 1,
            left,
            mid
        );

        int right_idx = query_maximum_index(
            start,
            end,
            2 * curr_idx + 2,
            mid + 1,
            right
        );

        if (left_idx == -1)
            return right_idx;

        if (right_idx == -1)
            return left_idx;

        return (nums[left_idx] >= nums[right_idx])
            ? left_idx
            : right_idx;
    }

public:

    Range_Max_Min_Query_Index(vector<int>& nums)
        : nums(nums) {

        n = nums.size();

        // allocate enough space for segment trees
        min_tree.resize(4 * n);
        max_tree.resize(4 * n);

        // now build the tree
        if (n > 0) {
            build_tree(0, 0, n - 1);
        }
    }

    int min_query(int start, int end) {
        if (n == 0)
            return -1;

        if (start < 0 || end >= n || start > end)
            return -1;

        return query_minimum_index(
            start,
            end,
            0,
            0,
            n - 1
        );
    }

    int max_query(int start, int end) {
        if (n == 0)
            return -1;

        if (start < 0 || end >= n || start > end)
            return -1;

        return query_maximum_index(
            start,
            end,
            0,
            0,
            n - 1
        );
    }
};

int main() {
    vector<int> nums = {4, 2, 7, 1, 9, 3, 6, 5};

    Range_Max_Min_Query_Index rmq(nums);

    cout << "Array: ";

    for (int x : nums) {
        cout << x << " ";
    }

    cout << "\n\n";

    // Query range [0, 7]
    int min_idx = rmq.min_query(0, 7);
    int max_idx = rmq.max_query(0, 7);

    cout << "Range [0, 7]\n";

    cout << "Minimum index: " << min_idx
         << ", value: " << nums[min_idx] << "\n";

    cout << "Maximum index: " << max_idx
         << ", value: " << nums[max_idx] << "\n";

    // Query range [1, 4]
    min_idx = rmq.min_query(1, 4);
    max_idx = rmq.max_query(1, 4);

    cout << "\nRange [1, 4]\n";

    cout << "Minimum index: " << min_idx
         << ", value: " << nums[min_idx] << "\n";

    cout << "Maximum index: " << max_idx
         << ", value: " << nums[max_idx] << "\n";

    // Query range [4, 7]
    min_idx = rmq.min_query(4, 7);
    max_idx = rmq.max_query(4, 7);

    cout << "\nRange [4, 7]\n";

    cout << "Minimum index: " << min_idx
         << ", value: " << nums[min_idx] << "\n";

    cout << "Maximum index: " << max_idx
         << ", value: " << nums[max_idx] << "\n";

    return 0;
}