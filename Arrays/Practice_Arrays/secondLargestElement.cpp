#include <iostream>
#include <vector>
using namespace std;

int secondLargestElement(vector<int> &arr) {
    int max, secMax;
    max = secMax = -1;

    if (arr.size() == 0) {
        // means array is empty just return -1;
        return -1;
    }

    for (int i = 0; i < arr.size(); ++i) {
        // check the condition
        if (arr[i] > max) {
            secMax = max;
            max = arr[i];
        } else if (arr[i] < max && arr[i] > secMax) {
            secMax = arr[i];
        }
    }

    return secMax;

}

int main() {
    vector<int> arr = {11,44,32,54,32,89};

    cout << "Second Largest Element Is : " << secondLargestElement(arr) << endl;
    return 0;
}