// Question Link : https://leetcode.com/problems/destroying-asteroids/?envType=daily-question&envId=2026-05-31

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // let first sort the asteroids
        sort(asteroids.begin(), asteroids.end());

        for (int &m : asteroids) {
            if (m > mass) return false;
            else if (mass >= 1e5) return true;
            mass += m;
        }

        return true;
    }
};
