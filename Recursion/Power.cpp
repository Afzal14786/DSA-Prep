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

int main() {
    cout << power1(2,5) << endl;
    cout << bitPower(2,5) << endl;      // not correct trying to fix it . 
    return 0;
}