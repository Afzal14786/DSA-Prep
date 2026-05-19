// Question Link : https://leetcode.com/problems/super-egg-drop/description/
// Question Link : https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
using namespace std;

// Recursive Solution
// Time complexity : O(e^f)
// space complexity : O(1)
class RecursionSolution {
public:
    int superEggDrop(int e, int f) {
        if (f == 0 || f == 1) return f;
        if (e == 0) return f;

        int mn = 1e9 + 7;
        
        for (int k = 1; k <= f; ++k) {
            int temp = 1 + max(superEggDrop(e-1, k-1), superEggDrop(e, f-k));
            mn = min(mn, temp);
        }
        return mn;
    }
};

// Memoization Solution
// this solution give TLE
// time complexity : O(egg * floor ^ 2)
// space complexity : O(egg * floor)

class Memoization {
public:
    int solve(int egg, int floor, vector<vector<int>> &dp) {
        if (floor == 0 || floor == 1) return floor;
        if (egg == 1) return floor;

        if (dp[egg][floor] != -1) return dp[egg][floor];

        int mn = 1e9 + 7;

        for (int k = 1; k <= floor; ++k) {
            // int temp = 1 + max(solve(egg-1, k-1, dp), solve(egg, floor-k, dp));
            dp[egg-1][k-1] = solve(egg-1, k-1, dp);
            dp[egg][floor-k] = solve(egg, floor-k, dp);

            int temp = 1 + max(dp[egg-1][k-1], dp[egg][floor-k]);
            mn = min(temp, mn);
        }

        return dp[egg][floor] = mn;
    }

    int superEggDrop(int egg, int floor) {
        vector<vector<int>> dp(egg+1, vector<int>(floor+1, -1));

        return solve(egg, floor, dp);
    }
};

/**
 * Another and better approach using tabulation
 * time complexity : O(egg * floor) OR say O(e * f)
 * space complexity : O(egg * floor) OR say O(e * f)
 */

class Solution {
public:
    int superEggDrop(int e, int f) {
        // base case
        if (f <= 1) return f;
        if (e == 1) return f;
        int max_moves = f;
        vector<vector<int>> dp(max_moves + 1, vector<int>(e + 1, 0));

        int count = 0;

        while (dp[count][e] < f) {
            count++;

            for (int k = 1; k <= e; ++k) {
                dp[count][k] = 1 + dp[count - 1][k-1] + dp[count-1][k];
            }
        }

        return count;
    }
};

// more better and optimize code 
// time complexity : O(e * f)
// space complexity : O(n)

class Solution {
public:
    int superEggDrop(int e, int f) {
        // base case
        if (f <= 1) return f;
        if (e == 1) return f;
        vector<int> dp(e+1, 0);

        int count = 0;

        while (dp[e] < f) {
            count++;
            for (int k = e; k > 0; --k) {
                dp[k] += 1 + dp[k - 1];
            }
        }

        return count;
    }
};

// this is the another problem
// question link : https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

class Solution2 {
public:
    int twoEggDrop(int n) {
        return std::ceil((-1.0 + sqrt(1 + 8*n)) / 2.0);
    }
};

int main() {
    Solution s;
    int e, f;
    cin >> e >> f;

    auto start = chrono::high_resolution_clock::now();
    int res = s.superEggDrop(e, f);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;

    cout << "Minimum no of ways : " << res << endl;
    cout << "Executation time it takes : " << duration.count() << " ms" << endl;
    return 0;
}