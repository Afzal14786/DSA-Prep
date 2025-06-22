#include <iostream>
using namespace std;

// combination formula = n! / r! * (n-r)!

int fact(int x) {
    if (x == 1) {
        return x;
    }

    return x * fact(x-1);
}

int Combination(int n, int r) {
    int fact_n = fact(n);
    int fact_r = fact(r);
    int fact_n_r = fact(n-r);

    return fact_n / (fact_r * fact_n_r);
}

int Combination2(int n, int r) {
    return fact(n) / (fact(r) * fact(n-r));
}

int main() {
    cout << "Using Combination Formula Is : " << Combination2(5, 3) << endl;
    return 0;
}