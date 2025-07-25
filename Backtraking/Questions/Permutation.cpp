#include <iostream>
#include <vector>
#include <string>

using namespace std;


// time complexity = O(n!)
// space complexity : O(n)
void Permutation(string str, string ans) {
    int n = str.size();
    if (n == 0) {
        cout << ans << endl;
        return;
    } else {
        for (int i = 0; i < n; ++i) {
            char ch = str[i];
            string nextStr = str.substr(0,i) + str.substr(i+1, n-i-1);
            Permutation(nextStr, ans + ch);
        }
    }
}

/**
 * Another Way
 */

string str = "ABC";
string ans = "";
int N = str.size();
vector<bool> selected(N, false);

void Permutation2(int k) {
    if (k == N) {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (selected[i] == false) {
            ans += str[i];
            selected[i] = true;
            Permutation2(k+1);
            selected[i] = false;
            ans.pop_back();
        }
    }
}

int main() {
    string str = "abc";
    string ans = "";

    // Permutation(str, ans);
    Permutation2(0);
    return 0;
}