#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Car {
    public:
        int idx;
        int dist;
        Car(int idx, int dist) {
            this->idx = idx;
            this->dist = dist;
        }

        bool operator < (const Car &obj) const {
            return this->dist > obj.dist;
        }
};

void NearByCar(vector<pair<int, int>> pos, int k) {
    vector<Car> cars;
    // calculate the distance
    for (int i = 0; i < pos.size(); ++i) {
        int dist = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i, dist));
    }

    // now using priority queue we can actualy sort from begin() to end()
    priority_queue<Car> pq(cars.begin(), cars.end());

    cout << "Nearest Cars = ";
    for (int i = 0; i < k; ++i) {
        cout << pq.top().idx << " ";
        pq.pop();
    }
    cout << endl;
}

int main () {
    vector<pair<int, int>> positions;
    positions.push_back(make_pair(3,3));        // car 1
    positions.push_back(make_pair(5,-1));       // car 2
    positions.push_back(make_pair(-2,4));       // car 3

    NearByCar(positions, 1);
    return 0;
}