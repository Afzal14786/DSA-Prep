
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-divisible-digit-product-ii/?envType=daily-question&envId=2026-08-07

class Solution {
public:
    typedef long long ll;

    string free_slots_filler(ll required, int length) {
        string str;

        for(int digit = 9; digit >= 2; digit--) {
            while(required % digit == 0) {
                str.push_back(digit + '0');
                required /= digit;
            }
        }

        while(str.length() < length) {
            str.push_back('1');
        }

        reverse(begin(str), end(str));

        return str;
    }

    string smallestNumber(string num, long long t) {
        int n = num.length();

        ll temp = t;
        for(int prime_fact : {2, 3, 5, 7}) {
            while(temp % prime_fact == 0) {
                temp /= prime_fact;
            }
        }

        if(temp != 1) {
            return "-1";
        }

        //Precompute remainingFactor[i] = if we take i digits of num in my result, what factor remaining for t
        vector<ll> remaining_factor(n+1, t);
        //"123045"
        for(int i = 0; i < n; i++) {
            int digit = num[i] - '0';

            if(digit == 0) {
                break;
            }

            remaining_factor[i+1] = remaining_factor[i]/gcd(remaining_factor[i], (ll)digit);
        }

        if(remaining_factor[n] == 1) { //the input itself is sufficient for t
            return num;
        }

        int zero_pos = num.find('0');
        int zero_idx = n-1;
        if(zero_pos != -1) {
            zero_idx = zero_pos;
        }

        for(int i = zero_idx; i >= 0; i--) {
            ll required = remaining_factor[i];
            int freeSlots = n - 1 - i;

            for(int digit = (num[i] - '0')+1; digit <= 9; digit++) {
                ll further_required = required / gcd(required, digit);
                string required_number = free_slots_filler(further_required, freeSlots);

                if(required_number.length() == freeSlots) {
                    return num.substr(0, i) + char(digit + '0') + required_number;
                }
            }
        }

        return free_slots_filler(t, n+1); //num = "11", t = 2^15
    }
};

int main() {
    
    return 0;
}