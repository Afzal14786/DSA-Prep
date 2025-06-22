#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int> &nums, int i, int target) {
    
    if (i == nums.size()) {
        return -1;
    }

    if (nums[i] == target){
        return i;
    }

    return firstOccurrence(nums, i+1, target);
}

// last occuurrence 

int LastOccurrence(vector<int> &nums, int i, int target) {
    if (i == nums.size()) {
        return -1;
    }

    int idxFound = LastOccurrence(nums, i+1, target);

    if (idxFound == -1 && nums[i] == target) {
        return i;
    }

    return idxFound;
}

int main() {
    vector<int> nums = {1,2,3,3,3,4,5};
    cout << "First Occurrence Found At Index : " << firstOccurrence(nums, 0, 3) << endl;
    cout << "First Occurrence Found At Index : " << firstOccurrence(nums, 0, 8) << endl;
    cout << "Last Occurrence Found At Index : " << LastOccurrence(nums, 0, 3) << endl;
    return 0;
}