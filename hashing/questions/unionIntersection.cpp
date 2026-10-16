#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> getUnion(vector<int>& n1, vector<int>& n2) {
    unordered_set<int> s;
    vector<int> ans;
    for (int i = 0; i < n1.size(); ++i) {
        s.insert(n1[i]);
    }

    for (int i = 0; i < n2.size(); ++i) {
        s.insert(n2[i]);
    }

    for (int val : s) {
        ans.push_back(val);
    }

    return ans;
}

vector<int> getInterSection(vector<int>& n1, vector<int>& n2) {
    vector<int> ans;
    unordered_set<int> s;
    for (int v : n1) {
        s.insert(v);
    }

    for (int v : n2) {
        if (s.find(v) != s.end()) {
            ans.push_back(v);
            s.erase(v);
        }
    }

    return ans;
}

int main() {
    vector<int> n1 = {1,2,2,1};
    vector<int> n2 = {2,2};

    vector<int> ans1 = getUnion(n1, n2);
    vector<int> ans2 = getInterSection(n1, n2);

    cout << "Union : ";
    for (int n : ans1) {
        cout << n << " ";
    }

    cout << endl;

    cout << "Intersection : ";
    for (int n : ans2) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}