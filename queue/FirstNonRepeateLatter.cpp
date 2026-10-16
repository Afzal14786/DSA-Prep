#include <iostream>
#include <queue>
using namespace std;

void FirstNonRepeatingLetter(string str) {
    queue<char> charQueue;
    int freq[26] = {0};

    for (int i = 0; i < str.length(); ++i) {
        char ch = str[i];
        charQueue.push(ch);
        freq[ch - 'a']++;

        while (!charQueue.empty() && freq[charQueue.front()-'a'] > 1) {
            charQueue.pop();
        }

        if (charQueue.empty()) {
            cout << "-1" << " ";
        } else {
            cout << charQueue.front() << " ";
        }
    }

    cout << endl;
}

int main() {

    string str = "aabccxb";
    FirstNonRepeatingLetter(str);
    return 0;
}