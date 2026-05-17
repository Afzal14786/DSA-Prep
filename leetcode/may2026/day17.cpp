// Question Link : https://leetcode.com/problems/jump-game-iii/?envType=daily-question&envId=2026-05-17
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(start);
        vis[start] = true;

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if(arr[i] == 0) return true;

            int forward = i + arr[i];
            int backward = i - arr[i];

            if(forward < n && !vis[forward]) {
                vis[forward] = true;
                q.push(forward);
            }

            if(backward >= 0 && !vis[backward]) {
                vis[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};
