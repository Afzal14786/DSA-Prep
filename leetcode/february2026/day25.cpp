// Question Link : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=daily-question&envId=2026-02-25

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool check(int a,int b){
        int setBits1 = __builtin_popcount(a);
        int setBits2 = __builtin_popcount(b);

        if(setBits1 == setBits2){
            return a<b;
        }

        return setBits1<setBits2;

    }
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),check);
        return arr;
    }
};
