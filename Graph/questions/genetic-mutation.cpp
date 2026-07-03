/**
 * @brief Finds the minimum number of mutations needed to transform startGene
 *        into endGene, where each mutation changes exactly one character.
 *
 * @details
 * A gene string is 8 characters long, with characters from {'A','C','G','T'}.
 * A mutation is a single‑character change. The gene bank contains all valid
 * intermediate strings. The startGene is assumed valid (may not be in bank).
 * We need the shortest path (minimum mutations) from startGene to endGene
 * using only strings that are in the bank (or the start/end themselves).
 *
 * **Solution Approach:**
 * This is a classic **shortest‑path in an unweighted graph** problem.
 * - Nodes are gene strings (all strings of length 8 over the 4 letters).
 * - Edges exist between two strings if they differ by exactly one character.
 * - We only consider nodes that are in the bank (plus the start and end).
 *
 * We use **Breadth‑First Search (BFS)** because it gives the minimum number
 * of steps (mutations) in an unweighted graph.
 *
 * **Algorithm Steps:**
 * 1. Store the bank in an unordered_set for O(1) lookup.
 * 2. Use a queue for BFS, starting with `startGene`.
 * 3. Maintain a visited set to avoid revisiting genes.
 * 4. For each gene popped from the queue, generate all possible 1‑mutation
 *    neighbours (8 positions × 4 characters = 32 candidates).
 * 5. If a neighbour is in the bank and not visited, add it to the queue,
 *    mark it visited.
 * 6. Track the BFS level (number of mutations so far). If we pop `endGene`,
 *    return the current level.
 * 7. If the queue empties without finding `endGene`, return -1.
 *
 * @param startGene  Initial gene string (length 8).
 * @param endGene    Target gene string (length 8).
 * @param bank       Vector of valid gene strings (may be empty).
 * @return int       Minimum number of mutations, or -1 if impossible.
 *
 * @par Complexity
 * - **Time:** O(32 * N) ≈ O(N), where N is the number of distinct gene
 *   strings reachable from start (bounded by bank size + 1).
 *   For each node, we generate at most 8×4 = 32 neighbours, each checked in O(1).
 * - **Auxiliary Space:** O(N) for the visited set and the queue.
 *   In the worst case, we may store all genes in bank.
 *
 * @par Examples
 * - start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"] → output 1.
 * - start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"] → output 2.
 *
 * @see https://leetcode.com/problems/minimum-genetic-mutation/
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Quick lookup for valid genes
        unordered_set<string> bankSet(bank.begin(), bank.end());

        // BFS structures
        queue<string> q;
        unordered_set<string> visited;

        q.push(startGene);
        visited.insert(startGene);

        int mutations = 0;  // BFS level (number of mutations taken)

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                string current = q.front();
                q.pop();

                // If we reached the target, return the number of mutations so far
                if (current == endGene) return mutations;

                // Try all possible 1‑character mutations
                for (char ch : "ACGT") {          // all four possible letters
                    for (int pos = 0; pos < 8; ++pos) {
                        string neighbour = current;
                        neighbour[pos] = ch;

                        // Only consider if it's in the bank and not yet visited
                        if (visited.find(neighbour) == visited.end() &&
                            bankSet.find(neighbour) != bankSet.end()) {
                            visited.insert(neighbour);
                            q.push(neighbour);
                        }
                    }
                }
            }
            mutations++;   // after processing all nodes at this level, increment step count
        }

        return -1;  // endGene not reachable
    }
};