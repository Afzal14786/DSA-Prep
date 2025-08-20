#include <iostream>
#include <deque>
using namespace std;

/**
 * @brief Impelmenting a Queue using <deque>
 * We can add push_back() so always the element will insert from back, similar to push() in queue
 * And for pop in queue we can use pop_front() in deque which is similar to pop() in queue
 */

class Queue {
    deque<int> dq;

    public:
        void push(int data) {
            dq.push_back(data);  // alwase insert from one end
        }

        void pop() {
            dq.pop_front(); // always pop from front
        }

        bool isEmpty() {
            return dq.empty();
        }

        int front() {
            return dq.front();      // return the front element of the queue 
        }

        void display() {
            while (!dq.empty()) {
                cout << dq.front() << " ";
                pop();
            }
            cout << endl;
        }
};

int main() {
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);


    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;

    // Queue using own class and implementing deque internally
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);
    q1.push(7);
    q1.push(8);
    q1.push(9);
    q1.push(10);

    // cout << "Implementing Queue (Internally Using <deque> ) : ";
    // q1.display();

    q1.pop();
    cout << "Front Element Is : " << q1.front() << endl;
    cout << "Deleting Element Afetr Popping Element : ";
    q1.display();

    return 0;
}