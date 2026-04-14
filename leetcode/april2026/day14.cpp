// Question Link : https://leetcode.com/problems/minimum-total-distance-traveled/description/?envType=daily-question&envId=2026-04-14

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Solution {
public:
    long long solve(int robotIdx, int factoryIdx, std::vector<int> &robot, std::vector<int> &positions, std::vector<std::vector<long long>> &t) {
        if (robotIdx >= robot.size()) return 0;

        if (factoryIdx >= positions.size()) return 1e12;
        if (t[robotIdx][factoryIdx] != -1) return t[robotIdx][factoryIdx];

        long long take_curr_factory = abs(robot[robotIdx] - positions[factoryIdx]) + solve(robotIdx+1, factoryIdx+1, robot, positions, t);
        long long skip = solve(robotIdx, factoryIdx+1, robot, positions, t);

        return t[robotIdx][factoryIdx] = std::min(take_curr_factory, skip);
    }

    long long minimumTotalDistance(std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
        std::sort(robot.begin(), robot.end());
        std::sort(begin(factory), end(factory));

        std::vector<int> positions;
        for (int i = 0; i < factory.size(); ++i) {
            int pos = factory[i][0];
            int limit = factory[i][1];

            for (int j = 0; j < limit; ++j) {
                positions.push_back(pos);
            }
        }

        int m = robot.size();
        int n = positions.size();

        std::vector<std::vector<long long>> t(m+1, std::vector<long long>(n+1, -1));


        return solve(0, 0, robot, positions, t);
    }
};