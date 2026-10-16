#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

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

    bool search(string key) {
        Node *temp = root;
        for (int i = 0; i < key.size(); ++i) {
            if (temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }

        return temp->eof;
    }

    bool startsWith(string prefix) {
        Node *temp = root;
        for (char ch : prefix) {
            if (temp->children.find(ch) == temp->children.end()) {
                return false;
            }
            temp = temp->children[ch];
        }

        return true;
    }
};

int main() {
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    Tries trie;

    // insertion done
    for (int i = 0; i < words.size(); ++i) {
        trie.insert(words[i]);        // at every i one word pass
    }

    string key;
    cout << "Enter the word you want to search : ";
    cin >> key;
    if (trie.search(key)) {
        cout << "Oh yes the word exists\n";
    } else {
        cout << "Oh no, the word not exist.\n";
    }

    cout << trie.startsWith("do") << endl;
    return 0;
}