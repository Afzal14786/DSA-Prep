#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,4,5};
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Size of the array is : " << arr.size() << endl;
    cout << "Capacity of the array is : " << arr.capacity() << endl;
    return 0;
}