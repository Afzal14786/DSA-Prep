// Question Link : https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/?envType=daily-question&envId=2026-04-12

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>


class Solution {
public:
    /**
     * @length 301
     * @position of first character
     * @position of second character
     */
    int memo[301][27][27];

    /**
     * @fuction dist 
     * @return Distance from character 1 to character 2
     */

    int distance(int c1, int c2) {
        if (c1 == 26) return 0;
        /**
         * Here we can get 
         * @cordinates
         * 'x' cordinates by divinding it with 6 because there are 6 columns in the alphabates / keyboard grid
         * 'y' cordinates by taking mode with the finger position
         */
        int x1 = c1 / 6, y1 = c1 % 6;
        int x2 = c2 / 6, y2 = c2 % 6;

        /**
         * @return |x1 - x2| + |y1 - y2|
         */
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int helper(int idx, int finger1, int finger2, const std::string &word) {
        if (idx == word.size()) return 0;

        /**
         * @approach -- Top Down Approach {Memoization}
         */

        if (memo[idx][finger1][finger2] != -1) return memo[idx][finger1][finger2];
        
        /**
         * now calculate what is the target here
         */
        int target = word[idx] - 'A';  // all the latters are in UPPER CASE
        /**
         * now everytime we have two choices, either finger 1 will type word[i] OR else finger 2 will type word[i]
         */

         // here finger 1 type word[i]
        int choice1 = distance(finger1, target) + helper(idx + 1, target, finger2, word);
        int choice2 = distance(finger2, target) + helper(idx + 1, finger1, target, word);

        // now store the minimum result and return 
        return memo[idx][finger1][finger2] = std::min(choice1, choice2);
    }

    int minimumDistance(std::string word) {
        std::memset(memo, -1, sizeof(memo));
        return helper(0,26,26, word);
    }
};