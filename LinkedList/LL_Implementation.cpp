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

    void push_middle(int data, int position) {
    // check if it null or not
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            // create a temp node & assign to it head and move till position-1
            Node *temp = head;
            for (int i = 0; i < position-1; ++i) {
                if (temp == nullptr) {
                    // invalid position
                    cout << "Invalid Position\n";
                    return;     // -> Go Back
                }
                temp = temp->nextPtr;
            }
            newNode->nextPtr = temp->nextPtr;
            temp->nextPtr = newNode;
        }
    }
};

int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_back(10);
    ll.push_back(30);
    ll.displayList();   // 6->5->3->10->30
    
    
    ll.push_middle(100, 3);
    
    ll.displayList();   // 6->5->3->100->10->30
    return 0;
}