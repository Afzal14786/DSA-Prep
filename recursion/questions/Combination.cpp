#include <iostream>
using namespace std;

// combination formula = n! / r! * (n-r)!

unsigned long long fact(int x) {
    if (x == 1) {
        return x;
    }

    return x * fact(x-1);
}

unsigned long long Combination(int n, int r) {
    unsigned long long fact_n = fact(n);
    unsigned long long fact_r = fact(r);
    unsigned long long fact_n_r = fact(n-r);

    return fact_n / (fact_r * fact_n_r);
}

unsigned long long Combination2(int n, int r) {
    return fact(n) / (fact(r) * fact(n-r));
}

int main() {
    cout << "Enter the number of objects(n) & samples(r) : ";
    int n, r;
    cin >> n >> r;
    cout << "The combination is : " << Combination(n, r) << endl;
    return 0;
}