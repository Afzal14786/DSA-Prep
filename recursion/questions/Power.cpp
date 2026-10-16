#include <iostream>
using namespace std;

// way 1

int power1(int m, int n) {
    if (n == 0) {
        return 1;
    }

    return power1(m, n-1) * m;
}


// enhanced way 
int power(int m, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return power(m*m, n/2);
    } else {
        return m * power(m*m, (n-1)/2);
    }
}


// using bit manipulation the pow(n, x)
int bitPower(int n, int x) {
    int ans = 1;

    while (x > 0) {
        int lastDigit = x & 1;
        if (lastDigit) {
            // fixing + to * => previousl it was ans += n now it is : ans *= n
            ans *= n;
        }
        n *= n;
        x = x >> 1;
    }

    return ans;
}

// best optimize solution for this problem using bit manipulatio with all the edge cases 

double myPower2(double x, int n) {
    if (x == 0) {
        return (n == 0) ? 1.0 : 0.0;
    }

    long long N = n;

    if (N < 0) {
        x = 1/x;
        N = -N;
    }

    double ans = 1.0;

    while (N > 0) {
        if (N & 1) {
            ans *= x;
        }
        x *= x;
        N >>= 1;
    }

    return ans;
}

int main() {
    // cout << power1(2,5) << endl;
    // cout << bitPower(2,5) << endl;      // not correct trying to fix it . 
    cout << "Answer : " << myPower2(2, 5) << endl;
    return 0;
}