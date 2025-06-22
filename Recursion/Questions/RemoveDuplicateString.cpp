#include <iostream>
#include <string>
using namespace std;

void removeDuplicate(string str, string ans, int i, int map[26]) {
    if (i == str.size()) {
        cout << "Removed Duplicate : " << ans << endl;
        return;
    }

    int mapIdx = (int)(str[i] - 'a');

    if (map[mapIdx]) {
        removeDuplicate(str, ans, i+1, map);
    } else {
        map[mapIdx] = true;
        removeDuplicate(str, ans+str[i], i+1, map);
    }
}

int main() {
    string str = "apnnacollege";
    string ans = "";
    int map[26] = {false};

    removeDuplicate(str, ans, 0, map);
    return 0;
}