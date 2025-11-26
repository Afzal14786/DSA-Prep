#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int help(string s1, int n, string s2, int m) {
    if (n == 0 || m == 0) return 0;
    int ans = 0;

    if (s1[n-1] == s2[m-1]) {
        ans += 1 + help(s1, n-1, s2, m-1);
    } else {
        // there is two cases
        int case1 = help(s1, n-1, s2, m);
        int case2 = help(s1, n, s2, m-1);

        ans += max(case1, case2);
    }

    return ans;
}

int longestCommonSubSequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // cout << "Size of the s1 is : " << n << " & size of the s2 is : " << m << endl;
    return help(s1, n, s2, m);
}

// way two

int lcsRec(string s1, string s2)  {
    int n = s1.size(), m = s2.size();

    if (n == 0 || m == 0) return 0;

    if (s1[n-1] == s2[m-1]) {
        return 1 + lcsRec(s1.substr(0, n-1), s2.substr(0, m-1));
    } else {
        int case1 = lcsRec(s1.substr(0, n-1), s2);
        int case2 = lcsRec(s1, s2.substr(0, m-1));
        return max(case1, case2);
    }
}

int main() {
    string s1 = "abedge";
    string s2 = "abedg";

    cout << "Longest Common Subsequence : " << longestCommonSubSequence(s1, s2) << endl;
    cout << "Longest Common Subsequence : " << lcsRec(s1, s2) << endl;
    return 0;
}