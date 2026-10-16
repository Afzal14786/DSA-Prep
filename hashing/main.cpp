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

        return idx % totalSize;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totalSize;
        // now increase the size
        totalSize =  totalSize * 2;
        currSize = 0;

        table = new Node*[totalSize];
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
            newNode->next = table[idx];
            table[idx] = newNode;

            currSize++;
            double lambda = currSize/double(totalSize);

            if (lambda > 1) {
                rehash();
            }
        }

        bool exisit (string key) {
            int idx = hashFunction(key);
            Node *temp = table[idx];
            while (temp != nullptr) {
                if (temp->key == key) {
                    // yes the key exist
                    return true;
                }

                temp = temp->next;
            }

            return false;
        }

        // searching

        int search(string key) {
            int idx = hashFunction(key);
            Node *temp = table[idx];

            while (temp != nullptr) {
                if (temp->key == key) {
                    return temp->value;
                }

                temp = temp->next;
            }

            return -1;  // means not found
        }

        void remove (string key) {
            int idx = hashFunction(key);
            Node *temp = table[idx];
            Node* pre = temp;

            while (temp != nullptr) {
                if (temp->key == key) {
                    if (pre == temp) {
                        // delete the head node
                        table[idx] = temp->next;
                    }

                    pre->next = temp->next;
                    return;
                }

                pre = temp;
                temp = temp->next;
            }
        }
        
        void print () {
            for (int i = 0; i < totalSize; ++i) {
                cout << "idx" << i << "->";
                Node *temp = table[i];
                while (temp != nullptr) {
                    cout << "(" << temp->key << "," << temp->value << ")" << "->";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

};

int main() {
    
    HashTable h1(5);
    h1.insert("India", 200);
    h1.insert("China", 250);
    h1.insert("Bhutan", 100);
    h1.insert("Pakistan", 20);
    h1.insert("Sri Lanka", 400);
    h1.insert("US", 30);

    h1.print();
    cout << "\n\nAfter Deleting China & Pakistan From Earth : \n\n";
    h1.remove("China");
    h1.remove("Pakistan");

    h1.print();
    return 0;
}