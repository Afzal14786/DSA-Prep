// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/?envType=daily-question&envId=2026-09-26

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        // we are processing the knowledge into map so it would be easy to found
        unordered_map<string, string> knowledge_map;
        for (auto &arr : knowledge) {
            string key = arr[0];
            string val = arr[1];

            knowledge_map[key] = val;
        }

        int n = s.size();  // size of the string 
        string ans = "";

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                // extract the key
                int j = i + 1;
                while (s[j] != ')') j++;

                string key = s.substr(i+1, j - i - 1);
                if (knowledge_map.find(key) != knowledge_map.end()) ans += knowledge_map[key];
                else ans += '?';
                i = j;
            } else ans.push_back(s[i]);
        }

        return ans;
    }
};


int main() {
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {
        {"name","bob"},
        {"age","two"}
    };

    Solution S;

    cout << "Output : " << S.evaluate(s, knowledge) << '\n';
    return 0;
}