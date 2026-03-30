// Question Link : https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool checkStrings(string& s1, string& s2) {
        array<int, 52> freq{};
        const int n=s1.size();
        for(int i=0; i<n; i++){
            bool iOdd=i&1;
            freq[iOdd*26+s1[i]-'a']++;
            freq[iOdd*26+s2[i]-'a']--;
        }
        return all_of(freq.begin(), freq.end(), [](int x){return x==0;});
    }
};
