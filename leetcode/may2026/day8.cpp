// Question Link : https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/?envType=daily-question&envId=2026-05-08
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


class Solution {
public:
    int minJumps(std::vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        
        std::vector<bool> prime(mx+1, true);
        prime[0] = false;
        prime[1] = false;
        for (long long i=2; i<=mx; i++) {
            if (prime[i]) {
                for (long long j=i*i; j<=mx; j+=i) {
                    prime[j] = false;
                }
            }
        }

        std::vector<std::vector<int>> pos(mx+1);
        for (int i=0; i<n; i++) {
            pos[nums[i]].push_back(i);
        }

        std::queue<std::pair<int, int>> q;
        q.push({0, 0});
        std::vector<int> vis(n);
        vis[0] = 1;
        while (!q.empty()) {
            auto [i, t] = q.front();
            q.pop();

            if (i == n-1) return t;

            if (i > 0 && !vis[i-1]) {
                q.push({i-1, t+1});
                vis[i-1] = 1;
            }
            if (i < n-1 && !vis[i+1]) {
                q.push({i+1, t+1});
                vis[i+1] = 1;
            }

            if (prime[nums[i]]) {
                int p = nums[i];
                for (int m=p; m<=mx; m+=p) {
                    for (int j: pos[m]) {
                        if (!vis[j]) {
                            q.push({j, t+1});
                            vis[j] = 1;
                        }
                    }
                    pos[m].clear();
                }
                prime[p] = false; 
            }
        }
        return n-1;
    }
};
