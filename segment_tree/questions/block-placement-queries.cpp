// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// brute force soluiton 
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> res;
        set<int> st;  // ordered set to store the opticals

        for (auto &query : queries) {
            if (query[0] == 1) {  // type 1 query
                st.insert(query[1]);  // store the opticals
            } else { // type 2 query
                int x = query[1];
                int sz = query[2];
                int prev = 0;

                bool found = false;

                for (int curr : st) {
                    if (curr > x) break;
                    if (curr - prev >= sz) {
                        found = true;
                        break;
                    }

                    prev = curr;
                }

                if (!found) {
                    found = (x - prev >= sz);
                }

                res.push_back(found);
            }
        }

        return res;
    }
};