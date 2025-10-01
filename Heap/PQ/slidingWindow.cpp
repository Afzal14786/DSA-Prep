#include <iostream>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

// time complexity = O(nlogn)
vector<int> slidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    priority_queue<pair<int, int>> pq;

    // let's make a priority que from i to k
    for (int i = 0; i < k; ++i) {
        pq.push(make_pair(nums[i], i));
    }

    // now push the first largest element into the ans array
    ans.push_back(pq.top().first);

    // now let's move the window ahead & also check and remove the element who are not the part of the window
    for (int i = k; i < nums.size(); ++i) {
        // this while will check the element outside the window
        while (!pq.empty() && pq.top().second <= (i-k)) {
            pq.pop();
        }

        pq.push(make_pair(nums[i], i));
        ans.push_back(pq.top().first);
    }

    return ans;
}


// solution 2
// time complexity = O(n)

vector<int> slidingWindow2(vector<int>& nums, int k) {
    // get the size
    int n = nums.size();
    vector<int> ans;
    // for storing the index, we have a deque
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        // now check and remove the elements who are outside the window
        if (!dq.empty() && dq.front() == (i-k)) {
            dq.pop_front();
        }

        // also remove the smaller elements from back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // now add answers to ans
        if (i >= k-1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}



int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = slidingWindow2(nums, 3);

    for (int val : ans) {
        cout << val << ", ";
    }

    cout << endl;

    return 0;
}