// Question Link : https://leetcode.com/problems/count-the-number-of-special-characters-i/?envType=daily-question&envId=2026-05-26

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
    static int numberOfSpecialChars(string& word) {
        bitset<26> a=0, A=0;
        for(char c: word){
            if (c>='a') a[c-'a']=1;
            else A[c-'A']=1;
        }
        a=a&A;
        return a.count();
    }
};


