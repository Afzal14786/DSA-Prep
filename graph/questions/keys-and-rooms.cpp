/**
 * Problem: Keys and Rooms
 * -------------------------------------------------
 * There are n rooms labeled 0 to n-1. All rooms are locked except room 0.
 * When you visit a room, you may find a set of distinct keys that unlock other rooms.
 * You can collect all keys and use them later.
 * Determine if you can visit all the rooms.
 *
 * Approach 1: Depth-First Search (Recursive)
 * --------------------------------------------
 * Start from room 0, mark it as visited, and recursively visit all rooms whose keys
 * we have collected. This explores as deep as possible. At the end, check if all rooms
 * have been visited.
 *
 * Time Complexity  : O(n + k), where n = number of rooms, k = total number of keys.
 *                    Each room and each key is processed once.
 * Space Complexity : O(n) for the visited array and recursion stack in worst case.
 *
 * @see https://leetcode.com/problems/keys-and-rooms/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * Recursive DFS to visit rooms reachable from the current room.
     * @param currentRoom   The room we are currently visiting.
     * @param rooms         The input rooms array containing keys in each room.
     * @param visited       Boolean array marking visited rooms.
     */
    void depthFirstSearch(int currentRoom, std::vector<std::vector<int>>& rooms,
                          std::vector<bool>& visited) {
        // Mark the current room as visited.
        visited[currentRoom] = true;

        // For each key found in this room, if the corresponding room is not yet visited,
        // recursively explore that room.
        for (int key : rooms[currentRoom]) {
            if (!visited[key]) {
                depthFirstSearch(key, rooms, visited);
            }
        }
    }

    /**
     * Main function to check if we can visit all rooms.
     * @param rooms The input rooms array.
     * @return true if all rooms can be visited, false otherwise.
     */
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        int totalRooms = rooms.size();
        std::vector<bool> visited(totalRooms, false);

        // Start DFS from room 0.
        depthFirstSearch(0, rooms, visited);

        // Check if any room remains unvisited.
        for (bool roomVisited : visited) {
            if (!roomVisited) return false;
        }
        return true;
    }
};

// ----------------------------------------------------------------------------

/**
 * Approach 2: Breadth-First Search (Iterative)
 * ---------------------------------------------
 * Start from room 0, mark it visited, and use a queue to explore rooms level by level.
 * When we visit a room, we collect all its keys and enqueue any newly unlocked rooms.
 * After BFS finishes, verify that all rooms have been visited.
 *
 * Time Complexity  : O(n + k), where n = number of rooms, k = total number of keys.
 * Space Complexity : O(n) for the visited array and the queue in worst case.
 */
#include <queue>

class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        int totalRooms = rooms.size();
        std::queue<int> bfsQueue;                 // Queue for BFS traversal.
        std::vector<bool> visited(totalRooms, false);

        // Start from room 0.
        bfsQueue.push(0);
        visited[0] = true;

        // Process rooms level by level.
        while (!bfsQueue.empty()) {
            int currentRoom = bfsQueue.front();
            bfsQueue.pop();

            // For each key obtained from the current room,
            // if the key's room is not yet visited, mark it and enqueue it.
            for (int key : rooms[currentRoom]) {
                if (!visited[key]) {
                    visited[key] = true;
                    bfsQueue.push(key);
                }
            }
        }

        // After BFS, if any room is still unvisited, we cannot visit all rooms.
        for (bool roomVisited : visited) {
            if (!roomVisited) return false;
        }
        return true;
    }
};