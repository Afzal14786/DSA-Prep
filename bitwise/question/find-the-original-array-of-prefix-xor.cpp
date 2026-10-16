// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        if (n == 1) return pref;
        vector<int> ans(n);
        ans[0] = pref[0];

        for (int i = 1; i < n; ++i) ans[i] = pref[i] ^ pref[i - 1];
        return ans;
    }
};