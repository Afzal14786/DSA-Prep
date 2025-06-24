# Recursion  
**What is recursion?**  
`
when a function call itself again and again.
`  
***Example:***  
```cpp
1 int factorial(int num) {
2    if (num == 0) {
3         return 1;
4     }
5 
6     return factorial(num - 1) * num;
7 }
```
`
In the above example if we see, the _factoral_ function call itself in line no 6.
`

* **There are five types of recursion functions**  
    1. **Tail Recursion**  
        When the function call itself in the last line of the code or block of code .  
        **example:**  
        ```cpp
                        // num = 5
        1 void printNum(int num) {
        2    if (num == 0) {
        3       return;    
        4    } 
        5    cout << num << " ";  // 5,4,3,2,1
        6    printNum(num-1);
        7 }
        ```  
    
    2. **Head Recursion**  
    When the function call before the execuation of next step .
    **example:**  
    ```cpp
                        // num = 5
        1 void printNum(int num) {
        2    if (num == 0) {
        3       return;    
        4    } 
        5    printNum(num-1);
        6    cout << num << " ";  // 1,2,3,4,5
        7 }
    ```  

    3. **Indirect Recursion**  
    4. **Tree Recursion**  
    5. **Nested Recursion**  


<hr/>

## Questions & Solution Code  

### 1. Write a function to calculation nth fibonacci number .  
**Solution:**  
***Fibonacci number*** is a sequence of number where each number is the sum of two preceding ones. It starting with **0** & **1**.  

The sequence typically begins: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, and so on  

Finoacci number has a deep connection to the ***Golden Ration*** (ϕ ≈ 1.618). 

In terms of ***Computer Science*** the **fibonacci numbers** are used in algorithms, data structures (like Fibonacci heaps).  

```cpp
int fibonacci(int num) {
    if (num == 0 || num == 1) {
        return num
    }

    return fibonacci(n-2) + fibonacci(num-1);
}
```
**In above code, if we see the no of calls are `O(n^2)` but using memoization we'll reduce it with `O(n)` calls.**  

**Example Code:**  
```cpp
int memoizationFibonacci(int n) {
    int array[n+1];
    for (int i = 0; i < n+1; ++i) {
        array[i] = -1;
    }

    if (n <= 1) {
        array[n] = n;
        return n;
    } else {
        if (array[n-2] == -1) {
            array[n-2] = memoizationFibonacci(n-2);
        } else if (array[n-1] == -1) {
            array[n-1] = memoizationFibonacci(n-1);
        }
    }

    return array[n-2] + array[n-1];
}
```
### Time complexity for this code is exponential time complexity of O(2^n) .  


### 2. Write a function for Combination .  
###        Combination is used to selection of items from a large set where the order of selection does not matter.  

**Formula** => `C(n, k) = n! / k! * (n-k)!`  
***Where :***  
* `n` is the total no of items in the set.
* `k` is the number of items to choose.
* `!` denotes the factorial **(e.g., 5!=5×4×3×2×1)**.  

```cpp
// solution code in C++ using for loop
int combination (int n, int k) {
    // edge cases or invalid inputes
    if (k < 0 || k > 0) {
        return 0;
    }

    if (k == 0 || k == n) {
        // there is only one way to choose 0 items .
        // or to choose all n
        return 1;
    }

    if (k > n/2) {
        k = n-k;
    }

    long long result = 1;

    for (int i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }

    return result;
}
```  

```cpp
// solution code using recursion
int combination(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    if (k == 0 || k == n) {
        return 1;
    }

    if (k > n / 2 ) {
        k = n-k;
    }

    return combination(n-1, k-1) + combination(n-1, k);
}
```

### Time complexity for this code will be 2^n.  


### 3. Write a program to find first occurrence of an element.  
***Solution Code:***  
```cpp
int firstOccurrence(vector<int> &nums, int i, int target) {

    if (i == nums.size()) {
        return -1;  // i reach to end
    }

    if (i == nums[i]) {
        return i;
    }

    return firstOccurrence(nums, i+1, target);
}
```

### 4. Write a program to find last occurrence of an element.  
***Solution Code:***  
```cpp
int lastOccurrence(vector<int> &nums, int i, int target) {

    if (i == nums.size()) {
        return -1;  // i reach to end
    }

    int indexFound = lastOccurrence(nums, i+1, target);

    if (indexFound == -1 && nums[i] == target) {
        return i;
    }

    return indexFound;
}
```

### 5. Write a program to find power(x, n).  
***Solution Code :***  
```cpp
// Solution Code : 1
int power1(int x, int n) {

    if (n == 0) {
        return 1;
    }

    return power(x, n-1) * x;
}
```

```cpp
// solution code : 2
int  power(int x, int n) {

    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        return power(x*x, n/2);
    } else {
        return x * power(x*x, (n-1)/2);
    }
}
```
**Oprimize solution using bit manipulation**  

```cpp
double power(double x, int n) {
    
    if (x == 0) {
        return (n == 0) ? 1.0 : 0.0
    }

    long long N = n;

    if (N < 0) {
        x = 1/x;
        N = -N;
    }

    double ans = 1.0;

    while (N > 0) {
        if (N & 1) {
            ans *= x;
        }
        x *= x;
        N >>= 1;
    }

    return ans;
}
```  

### 6. Write a program for remove duplicates from a given string.  
***Solution Code:***  

```cpp
// here is the code for removing duplicates from string

void removeDuplicate(string str, string ans, int i, int map[26]) {
    // base case 
    if (i == str.size()) {
        cout << "Duplicate Removed : " << ans << endl;
        return;
    }

    int mapIdx = (int)(map[i] - 'a');

    if (map[mapIdx]) {
        removeDuplicate(str, ans, i+1, map);
    } else {
        map[mapIdx] = true;
        removeDuplicate(str, ans+str[i], i+1, map);
    }
}

// calling this function from main

int main() {
    string str = "apnnacollege";
    string ans = "";
    int map[26] = {false};

    // calling the function
    removeDuplicate(str, ans, 0, map);      // O/P : apnacoleg
}
```

### 7. Given a "2 x n" board and tiles of size "2 x 1", the task is to count the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.  

***Solution Code:***  

```cpp
     // Base Cases:
        // numberOfWays(n) = 1, if n = 0.
        // numberOfWays(n) = 0, if n < 0.

    int tilingProblem(int n) {

        if (n == 0 | n == 1) {
            return 1;
        }

        return tilingProblem(n-2) + tilingProblem(n-1);
    }

    // tilingProblem(n-1) => means align vertically.
    // tilingProblem(n-2) => means set the tiles horizantally.
```

### 8. Tylor Series Using Recursion And For Loop  
```cpp
// solution approach 1:
// In this solution , no of multiplication is n^2.
double tylorSeries1(int x, int n) {
    static double power = 1.0, factorial = 1.0;
    double ans;

    if (n == 0) {
        return 1;
    } else {
        ans = tylorSeries1(x, n-1);
        power *= x;
        factorial *= n;
        return ans + power/factorial;
    }
}
```

```cpp
// Solution Approach 2:
// In this solution approach no of multiplication is `n` time only.

// Solution using for loop

double tylorSeries2(int x, int n) {
    double ans = 1.0;
    if (n == 0) {
        return ans;
    }

    for (; n > 0; n--) {
        ans = 1 + x * ans / n;
    }

    return ans;
}

// Solution Approach 3 :
// Using Recursion : 
// taking common the first term & then multiply .

double tylorSeries3(int x, int n) {
    static double ans;
    if (n == 0) {
        return 1;
    }

    ans = 1 + x * ans / n;
    return tylorSeries3(x, n-1);
}
```