// Question Link : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2026-02-26

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        
        int carry =0;

        int ans =0;
        int n = s.size();
        for(int i=n-1;i>=1;i--){
            int bit = s[i]-'0';
            int val = (bit+carry)%2;
            carry = (carry+bit)/2;

            if(val==1){
                carry =1;
                ans+=2;
            }else{
                ans++;
            }
        }

        if(carry!=0){
            ans++;
        }
        return ans;
    }
};
