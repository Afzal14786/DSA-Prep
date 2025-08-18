#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int data) {
	   this->data = data;
	   next = nullptr;
	}
};


class Queue {
   Node *head;
   Node *tail;
public:
   	Queue() {
	   head = tail = nullptr;
	}

	void enQueue(int data) {
	 // create a new node
	  Node *newNode = new Node(data);
	  if (head == nullptr) {
	     head = tail = newNode;
	  } else {
	    tail->next = newNode;
	    tail = newNode;
	  }
	}

	int deQueue() {
	  // check if the head is null or not
	   if (head == nullptr) {
	      return -1;  // means the head is null
	   }

	   // create a new Node that will hold the head 
	    Node *temp = head;
	    int delValue = temp->data;
	    head = head->next;	// head will move to the next location
	    if (head == nullptr) {
	        tail = nullptr;	// means there is only one single node in the list
	    }

	    delete temp;

	    return delValue;
	}

	int front () {
	  if (head == nullptr) {
	     return -1;
	  }

	  return head->data;
	}

	void displayQueue () {
	     Node *temp = head;
	     while (temp != nullptr) {
	         cout << temp->data;
		 if (temp->next != nullptr) {
		     cout << " <- ";
		 }

		 temp = temp->next;
	     }
	     cout << endl;
	}
};



int main() {
    Queue q1;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);

    q1.displayQueue();

    cout << "The Front Value Of Queue Is : " << q1.front() << endl;
    cout << "Deleted Value From Queue Is : " << q1.deQueue() << endl;

    q1.displayQueue();
    return 0;
}
