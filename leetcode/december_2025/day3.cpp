// You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
// Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.
// A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel if and only if they have the same slope.

// Example 1:

// Input: points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]
// Output: 2

// Explanation:
// There are two distinct ways to pick four points that form a trapezoid:

//     The points [-3,2], [2,3], [3,2], [2,-3] form one trapezoid.
//     The points [2,3], [3,2], [3,0], [2,-3] form another trapezoid.

// Example 2:

// Input: points = [[0,0],[1,0],[0,1],[2,1]]
// Output: 1

// Explanation:

// There is only one trapezoid which can be formed.

// Constraints:
//     4 <= points.length <= 500
//     –1000 <= xi, yi <= 1000
//     All points are pairwise distinct

// Question Link : https://leetcode.com/problems/count-number-of-trapezoids-ii/?envType=daily-question&envId=2025-12-03
// Solution Link : 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    typedef map<int, int> M;

    P getSlope(int x1, int x2, int y1, int y2) {
        int dx = (x1 - x2);
        int dy = (y1 - y2);

        bool flag = true;
        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }

        if (dx == 0) return {1, 0};
        if (dy == 0) return {0, 1};

        int gcd = __gcd(abs(dx), abs(dy));

        return {dy/gcd, dx/gcd};
    }

    int countTrapezoids(vector<vector<int>> &points) {
        map<P, M> mp;
        map<P, int> mids;
        map<P, map<P, int>> mids_diff;
        int pg = 0;
        int n = points.size();

        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                P slope = getSlope(x1, x2, y1, y2);

                int intercept = y1 * slope.second - x1 * slope.first;

                mp[slope][intercept]++;

                int mx = points[i][0] + points[j][0];
                int my = points[i][1] + points[j][1];

                pg += (mids[{mx, my}] - mids_diff[{mx, my}][slope]);
                mids[{mx, my}]++;
                mids_diff[{mx, my}][slope]++;
            }
        }

        int ans = 0;
        for (auto i : mp) {
            int edges = 0;
            for (auto j : i.second) {
                int count = j.second;
                ans += (edges * count);
                edges += count;
            }
        }

        return ans - pg;
    }
};