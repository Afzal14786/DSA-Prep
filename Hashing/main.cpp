#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }

        ~Node() {
            if (next != nullptr) {
                delete next;
            }
        }
};

/**
 * Important Functions On Hash
 *      1. insert(key, value)   O(1)
 *      2. remove(key)      O(1)
 *      3. search(key) -> retrun the value      O(1)
 */

class HashTable {
    int totalSize;
    int currSize;
    Node** table;
    int hashFunction(string key) {
        int idx = 0;
        for (int i = 0; i < key.size(); ++i) {
            idx = idx + (key[i] * key[i]) % totalSize;
        }

        return idx;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totalSize;
        // now increase the size
        totalSize *= 2;

        for (int i = 0; i < totalSize; ++i) {
            table[i] = nullptr;
        }

        // now copy all the key value to new table
        for (int i = 0; i < oldSize; ++i) {
            Node* temp = oldTable[i];

            while (temp != nullptr) {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            if (oldTable[i] != nullptr) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }
    public:
        HashTable(int size) {
            totalSize = size;
            currSize = 0;

            table = new Node*[totalSize];
            for (int i = 0; i < totalSize; ++i) {
                table[i] = nullptr;
            }
        }

        void insert(string key, int value) {    // time complexity = O(1)
            int idx = hashFunction(key);
            // create the new node
            Node *newNode = new Node(key, value);
            Node *head = table[idx];
            newNode->next = head;
            head = newNode;

            currSize++;
            double lambda = currSize/double(totalSize);

            if (lambda > 1) {
                rehash();
            }
        }

        // rehashing
        

};

int main() {
    cout << "Basic Structur Of Hash Table";
    HashTable hash(5);
    return 0;
}