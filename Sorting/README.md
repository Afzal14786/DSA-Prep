# Sorting Techniques  

### There are many types of sorting techniques. Here is some of the famous`Sorting Algorithms`  

### From `Bubble Sort` till `Shell Sort` all are comparision based algorithm.
### From `Count Sort` till `Radix Sort` are index based algorithm .  

 1. Bubble Sort
 2. Insertion Sort
 3. Selection Sort
 4. Heap Sort
 5. Merge Sort
 6. Quick Sort
 7. Tree Sort
 8. Shell Sort
 9. Count Sort
 10. Bucket Or Bin Sort
 11. Radix Sort  

###  Some of these algorithms are `Comparision Based Algorithm` or some of them are `Index Based Algorithm`  


### There is some critera for analysis the sorting algorithms  
a. Number of comparision.  
b. Number of swaps.  
c. Adaptive.  
d. Stable.  
e. Extra Memory.

### When an algorithm is Stable ?  
When an algorithm preserve the `order` of an element or elements while sorting, such `algorithm` known as `Stable Algorithm`.  

### When an algorithm is adaptive ?  
When the given `array` or `list of objects` are **already sorted**, then the comparision must be stop after one iteration . So it takes only `O(n) time complexity`. Such algorithm known as `Adaptive Algorithm.`

### 1. Bubble Sort  
`Bubble Sort` is one of the simplest `sorting algorithm` which simple sort the element step by step by comparing the elements with it's adjecent.

In every iteration or pass the heavier element will sort .

```cpp
// TIme Complexity : O(n^2)
void BubbleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int flag = 0;
        for (int j = 0; j < nums.size()-i-1; ++j) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                flag = 1;   // means the 
            }
        }
        if (flag == 0) {
            break;      // means given array is already sorted .
        }
    }
}
```


### Merge Sort  
Merge sort algorithm is one of the most famous algorithm that is used for sorting . It uses divide and conquer rule . First it divides the array into 2 half using calculating the mid. Merge Sort Divide the array by half continuesly unitl it find a single element because by default single element is sorted, then it apply merging the sorted element with another sorted element into a single array .  

`Merge Sort Algorithm`  
```cpp
// this function is used to combine the sorted element into a temp array 
void Merge(int arr[], int start, int mid, int end) {
    // time complexity : O(n)
    // space complexity : O(n)
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // copy rest element of left half
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    
    // copy rest element of right half
    while (j <= end) {
        temp.push_back(arr[j++]);
    }

    // now copy all the sorted element from temp array to orignal array
    for (int i = start, k = 0; i <= end; ++i) {
        arr[i] = temp[k++];
    }
}

// function for performing merge sort using recursion

void MergeSort(int nums[], int start, int end) {
    // time complexity : O(nlogn)

    if (start >= end) {
        return;
    }

    int mid = start + (end - start) /2;

    MergeSort(nums, start, mid);    // left array
    MergeSort(nums, mid+1, end);    // right array

    // call the merge sort for merging the elements.
    Merge(nums, start, mid, end);
}
```

