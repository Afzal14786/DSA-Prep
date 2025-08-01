#include <iostream>
using namespace std;

class Node {
    int data;
    Node *nextPtr;
    friend class List;

    public:
        Node(int data) {
            this->data = data;
            nextPtr = nullptr;
        }
};

class List {
    Node *head;
    Node *tail;
    public:
        List() {
            head = nullptr;
            tail = nullptr;
        }

        void push_front(int value) {
            Node *newNode = new Node(value);
            if (head == nullptr){
                head = tail = newNode;
            } else {
                newNode->nextPtr = head;
                head = newNode;
            }
        }

        void push_back(int value) {
            Node *newNode = new Node(value);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->nextPtr = newNode;
                tail = newNode;
            }
        }

        void displayList() {
            Node *temp = head;
            while (temp != nullptr) {
                cout << temp->data;
                if (temp->nextPtr != nullptr) {
                    cout << " -> ";
                }
                temp = temp->nextPtr;
            }
            cout << endl;
        }
};

int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(5);
    ll.push_front(6);

    ll.displayList();
    return 0;
}