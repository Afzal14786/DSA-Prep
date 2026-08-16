
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/stone-game-ix/description/?envType=daily-question&envId=2026-08-16

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int a = 0, b = 0, c = 0;
        for (int i : stones) {
            if (i % 3 == 0) a++;
            else if (i % 3 == 1) b++;
            else c++;
        }

        if (a % 2 == 0) return b > 0 && c > 0;

        return abs(b - c) > 2;
    }
};