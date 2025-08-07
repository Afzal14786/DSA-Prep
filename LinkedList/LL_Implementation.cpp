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

        ~Node() {
            if (nextPtr != nullptr) {
                delete nextPtr;
                nextPtr = nullptr;
            }
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

        ~List() {
            if(head != nullptr) {
                delete head;
                head = nullptr;
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

        int helper(Node *temp, int key) {
            // base case
            if (temp == nullptr) {
                cout << "Key Doesn't exist.\n";
                return -1;
            }

            if (temp->data == key) {
                // key found
                return 0;
            }

            // what if not found
            int idx = helper(temp->nextPtr, key);
            if (idx ==-1) {
                return -1;
            }

            return idx+1;
        }
        
        int size() {
            Node *temp = head;
            int size = 0;
            while (temp != nullptr) {
                temp = temp->nextPtr;
                size++;
            }
            return size;
        }

        bool isEmpty() {
            if (head == nullptr) {
                return true;    // yes the list is empty
            }
            return false;   // no the list is not empty
        }

        void push_front(int value);
        void push_back(int value);
        void push_middle(int data, int position);
        void pop_front();
        void pop_back();
        int search(int key);
        int recursive_search(int key);
        void delNth(int n);
        bool isSorted();
        bool isDuplicate();
        void reverse();
        void merge();
};

/**
 * @brief Pushes a new node to the front of the list.
 * @param data The integer value to be stored in the new node.
 */

void List::push_front(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr){
        head = tail = newNode;
    } else {
        newNode->nextPtr = head;
        head = newNode;
    }
}

/**
 * @brief Pushes a new node at the end of the list
 * @param data The integer value to be stored in the new node.
 */

void List::push_back(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->nextPtr = newNode;
        tail = newNode;
    }
}

/**
 * @brief Pushes a new node at given position
 * @param data The integer value to be stored in the new node.
 */

void List::push_middle(int data, int position) {
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

/**
 * @brief Pop a node from starting of the list
 * @return It return the node's data Integer value
 */

void List::pop_front() {
    // check base base
    if (head == nullptr) {
        // empty list
        cout << "List is empty\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    Node *temp = head;
    head = head->nextPtr;
    temp->nextPtr = nullptr;
    delete temp;
}

/**
 * @brief Pop a node from the end of the list
 * @return Return the poped data
 */

void List::pop_back() {
    if (head == nullptr) {
        // empty list
        cout << "List is empty\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    Node *temp = head;
    while (temp->nextPtr != tail) {
        temp = temp->nextPtr;
    }

    temp->nextPtr = nullptr;
    delete tail;
    tail = temp;
}


/**
 * @brief search an element in the list
 * @return position of the element
 * @if found
 * @else return -1 mean not found 
 */
int List::search(int key) {
    // base case
    if (head == nullptr) {
        cout << "List is empty\n";
        return -1;
    }


    Node *temp = head;
    int pos = 0;

    while (temp != nullptr) {
        if (temp->data == key) {
            return pos;
        }
        temp = temp->nextPtr;
        pos++;
    }
    return -1;
}

/**
 * @brief Recursive search using a helper function
 * @return position of the element
 * @if found
 * @else return -1 mean not found 
 */

int List::recursive_search(int key) {
    return helper(head, key);
}

/**
 * @brief Reverse the given list : Inplace reverse
 */

void List::reverse() {
    Node *curr = head;
    Node *pre = nullptr;

    while (curr != nullptr) {
        // first find the next pointer location
        Node *next = curr->nextPtr;
        // then the current node's pointer will point to privious node
        curr->nextPtr = pre;

        // now update the pointers 
        pre = curr;
        curr = next;
    }

    // at the end in the previous pointer we have last value which becomes the head of the reverse list
    head = pre;
}

/**
 * @brief Deleting a node which is given in a position from last
 * @param position The integer value for the position
 */

void List::delNth(int position) {
    // base case
    if (isEmpty()) {
        return;
    }

    int s = size() - position;
    // corner case
    if (s < 0) {
        cout << "Invalid Position\n";
        return;
    }

    Node *temp = head;

    // run a loop from head to size - n 
    for (int i = 1; i < s; i++) {
        temp = temp->nextPtr;
    }

    // now we are at correct position
    temp->nextPtr = temp->nextPtr->nextPtr;
}

int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_back(10);
    ll.push_back(30);
    // ll.displayList();   // 6->5->3->10->30
    
    
    ll.push_middle(100, 3);
    ll.displayList();   // 5->3->100->10

    // cout << ll.search(30) << endl;   // 5
    // cout << ll.recursive_search(30) << endl;    // 5

    // ll.reverse();
    ll.delNth(4);

    ll.displayList();   // 30->10->100->3->5->6
    return 0;
}