#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// leetcode question link : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/


class Rows {
    public:
        int count;
        int idx;

        Rows(int count, int idx) {
            this->count = count;
            this->idx = idx;
        }

        bool operator < (const Rows &obj) const {
            if (this->count == obj.count) {
                return this->idx > obj.idx;
            }

            return this->count > obj.count;
        }
};

vector<int> weekestSoldier(vector<vector<int>> &matrix, int k) {
    vector<Rows> rows;
    vector<int > indices;

    for (int i = 0; i < matrix.size(); ++i) {
        int count = 0;
        for (int j = 0; j < matrix[i].size() && matrix[i][j] == 1; ++j) {
            count++;
        }

        rows.push_back(Rows(count, i));
    }

    // now create the min heap
    priority_queue<Rows> pq(rows.begin(), rows.end());

    for (int i = 0; i < k; ++i) {
        int idx = pq.top().idx;
        indices.push_back(idx);
        pq.pop();
    }

    return indices;
}

int main() {

    vector<vector<int>> matrix = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };

    vector<int> ans = weekestSoldier(matrix, 4);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}