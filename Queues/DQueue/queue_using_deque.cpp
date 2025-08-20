#include <iostream>
#include <deque>
using namespace std;

/**
 * @brief Impelmenting a Queue using <deque>
 * We can add push_back() so always the element will insert from back, similar to push() in queue
 * And for pop in queue we can use pop_front() in deque which is similar to pop() in queue
 */

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

    return 0;
}