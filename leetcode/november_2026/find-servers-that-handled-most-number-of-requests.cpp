// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/?envType=daily-question&envId=2026-11-09

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        for (int i = 0; i < k; ++i) free.insert(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> cnt(k);
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            long long t = arrival[i];
            while (!busy.empty() && busy.top().first <= t) {
                free.insert(busy.top().second);
                busy.pop();
            }
            if (free.empty()) continue;
            int pref = i % k;
            auto it = free.lower_bound(pref);
            if (it == free.end()) it = free.begin();
            int s = *it;
            free.erase(it);
            ++cnt[s];
            busy.emplace(t + load[i], s);
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            if (cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();