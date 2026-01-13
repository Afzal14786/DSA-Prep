/**
 * Separate Squares I
 * Question Link : https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13
 * Solution Link : https://leetcode.com/problems/separate-squares-i/submissions/1883539480/?envType=daily-question&envId=2026-01-13
 */

// You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
// Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.
// Answers within 10^-5 of the actual answer will be accepted.
// Note: Squares may overlap. Overlapping areas should be counted multiple times.

// Example 1:

// Input: squares = [[0,0,1],[2,2,1]]
// Output: 1.00000

// Explanation:
// Any horizontal line between y = 1 and y = 2 will have 1 square unit above it and 1 square unit below it. The lowest option is 1.

// Example 2:

// Input: squares = [[0,0,2],[1,1,1]]
// Output: 1.16667

// Explanation:
// The areas are:

//  Below the line: 7/6 * 2 (Red) + 1/6 (Blue) = 15/6 = 2.5.
//  Above the line: 5/6 * 2 (Red) + 5/6 (Blue) = 15/6 = 2.5.
// Since the areas above and below the line are equal, the output is 7/6 = 1.16667.

// Constraints:

//  1 <= squares.length <= 5 * 10^4
//  squares[i] = [xi, yi, li]
//  squares[i].length == 3
//  0 <= xi, yi <= 10^9
//  1 <= li <= 10^9
//  The total area of all the squares will not exceed 10^12.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(long double y, vector<vector<int>> &squares, long double totalArea) {
        long double part2 = 0;
        for (auto &i : squares) {
            double Y = i[1];
            long double side = i[2];
            if (Y >= y) {

            } else {
                double finalY = Y + i[2];
                if (finalY <= y) {
                    part2 += side * side;
                } else {
                    part2 += (y - Y) * side;
                }
            }
        }

        return part2 < totalArea / 2;
    }

    double separateSquares(vector<vector<int>>& squares) {
        long double low = 0, high = 0;
        double ans = 1e9;
        long double totalArea = 0;

        for (auto &i : squares) {
            double y = i[1];
            long double side = i[2];
            totalArea += side * side;
            high = max(high, y + side);
        }

        int count = 0;
        while (high - low >= 1e-6 && count < 60) {
            long double mid = (low + high) / 2;
            count++;
            if (check(mid, squares, totalArea)) {
                low = mid;
                ans = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }
};


class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total_area = 0;
        vector<tuple<int, int, int>> events;
        for (const auto& sq : squares) {
            int y = sq[1], l = sq[2];
            total_area += (long long)l * l;
            events.emplace_back(y, l, 1);
            events.emplace_back(y + l, l, -1);
        }
        // sort by y-coordinate
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return get<0>(a) < get<0>(b);
        });

        double covered_width =
            0;  // sum of all bottom edges under the current scanning line
        double curr_area = 0;    // current cumulative area
        double prev_height = 0;  // height of the previous scanning line
        for (const auto& [y, l, delta] : events) {
            int diff = y - prev_height;
            // additional area between two scanning lines
            double area = covered_width * diff;
            // if this part of the area exceeds more than half of the total area
            if (2LL * (curr_area + area) >= total_area) {
                return prev_height +
                       (total_area - 2.0 * curr_area) / (2.0 * covered_width);
            }
            // update width: add width at the start event, subtract width at the
            // end event
            covered_width += delta * l;
            curr_area += area;
            prev_height = y;
        }

        return 0.0;
    }
};