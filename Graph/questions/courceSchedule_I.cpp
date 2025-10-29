#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

/**

    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    Return true if you can finish all courses. Otherwise, return false.

Example: 1
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0. So it is possible.

Example: 2
    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.

 */


class Solution {
    bool haiCycle(int source, vector<bool> &visited, vector<bool> &rec, vector<vector<int>>& graph) {
        visited[source] = true;
        rec[source] = true;

        for (int i = 0; i < graph.size(); ++i) {
            int u = graph[i][1];
            int v = graph[i][0];

            if (u == source) {
                if (!visited[v]) {
                    if(haiCycle(v, visited, rec, graph)) return true;
                } else {
                    if (rec[v]) return true;
                }
            }
        }

        rec[source] = false;
        return false;
    }

public:
    bool canFinish(int V, vector<vector<int>>& graph) {
        vector<bool> visited(V, false);
        vector<bool> rec(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (haiCycle(i, visited, rec, graph)) return false;
            }
        }

        return true;
    }
};