#include <iostream>
using namespace std;

int fun(int N, int sum) {
    if (N < 1) return sum;
    return fun(N-1, sum + N);
}

// other way of doing same

int fun2(int N) {
    if (N == 0) return 0;
    return N + fun2(N-1);
}

int main() {
    int N, sum;
    cout << "Please enter the value of N : ";
    cin >> N;

    cout << fun2(N) << endl;
    return 0;
}