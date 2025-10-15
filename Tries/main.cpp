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
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "three", "thee"};
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

    return 0;
}