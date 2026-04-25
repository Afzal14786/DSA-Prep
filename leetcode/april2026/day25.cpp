// Question Link : https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/?envType=daily-question&envId=2026-04-25

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    bool check(long long mid, int n, int k, long long perimeter, const std::vector<long long>& circ) {
        // We only need to check starting points within the first 'jump' range
        // because the points are periodic.
        for (int i = 0; i < n; ++i) {
            int count = 1;
            int curr = i;
            bool possible = true;
            
            for (int j = 1; j < k; ++j) {
                // Find the first point that is at least 'mid' distance away
                auto it = lower_bound(circ.begin() + curr + 1, circ.begin() + i + n, circ[curr] + mid);
                if (it == circ.begin() + i + n) {
                    possible = false;
                    break;
                }
                curr = distance(circ.begin(), it);
            }
            
            if (possible) {
                // Check if the distance from the last point back to the first point is >= mid
                if (circ[i] + perimeter - circ[curr] >= mid) {
                    return true;
                }
            }
            
            // Optimization: If the first gap is already too large, 
            // checking more starting points won't help much.
            if (circ[i+1] - circ[i] > mid) continue; 
        }
        return false;
    }

    int maxDistance(int side, std::vector<std::vector<int>>& points, int k) {
        int n = points.size();
        std::vector<long long> pos;
        
        // Map 2D coordinates to 1D perimeter distance
        for (auto& p : points) {
            long long x = p[0], y = p[1];
            if (y == 0) pos.push_back(x);
            else if (x == side) pos.push_back(side + y);
            else if (y == side) pos.push_back(2LL * side + (side - x));
            else pos.push_back(3LL * side + (side - y));
        }
        
        sort(pos.begin(), pos.end());
        
        long long perimeter = 4LL * side;
        std::vector<long long> circ = pos;
        for (int i = 0; i < n; ++i) {
            circ.push_back(pos[i] + perimeter);
        }

        long long low = 1, high = perimeter / k;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, n, k, perimeter, circ)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};