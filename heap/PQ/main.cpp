#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Student {
    public:
        string name;
        int marks;

        Student(string name, int marks) {
            this->name = name;
            this->marks = marks;
        }

        bool operator < (const Student &obj) const {
            return this->marks > obj.marks;
        }

};

struct ComparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;
    }
};

int main() {

    priority_queue<Student> pq;

    pq.push(Student("Md Afzal", 200));
    pq.push(Student("Haider Ali", 300));
    pq.push(Student("Firoz Ansari", 400));
    pq.push(Student("Gulam Rabbani", 500));

    while (!pq.empty()) {
        cout << pq.top().name << " " << pq.top().marks << endl;
        pq.pop();
    }

    // we can also store pairs in priority queue
    // here is how
    cout << "\n-------------------------------\n\n";
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pair_queue;
    pair_queue.push(make_pair("Md Afzal", 200));
    pair_queue.push(make_pair("Haider Ali", 300));
    pair_queue.push(make_pair("Firoz Ansari", 400));
    pair_queue.push(make_pair("Gulam Rabbani", 500));

    while (!pair_queue.empty()) {
        cout << pair_queue.top().first << " " <<  pair_queue.top().second << endl;
        pair_queue.pop();
    }

    cout << endl;
    return 0;
}