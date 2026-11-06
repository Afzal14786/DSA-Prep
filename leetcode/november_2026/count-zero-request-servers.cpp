// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : leetcode.com/problems/count-zero-request-servers/description/?envType=daily-question&envId=2026-11-06

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int m = queries.size();
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) q.emplace_back(queries[i], i);
        sort(q.begin(), q.end());
        vector<int> ans(m);
        unordered_map<int, int> freq;
        int active = 0;
        int left = 0, right = 0;
        int L = logs.size();
        for (auto& [time, idx] : q) {
            while (right < L && logs[right][1] <= time) {
                int s = logs[right][0];
                if (++freq[s] == 1) active++;
                right++;
            }
            while (left < right && logs[left][1] < time - x) {
                int s = logs[left][0];
                if (--freq[s] == 0) active--;
                left++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();