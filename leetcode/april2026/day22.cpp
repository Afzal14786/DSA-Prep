// Question Link : https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/?envType=daily-question&envId=2026-04-22

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> twoEditWords(std::vector<std::string>& queries, std::vector<std::string>& dictionary) {
        std::vector<std::string> ans;
        
        for (auto &que : queries) {
            for (auto &dic : dictionary) {
                int diff = 0;
                for (int i = 0; i < que.size(); ++i) {
                    if (que[i] != dic[i]) diff++;
                    if (diff > 2) break;
                }
                if (diff <= 2) {
                    ans.push_back(que);
                    break;
                }
            }
        }

        return ans;
    }
};



struct TrieNode {
    TrieNode* child[26] = {nullptr};
    bool isEnd = false;
};

class Solution {
    TrieNode* root = new TrieNode();

    void insert(std::string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            if (!curr->child[c - 'a']) curr->child[c - 'a'] = new TrieNode();
            curr = curr->child[c - 'a'];
        }
        curr->isEnd = true;
    }

    bool search(std::string& q, int idx, int edits, TrieNode* curr) {
        if (edits > 2) return false;
        if (idx == q.size()) return true; // Found a word within 2 edits

        for (int i = 0; i < 26; i++) {
            if (curr->child[i]) {
                // If character matches, edits stay same. If not, edits + 1.
                int nextEdits = edits + (i != (q[idx] - 'a'));
                if (search(q, idx + 1, nextEdits, curr->child[i])) return true;
            }
        }
        return false;
    }

public:
    std::vector<std::string> twoEditWords(std::vector<std::string>& queries, std::vector<std::string>& dictionary) {
        for (std::string& d : dictionary) insert(d);
        
        std::vector<std::string> ans;
        for (std::string& q : queries) {
            if (search(q, 0, 0, root)) ans.push_back(q);
        }
        return ans;
    }
};