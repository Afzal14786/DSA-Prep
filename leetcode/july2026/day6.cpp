/**
 * Given an array intervals where intervals[i] = [li, ri] represent the interval
 * [li, ri), remove all intervals that are covered by another interval in the list.
 *
 * The interval [a, b) is covered by the interval [c, d) if and only if
 * c <= a and b <= d.
 *
 * Return the number of remaining intervals.
 *
 * Example 1:
 *   Input: intervals = [[1,4],[3,6],[2,8]]
 *   Output: 2
 *   Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
 *
 * Example 2:
 *   Input: intervals = [[1,4],[2,3]]
 *   Output: 1
 *
 * Constraints:
 *   1 <= intervals.length <= 1000
 *   intervals[i].length == 2
 *   0 <= li < ri <= 10^5
 *   All the given intervals are unique.
 *
 * @see https://leetcode.com/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // solution with constant space 
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // vector<vector<int>> result;   // not needed for this approach

        // Custom comparator: sort by start ascending, and if ties, by end descending
        auto lambda = [](vector<int> &vec1, vector<int> &vec2) {
            if (vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];   // longer interval first when starts equal
            }
            return vec1[0] < vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        // The first interval is always kept (no previous interval to cover it)
        int lastIntervalValue = intervals[0][1];
        int count = 1;

        for (int i = 1; i < n; ++i) {
            // If current interval's end is not greater than last kept end, it's covered
            if (lastIntervalValue >= intervals[i][1]) {
                continue;   // skip covered interval
            }
            // Otherwise, it's not covered, keep it and update the last end
            lastIntervalValue = intervals[i][1];
            count++;
        }

        return count;
    }
};

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;

        // Custom comparator
        auto lambda = [](vector<int> &vec1, vector<int> &vec2) {
            if (vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }
            return vec1[0] < vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        // Push the first interval as the first kept one
        result.push_back(intervals[0]);

        for (int i = 1; i < n; ++i) {
            // If the current interval's end is covered by the last kept interval, skip
            if (result.back()[1] >= intervals[i][1]) {
                continue;
            }
            // Otherwise, it's a new uncovered interval
            result.push_back(intervals[i]);
        }

        return result.size();
    }
};

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;

        // Custom comparator
        auto lambda = [](vector<int> &vec1, vector<int> &vec2) {
            if (vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }
            return vec1[0] < vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        result.push_back(intervals[0]);

        for (int i = 1; i < n; ++i) {
            // Check if the current interval is fully covered by the last kept one
            if (result.back()[0] <= intervals[i][0] && result.back()[1] >= intervals[i][1]) {
                continue;   // covered, so skip
            }
            // Not covered – keep it
            result.push_back(intervals[i]);
        }

        return result.size();
    }
};