// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {

        ll xXora = 0;
        ll xXorb = 0;

        for(long long i = 49; i >= n; i--) {
            bool aset = (a >> i) & 1 > 0; //Finding the ith bit of a
            bool bset = (b >> i) & 1 > 0; //Finding the ith bit of b

            if(aset)
                xXora ^= (1ll << i);
            if(bset)
                xXorb ^= (1ll << i);
        }

       
        for (long long i = n-1; i >= 0; i--) {
            
            bool aset = (a & (1ll << i)) > 0; //Finding the ith bit of a
            bool bset = (b & (1ll << i)) > 0; //Finding the ith bit of b

            //If both ith bit of a and b are same
            if(aset == bset) {
                xXora ^= (1ll << i);
                xXorb ^= (1ll << i);
                continue;
            }
            
            if(xXora > xXorb) {
                xXorb ^= (1ll << i);
            } else {
                xXora ^= (1ll << i);
            }

        }   

        xXora %= M;
        xXorb %= M;
        return (xXora * xXorb) % M;
    }
};