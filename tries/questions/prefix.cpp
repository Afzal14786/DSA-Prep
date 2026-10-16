#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
    public:
        unordered_map<char, Node*> children;
        bool eof;   // end of the line
        int freq;

        Node() {
            eof = false;
        }
};

class Tries {
    Node *root;
    int countHelper(Node *root) {
        int count = 0;
        for (pair<char, Node*> child : root->children) {
            count += countHelper(child.second);
        }

        return count + 1;
    }

    void longestHelper(Node *root, string &ans, string temp) {
        for (pair<char, Node*> child : root->children) {
            // only when the end of the word is true
            if (child.second->eof) {
                temp += child.first;
                // check if the word is same or not also check who is greater
                if ((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }
                // recursive call
                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size() - 1);
            }
        }
    }

    public:
        Tries() {
            root = new Node();
            root->freq = -1;
        }

        // insert 
    void insert(string key);
    bool search(const string& key);
    string getprefix(string key);
    bool startsWith(string prefix);
    int count() {
        return countHelper(root);
    }

    int uniqueSubstrings(string word);      // we are given a word and we have to find the total number of unique substrings
    string longestWord() {
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }

    /**
     * @brief Find the largest word in the dict[], that is available in the dist[] as well as all of it's prefixes as well
     * @return String
     */
    string longestSubstring(vector<string> &dict);
    // leetcode question no : https://leetcode.com/problems/counting-words-with-a-given-prefix/
    int prefixCount(vector<string> &words, string prefix);
};

void Tries::insert(string key) {
    Node *temp = root;
    for (int i = 0; i < key.size(); ++i) {
        if (temp->children.count(key[i]) == 0) {
            temp->children[key[i]] = new Node();     // insert new char
            temp->children[key[i]]->freq = 1; // update the frequency for the character 
        } else {
            temp->children[key[i]]->freq++;
        }
        temp = temp->children[key[i]];
    }

    temp->eof = true;
}

bool Tries::search(const string &key) {
    Node *temp = root;
    for (char ch : key) {
        if (temp->children.find(ch) == temp->children.end()) {
            return false;
        }
        temp = temp->children[ch];
    }
    
    return temp->eof;
}

string Tries::getprefix(string key) {   // O(L)
    Node* temp = root;
    string prefix = "";
    for (char ch : key) {
        prefix += ch;
        // check the frequency
        if (temp->children[ch]->freq == 1) {
            break;
        }

        temp = temp->children[ch];
    }

    return prefix;
}

bool Tries::startsWith(string prefix) {
    Node *temp = root;
        for (char ch : prefix) {
            if (temp->children.find(ch) == temp->children.end()) {
                return false;
            }
            temp = temp->children[ch];
        }

        return true;
}

int Tries::uniqueSubstrings(string word) {
    Tries trie;
    for (int i = 0; i < word.size(); ++i) {
        string suffix = word.substr(i);
        trie.insert(suffix);
    }

    return trie.count();
}

// ----------------------------------------------------------

vector<string> prefix(vector<string> &dict) {
    // now create a tries
    Tries trie;
    for (const string &word : dict) {
        trie.insert(word);
    }

    // now get the prefix
    vector<string> prefix_ans;
    for (const string &word : dict) {
        string prefix = trie.getprefix(word);
        prefix_ans.push_back(prefix);
    }

    return prefix_ans;
}

void display_prefixes(vector<string> &answer) {
    cout << "prefixes are : {";
    for (const string &words : answer) {
        cout << words << ", ";
    }

    cout << "}" << endl;
}

string Tries::longestSubstring(vector<string> &dict) {
    // strp 1 : Build the tree
    Tries trie;
    for (int i = 0; i < dict.size(); ++i) {
        trie.insert(dict[i]);
    }

    // step 2 : call the search 
    return trie.longestWord();
}

int Tries::prefixCount(vector<string> &dict, string prefix) {
    int ans = 0;
    for (const string &word : dict) {
        if (word.rfind(prefix, 0) == 0) ans++;
    }

    return ans;
}

int main() {
    Tries trie;
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    vector<string> ans  = prefix(words);
    cout << trie.startsWith("duck") << endl;
    display_prefixes(ans);

    // count all unique sub string that can be formed from one given string
    cout << trie.uniqueSubstrings("ababa") << endl;     // 10
    cout << "The Longest Word With All Prefixes Exist In The Word[] : " << trie.longestSubstring(dict) << endl;
    cout << "Prefix Count : " << trie.prefixCount(dict, "a") << endl;
    return 0;
}