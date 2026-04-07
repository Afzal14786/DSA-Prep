// Question Link : https://leetcode.com/problems/walking-robot-simulation-ii/?envType=daily-question&envId=2026-04-07

// Solution 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct customDS {
    int x_axis, y_axis;
    string direction;
};

class Robot {
public:
    int idx = 0;
    bool moved = false;
    vector<customDS> path;

    Robot(int width, int height) {
        // now filling the boundries first were the robot moves
        // from left to right here the Y-Axis is constant

        for (int x = 0; x < width; ++x) {
            path.push_back({x, 0, "East"});
        }

        // now in the right boundry fill from 1 to top corner
        // here the X-Axis is constand
        for (int y = 1; y < height; ++y) {
            path.push_back({width-1, y, "North"});
        }

        // now at the top moves and store from right to left, we are moving from width - 2;
        // here the Y-Axis is constant

        for (int x = width-2; x >= 0; --x) {
            path.push_back({x, height-1, "West"});
        }

        // now in the left boudry we have to move from height-1 to 0
        for (int y = height-2; y > 0; --y) {
            path.push_back({0, y, "South"});
        }

        /**
         * Since we are having move flag so we can make the (0,0) as "South" for now, because 
         * if the robot don't move at all means it is facing east
         * and if the robot moves, means if moves == true, means at (0,0) robot is facing south
         */

        path[0] = {0,0, "South"};  // for now initially it is south
    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % path.size();
    }
    
    vector<int> getPos() {
        return {path[idx].x_axis, path[idx].y_axis};
    }
    
    string getDir() {
        string direction = path[idx].direction;
        if (!moved || direction == "East") return "East";
        else return direction;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */