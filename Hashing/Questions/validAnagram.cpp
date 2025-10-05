#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool validAnagram(string str1, string str2) {
    unordered_map<char, int> m;
    for (int i = 0; i < str1.size(); ++i) {
        if (m.count(str1[i])) {
            m[str1[i]]++;
        } else {
            m[str1[i]] = 1;
        }
    }

    // now run a loop over the second array
    for (int i = 0; i < str2.size(); ++i) {
        if (m.count(str2[i])) {
            m[str2[i]]--;
            if (m[str2[i]] == 0) {
                m.erase(str2[i]);
            }
        } else {
            return false;
        }
    }

    return m.size() == 0;
}


int main() {
    string str1 = "race";
    string str2 = "care";
    cout << validAnagram(str1, str2);
    cout << endl;
    return 0;
}