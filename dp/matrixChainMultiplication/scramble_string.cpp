// Question Link : https://leetcode.com/problems/scramble-string/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// exponential time complexity : O(N^N)
// space complexity : O(N) internal stack because of recursion 

class RecursionSolution {
public:
    bool solve(string str1, string str2) {
        if (str1.compare(str2) == 0) return true;
        if (str1.size() <= 1) return false;
        int n = str1.size();

        bool flag = false;

        for (int i = 1; i < n; ++i) {
            bool condition1 = solve(str1.substr(0, i), str2.substr(n-i, i)) && solve(str1.substr(i, n-i), str2.substr(0, n-i));
            bool condition2 = solve(str1.substr(0, i), str2.substr(0, i)) && solve(str1.substr(i, n-i), str2.substr(i, n-i));

            if (condition1 || condition2) {
                flag = true;
                break;
            }
        }

        return flag;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size(),  m = s2.size();

        if (n != m) return false;
        if (n == 0 || m == 0) return false;  // if any one string is empty
        return solve(s1, s2);
    }
};

// Memoization 
// using map
class Solution {
public:
    unordered_map<string, bool> mpp;
    bool solve(string str1, string str2) {
        if (str1.compare(str2)) return true;
        if (str1.size() <= 1) return false;

        // now generate a unique key for str1 and str2
        // example : str1$str2 -> can be a key
        string key = str1;
        key.push_back('$');
        key.append(str2);

        if (mpp.find(key) != mpp.end()) return mpp[key];

        int n = str1.size();
        bool flag = false;
        for (int i = 1; i < n; ++i) {
            bool condition1 = solve(str1.substr(0, i), str2.substr(n-i, i)) && solve(str1.substr(i, n-i), str2.substr(i, n-i));
            bool condition2 = solve(str1.substr(0, i), str2.substr(0, i)) && solve(str1.substr(i, n-i), str2.substr(i, n-i));

            if (condition1 || condition2) {
                flag = true;
                break;
            }
        }

        return mpp[key] = flag;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if (n != m) return false;
        if (n == 0 || m == 0) return false;
        mpp.clear();
        return solve(s1, s2);
    }
};

class Solution {
    // Memoization table using a string key to represent pairs (s1, s2)
    unordered_map<string, bool> memo;

public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        // Pruning: If character counts don't match, it's not a scramble
        vector<int> count(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int c : count) {
            if (c != 0) return memo[key] = false;
        }

        int n = s1.length();
        for (int i = 1; i < n; i++) {
            // Case 1: No Swap
            // Left matches Left, Right matches Right
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Swap
            // Left matches Right, Right matches Left
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};


int main() {
    Solution s1;
    string str1 = "great";
    string str2 = "rgeat";

    bool answer = s1.isScramble(str1, str2);

    if (answer) {
        cout << "Yes the string is scrambled.\n";
    } else {
        cout << "No the string is not scrambled.\n";
    }

    return 0;
}