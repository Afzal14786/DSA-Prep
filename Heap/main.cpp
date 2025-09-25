#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> arr; 

    void insert_helper(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            nums.push_back(0);
        }

        nums.push_back(val); // insert at end
        int i = nums.size() - 1;
        int temp = nums[i];

        while (i > 1 && temp > nums[i / 2]) {
            nums[i] = nums[i / 2];
            i /= 2;
        }

        nums[i] = temp;
    }

public:
    void insert(int val) {
        insert_helper(arr, val);
    }

    void display() {
        for (int i = 1; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h1;
    h1.insert(15);
    h1.insert(30);
    h1.insert(20);
    h1.insert(6);
    h1.insert(10);
    h1.insert(12);
    h1.insert(5);
    h1.display();

    h1.insert(40);
    cout << "Inserting 40, the heap is : ";
    h1.display();

    h1.insert(35);
    cout << "Inserting 35, the heap is : ";
    h1.display();

    return 0;
}
