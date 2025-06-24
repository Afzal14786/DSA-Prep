#include <iostream>
using namespace std;

// Tylor Series =>  

double TaylorSeries(int x, int n) {
    static double pow = 1.0, fact = 1.0;
    double ans;

    if (n == 0) {
        return 1;
    } else {
        ans = TaylorSeries(x, n-1);
        pow *= x;
        fact *= n;

        return ans + pow/fact;
    }
}

// Improved version of Taylor Series Using Hornor's Rule 

// using for loop
double TaylorSeries2(int x, int n) {
    double ans;

    if (n == 0) {
        return ans;
    }

    for (; n > 0; n--) {
        ans = 1 + (x * ans) / n;
    }

    return ans;
}

// using recursion

double TaylorSeries3(int x, int n) {
    static double ans;

    if (n == 0) {
        return ans;
    }
    ans = 1 + x*ans / n;
    return TaylorSeries3(x, n-1);
}

int main() {
    cout << TaylorSeries(2,5) << endl;
    cout << TaylorSeries2(2,10) << endl;
    cout << TaylorSeries3(2,10) << endl;
    return 0;
}