#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

    public:

        void enQueue(int data) {
            // step 1 = > Transfer all the s1 value to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            // step 2 => push the data into s1 stack
            s1.push(data);

            // step 3 => Now transfer all the data from stack 2 to stack 1
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }

        int deQueue() {
            if (s1.empty()) {
                cout << "The Queue Is Empty.\n";
                return -1;
            }
            int value = s1.top();
            s1.pop();
            return value;
        }

        int front() {
            if (s1.empty()) {
                cout << "The Queue Is Empty.\n";
                return -1;
            }

            return s1.top();
        }

        bool empty() {
            return s1.empty();
        }
};

/**
 * If we try to apply this method then when we print the stack it will remove all the elements and if we try to perform other 
 * auxilary functions like deQueue() and front(), then it will give us error | 
 * 
 * So before printing the stack we can perform the auxilary operations like deQueue(), and front() |
 */

int main() {

    // own class implementation using 2 stacks
    Queue q1;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    q1.enQueue(50);

    cout << "Deleted Value From Queue : " << q1.deQueue() << endl;


    cout << "The Front Element Of The Queue : " << q1.front() << endl;

    cout << "Queue After Performing deQueue And Front.\n";

    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.deQueue();
    }
    cout << endl;
    return 0;
}
