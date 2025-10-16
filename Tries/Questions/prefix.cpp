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
    public:
        Tries() {
            root = new Node();
            root->freq = -1;
        }

        // insert 
    void insert(string key);
    bool search(const string& key);
    string getprefix(string key);

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

int main() {
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    vector<string> ans  = prefix(words);
    display_prefixes(ans);
    return 0;
}