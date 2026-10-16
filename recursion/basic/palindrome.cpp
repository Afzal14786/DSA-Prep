#include <iostream>
#include <string>

using namespace std;

// first approach
string reverse_str(int i, string str) {
    int n = str.size();
    if (i >= n/2) return str;
    swap(str[i], str[n-i-1]);
    return reverse_str(i+1, str);
}


/**
 * we can reverse the same string using two pointer 
 */

string reverse_2(int left, int right, string str) {
    if (left >= right) return str;
    swap(str[left], str[right]);
    return reverse_2(left+1, right-1, str);
}

bool palindrome(string str) {
    string ans = reverse_2(0, str.size()-1, str);
    for (int i = 0; i < str.size(); ++i) {
        if (ans[i] != str[i]) return false;
    }
    return true;
}

/**
 * Another way of checking palindrome instead of first reverse and then checking the string
 */
// this is faster then previous and less power consuming ...
bool palindrome_2(int i, string str) {
    int n = str.size();
    if (i >= n/2) return true;
    if (str[i] != str[n-i-1]) return false;
    return palindrome_2(i+1, str);
}

int main() {
    string str = "11211";
    int ans = palindrome_2(0, str);
    if (ans) cout << "It's a palindrome" << endl;
    else cout << "It's not a palindrome." << endl;
    return 0;
}