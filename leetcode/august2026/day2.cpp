// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/stone-game/submissions/2090808547/?envType=daily-question&envId=2026-08-02
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // With even number of piles and odd total sum, Alice always wins.
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,3,4,5};
    cout << ((s.stoneGame(nums)) ? "True" : "False") << endl;
    return 0;
}