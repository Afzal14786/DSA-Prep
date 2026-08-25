// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// brute force solution
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            bool placed = false;
            for (int j = 0; j < n; ++j) {
                if (baskets[j] >= fruits[i]) {
                    baskets[j] = -1;
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                count++;
            }
        }
        return count;
    }
};
