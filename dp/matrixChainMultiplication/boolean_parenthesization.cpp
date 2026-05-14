// Question Link : https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// User function Template for C++
class Recursion {
  public:
    int ways(string &s, int i, int j, bool isTrue) {
        // base-case
        if (i > j) return 0;
        if (i == j) {
            return (isTrue == (s[i] == 'T')) ? 1 : 0;
        }

        int ans = 0;
        for (int k = i+1; k < j; k +=2) {
            int leftTrue = ways(s, i, k-1, true);
            int leftFalse = ways(s, i, k-1, false);
            int rightTrue = ways(s, k+1, j, true);
            int rightFalse = ways(s, k+1, j, false);

            // now calculte the ways
            if (s[k] == '&') {
                if (isTrue) {
                    ans += leftTrue * rightTrue;
                } else {
                    ans += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
                }
            } else if (s[k] == '|') {
                if (isTrue) {
                    ans += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftTrue * rightTrue);
                } else {
                    ans += leftFalse * rightFalse;
                }
            } else if (s[k] == '^') {
                if (isTrue) {
                    ans += (leftTrue * rightFalse) + (leftFalse * rightTrue);
                } else {
                    ans += (leftFalse * rightFalse) + (leftTrue * rightTrue);
                }
            }
        }

        return ans;
    }

    int countWays(string &s) {
        // code here
        int n = s.size();
        return ways(s, 0, n-1, true);
    }
};

/**
 * Solution Approach 2
 */

// User function Template for C++
class Approach2 {
  public:
    
    /**
     * we can also check the evaluation in a saprate function like : 
    */

    bool evaluate(bool left, bool right, char op) {
        if (op == '|') return left | right;
        else if (op == '^') return left ^ right;
        return left & right;
    }

    int solveWays(string &str, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) return (isTrue == (str[i] == 'T')) ? 1 : 0;

        int count = 0;

        for (int k = i+1; k < j; k +=2) {
            // calculate true & false for left sub problems
            int leftTrue = solveWays(str, i, k-1, true);
            int leftFalse = solveWays(str, i, k-1, false);

            // calculating true & false for right sub problems
            int rightTrue = solveWays(str, k+1, j, true);
            int rightFalse = solveWays(str, k+1, j, false);

            if (evaluate(true, true, str[k]) == isTrue) count += leftTrue * rightTrue;
            if (evaluate(true, false, str[k]) == isTrue) count += leftTrue * rightFalse;
            if (evaluate(false, true, str[k])  == isTrue) count += leftFalse * rightTrue;
            if (evaluate(false, false, str[k]) == isTrue) count += leftFalse * rightFalse;
        }

        return count;
    }

    int countWays(string &s) {
        // code here

        int n = s.size();
        return solveWays(s, 0, n-1, true);
    }
};


/**
 * Optimization 
 */

// User function Template for C++
class Solution {
  public:
    unordered_map<string, int> mpp;

    bool evaluation(bool left, bool right, char op) {
        if (op == '&') return left & right;
        else if (op == '|') return left | right;
        return left ^ right;
    }

    int solveWays(string &str, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) return (isTrue == (str[i] == 'T')) ? 1 : 0;

        // now check do we have answer inside map, if yes then return from here 
        string temp = to_string(i);
        temp.push_back('_');
        temp.append(to_string(j));
        temp.push_back('_');
        temp.append(to_string(isTrue));

        if (mpp.find(temp) != mpp.end()) return mpp[temp];

        int count = 0;
        for (int k = i+1; k < j; k += 2) {
            // calculating true & false both for left sub-problem
            int leftTrue = solveWays(str, i, k-1, true);
            int leftFalse = solveWays(str, i, k-1, false);
            
            // calculating true & false both for right sub-problem
            int rightTrue = solveWays(str, k+1, j, true);
            int rightFalse = solveWays(str, k+1, j, false);

            if (evaluation(true, true, str[k]) == isTrue) count += leftTrue * rightTrue;
            if (evaluation(true, false, str[k]) == isTrue) count += leftTrue * rightFalse;
            if (evaluation(false, true, str[k]) == isTrue) count += leftFalse * rightTrue;
            if (evaluation(false, false, str[k]) == isTrue) count += leftFalse * rightFalse;
        }

        return mpp[temp] = count;
    }

    int countWays(string &s) {
        // code here
        mpp.clear();
        return solveWays(s, 0, s.size()-1, true);
    }
};

int main() {
    Solution s;
    Approach2 sol;
    string str;
    cin >> str;

    cout << "# of ways we can parenthesis the expressing : " << s.countWays(str) << endl;
    cout << "# of ways we can parenthesis the expressing : " << sol.countWays(str) << endl;
    return 0;
}