//Question Link : https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/?envType=daily-question&envId=2026-06-04

/**
 * Time Complexity : O(N * K)
 * Where :  
 *      * N is the total number of elements in the range, calculated as N = (num2 - num1 + 1).
 *      * K is the maximum number of digits in the numbers within that range (e.g., K approax log(num2)
 *      * Outer Loop: Runs exactly N times.
 *      * String Conversion (to_string): Takes O(K) time to convert an integer to a string.
 *      * Inner Loop: Iterates through the string characters from index 1 to K-2. This executes K-2 times, taking O(K) time.
 *      * Total operations per number: O(K) + O(K) = (K).
 * 
 * Space Complexity : O(K)
 * K is the number of digits of the largest number in the range num2.
 *      * Variables: The peak, vally, and digit integers use constant space O(1).
 *      * String Storage: The string str variable dynamically allocates memory to store the string representation of the current number i. At any point in time, it holds at most K characters.
 *      * Heap/Stack Allocation: Since the string memory is overwritten and freed in every iteration of the outer loop, the memory does not scale with the range size N.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int peak = 0, vally = 0;

        for (int i =  num1; i <= num2; ++i) {
            string str = to_string(i);

            for (int j = 1; j < str.size() - 1; ++j) {
                int digit = str[j] - '0';
                if (digit > str[j-1] - '0' && digit > str[j+1] - '0') peak++;
                if (digit < str[j-1] - '0' && digit < str[j+1] - '0') vally++;
            }
        }

        return peak + vally;
    }
};


int main() {
    int num1 = 4848, num2 = 4848;
    Solution s;

    cout << "Waaviness : " << s.totalWaviness(num1, num2) << endl;
    return 0;
}