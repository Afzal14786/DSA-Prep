
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/?envType=daily-question&envId=2026-08-08

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();

        int R = M - 1;
        int C = 0;

        vector<int> Right(N);
        for (int i = N - 1; i >= 0; i--) {
            Right[i] = C;
            if (R >= 0 && word1[i] == word2[R]) {
                R--;
                C++;
            }
        }

        vector<int> ans;
        bool changed = false;
        int j = 0; // pointer for word2

        for (int i = 0; i < N && j < M; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!changed && Right[i] >= M - 1 - j) {
                // Spend our one allowed substitution here
                ans.push_back(i);
                j++;
                changed = true;
            }
        }

        return (j == M) ? ans : vector<int>();
    }
};
