#include <iostream>
#include <vector>

using namespace std;

int function(int n) {
    if (n <= 1) return n;
    return function(n-1) + function(n-2);
}

// memoization 
int memo_febo(int n, vector<int> &T) {
    if (n <= 1) return n;
    if (T[n] != -1) return T[n];
    return T[n] = memo_febo(n-1, T) + memo_febo(n-2, T);
}

int main() {
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    vector<int> T(n+1, -1);
    cout << "The " << n << " th fibonachi number is : " << memo_febo(n, T) << endl;
    return 0;
}