// Question Link : https://leetcode.com/problems/two-furthest-houses-with-different-colors/?envType=daily-question&envId=2026-04-20

#include <iostream>
#include <vector>

class Solution {
public:
    int maxDistance(std::vector<int>& colors) {
        int ans = 0;
        int n = colors.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (colors[i] != colors[j]) {
                    ans = std::max(ans, abs(i-j));
                }
            }
        }

        return ans;
    }
};

// optimize code 

class Solution {
public:
    int maxDistance(std::vector<int>& colors) {
        int ans = 0, n = colors.size();
        for (int i = n-1; i > 0; --i) {
            if (colors[i] != colors[0]) {
                ans = std::max(ans, i);
                break;
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            if (colors[i] != colors[n-1]) {
                ans = std::max(ans, (n-1) - i);
                break;
            }
        }

        return ans;
    }
};