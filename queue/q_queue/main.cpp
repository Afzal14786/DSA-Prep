#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_front(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_back(50);

    dq.pop_back();      // delete from front;
    dq.pop_front();     // delete from front;
    cout << "The Front Element : " << dq.front() << endl;
    cout << "The Back Elememnt : " << dq.back() << endl;
    return 0;
}