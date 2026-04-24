// Question Link : https://leetcode.com/problems/furthest-point-from-origin/description/?envType=daily-question&envId=2026-04-24

#include <iostream>
#include <string>

class Solution {
public:
    int furthestDistanceFromOrigin(std::string moves) {
        int left = 0, right = 0, dash = 0;
        for (int i = 0; i < moves.size(); ++i) {
            if (moves[i] == 'L') left++;
            else if (moves[i] == 'R') right++;
            else dash++;
        }

        return abs(left - right) + dash;
    }
};