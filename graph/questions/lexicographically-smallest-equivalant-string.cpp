// Question Link : https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    char dfs_min_char(unordered_map<char, vector<char>> &adjList, char curr_ch, vector<bool> &visited) {
        visited[curr_ch - 'a'] = true;
        char min_ch = curr_ch;

        for (char child : adjList[curr_ch]) {
            if (!visited[child - 'a']) {
                min_ch = min(min_ch, dfs_min_char(adjList, child, visited));
            }
        }

        return min_ch;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int m = s1.size();
        unordered_map<char, vector<char>> adjList;
        
        // forming the graph
        for (int i = 0; i < m; ++i) {
            char u = s1[i], v = s2[i];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        string result = "";
        int n = baseStr.size();
        for (int i = 0; i < n; ++i) {
            char curr_ch = baseStr[i];
            vector<bool> visited(n, false);

            char min_char = dfs_min_char(adjList, curr_ch, visited);
            result.push_back(min_char);
        }

        return result;
    }
};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char ch[26];
        for (int i = 0; i < 26; i++)
            ch[i] = 'a' + i;

        for (int i=0; i<s1.size(); i++) {
            char toReplace = max(ch[s1[i]-'a'], ch[s2[i]-'a']);
            char replaceWith = min(ch[s1[i]-'a'], ch[s2[i]-'a']);
            for (int i = 0; i < 26; i++)
                if (ch[i] == toReplace)
                    ch[i] = replaceWith;
        }
        
        for (int i = 0; i < baseStr.size(); i++)
            baseStr[i] = ch[baseStr[i]-'a'];

        return baseStr;
    }
};
