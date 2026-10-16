/**
 * We'll Be Discussing About Quick Sort
 */

/**
 * @steps
 * 
 * 1. Pick A Pivot Element From The Given Arrays
 *      a. Can Select From Anywhere in the given arrays,
 *          i) Can pick form front
 *          ii) can pick from end
 *          iii) can pick from middle
 *          iv) Or any random element
 * 
 * 2. Now set this pivot element to it's correct position
 * 3. Once we picked up the pivot element compare it with the element and all the smallest element will be in the left and all the greatest element will be in the right of pivot element
 * 
 *  Example : arr[5,4,8,4,6,9,4,2,3,5], and pivot = 2
 * 
 *  Now the array look like after step 3: [2,4,8,4,6,9,4,5,3,5] 
 *  Now we can say that one element which was pivot, now it's in the correct position
 * 
 *  Now repeate this process from 1 to 3, in the left half of the array and right half of the array .
 *  Because the pivot element divides the array into two different halfs...
 */

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class QuickSort {
    std::vector<int> nums;
    std::mt19937 gen{std::random_device{}()};
    /**
     * This partition works differently when we are selecting a pivot from end
     */
    int partition(int low, int high) {
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (nums[j] < pivot) {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }

        std::swap(nums[i+1], nums[high]);
        return i+1;
    }

    /**
     * this funtion works fine when we select the pivot from start
     */

    int partition2(int low, int high) {
        int pivot = nums[low];
        int i = low;
        for (int j = low+1; j <= high; ++j) {
            if (nums[j] < pivot) {
                i++;
                std::swap(nums[j], nums[i]);
            }
        }

        std::swap(nums[low], nums[i]);
        return i;
    }

    /**
     * The partition function will change if we select pivot from middle
     */

    int partition3(int low, int high) {
        int mid = low + (high - low)/2;
        int pivot = nums[mid];
        int i = low - 1;

        std::swap(nums[mid], nums[high]);
        for (int j = low; j < high; ++j) {
            if (nums[j] < pivot) {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }

        std::swap(nums[i+1], nums[high]);
        return i+1;
    }

    /**
     * The function get slightly change if we choose random idx for pivot 
     */
    int partition4(int low, int high) {
        std::uniform_int_distribution<int> dist(low, high);
        int randomIndex = dist(gen);

        std::swap(nums[randomIndex], nums[high]);

        int pivot = nums[high]; // we are selecting the random element as pivot from nums
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (nums[j] < pivot) {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }

        std::swap(nums[i+1], nums[high]);
        return i+1;
    }

public:
    QuickSort(std::vector<int> &vec) : nums(vec) {}

    void sort(int low, int high) {
        if (low < high) {
            int partitionIdx = partition4(low, high);
            sort(low, partitionIdx-1);
            sort(partitionIdx+1, high);
        }
    }
    void displayArr() {
        for (int x : nums) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};


int main() {
    std::vector<int> nums = {4,6,2,5,7,9,1,8,3};
    QuickSort Q(nums);

    std::cout << "Array before sorting : " << std::endl;
    Q.displayArr();

    Q.sort(0, nums.size()-1);
    std::cout << "Array after sorting : ";
    Q.displayArr();
    return 0;
}