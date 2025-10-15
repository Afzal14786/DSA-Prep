#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


// leetcode question link : https://leetcode.com/problems/word-break/
class Node {
    public:
        unordered_map<char, Node*> children;
        bool eof;   // end of the word
};

class Tries {
    Node *root;
    public:
    Tries() {
        root = new Node();
    }

    // now insert the value
    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); ++i) {
            if (temp->children.count(key[i]) == 0) {
                // means the key is not present, let insert the value
                temp->children[key[i]] = new Node();    // inserted the value
            }
            // now update the pointer
            temp = temp->children[key[i]];
        }

        temp->eof = true;   // end of he word is true
    }

    bool search (const string& key) {
        Node *temp = root;
        for (char ch: key) {
            if (temp->children.find(ch) == temp->children.end()) {
                return false;
            }
            temp = temp->children[ch];
        }

        return temp->eof;
    }
};

bool helper(const string& s, int index, Tries& trie, unordered_map<int, bool>& memo) {
    // step: 2
    if (memo.find(index) != memo.end()) {
        return memo[index];
    }

    if (index == s.size()) {
        return true;
    }

    for (int i = index + 1;  i <= s.size(); ++i) {
        string prefix = s.substr(index, i - index);
        if (trie.search(prefix) && helper(s, i, trie, memo)) {
            memo[index] = true;
            return true;
        }
    }

    memo[index] = false;
    return false;

}

bool wordBreak(string key, vector<string> &wordDict) {
    // step 1 : Build the trie
    Tries trie;
    for (const string& word : wordDict) {
        trie.insert(word);
    }

    unordered_map<int, bool> memo;
    return helper(key, 0, trie, memo);
}

int main() {
    vector<string> dictionary = {"cats","dog","sand","and","cat"};
    string key = "catsandog";
    cout << wordBreak(key, dictionary) << endl;
    return 0;
}