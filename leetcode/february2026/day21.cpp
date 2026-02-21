// Question Link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/?envType=daily-question&envId=2026-02-21

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
        unordered_map<int,int> isPrime;

        for(int i: primes){
            isPrime[i]=1;
        }

        int count =0;

        for(int i=left;i<=right;i++){
            int setBits = __builtin_popcount(i);
            if(isPrime.count(setBits)){
                count++;
            }
        }

        return count;

    }
};
