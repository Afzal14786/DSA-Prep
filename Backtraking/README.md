## Backtracking  

### Backtracking is a strategies for finding a solution to a problem.  
**Backtracking is used to solve those type of problems or specific problems which have more than one possible solutions and we want all the solutions, then we'll use backtracking.**   

**Example Problems :**  
1. SUDOKU
2. N-Queens
3. Rat In A Maze
4. Permutation
5. Grid Ways
6. FindSubsets
7. KNights  
and many more...   

**In above all the example, they have more then one solutions. And also we can apply _bounding conditions_ to get some specific solution or desired solutions**  

**Basically _backtracking_ means we'll try to find all the possible solutions and if we stuck while getting any solution then we get back to previous step and try a different approach to solve the problem.**  

### 1. N-Queen  

_In N-Queen problem we have **N * N** matrix and we have **N** queens, so we have to set the queens in such a way that no-one queen can in war directly with each other._  

**Queen Move :**  

_Queen can move **column-wise (Same Column)**, **row-wise (Same Row)**, **diagonal** or **cross-diagoonal.**_  

!["N-Queen Board"](https://media.geeksforgeeks.org/wp-content/uploads/20230814111654/Solution-Of-4-Queen-Problem-300.png)

**In this image, there is 4 Queens and the dimention of the chess-board [Matrix] is also 4 x 4.**  

**_the queens are placed in such a way that no any other queens can be direct in war with another queen_**  

**Here is the another image, how actually the Queens are placed and how it make a stack trace.**  

![](https://media.geeksforgeeks.org/wp-content/uploads/20230814111826/Backtracking.png)  

**For more information about _Backtracking_, you can also refer some of links which is mention below.**  

1. [Google Developers N-Queens](https://developers.google.com/optimization/cp/queens)

2. [Geeks For Geeks N-Queen](https://www.geeksforgeeks.org/dsa/n-queen-problem-backtracking-3/).

3. [Wikipedia - N-Queen Puzzel](https://en.wikipedia.org/wiki/Eight_queens_puzzle)  


**Leet Code Problem**  
1. [N-Queen Problem](https://leetcode.com/problems/n-queens/description/)  

**Let's Design The Algorithm For N-Queen Problem Using Backtracking.**  

**Step 1**  
_We should have a **isValid(int, int)** function that takes two input and it checks **queen's positions, means** they are under attack or not_   

**Step 2**  

_We should have a function **NQueen(int)** & it has only onw argument where it takes number of queens as input & perform the task for arranging the queens in each row_  

**Hint : Number Of Rows == No Of Queens**  

```cpp
bool isvalid(int k, int l) {
    for (int i = 1; i< k; ++i) {
        if (ans[i] == l || Math.abs(ans[k]-l) == Math.abs(i-k)) {
            return false;
        }
    }

    return true;
}
```

```cpp

Algorithm NQueen(int n) {
    for (int i = 1; i<= n; ++i) {
        if (isValid(n, i)) {
            ans[n] = i;
            if (n == size) {
                printAns(ans);  // if queen reaches end
                return; // do nothing
            }
            NQueen(n+1);
        }
    }
}
```
### There are three variations of _N-Queen_ question.  
1. **Find answer exist or not return _true / false_**
2. **Print all possible solutions**
3. **Count of all possible solutions**  

### Solution For NQueen Question In Cpp

**_time complexity : O(n!)_**

**This solution is for storing the safe positions were the queens are placed in answer array.**  
**Similarly we can also solve this question in two other ways, like just return `true or false` if problem exist or not or another is we can print all the possible solution.**  
```cpp
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// let board size = 4
const int N = 4;

// now for storing queen's positons
vector<int> answer(N);

void printAns(vector<int> &answer) {
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

/**
 * Now for solving the question we should have two function
 *      1. for recursive calling the NQueen() funtion for next call
 *      2. another for checking the valid position for keeping the queens
 */

// isSafe(int row, int col), this function check if the queen is placing in the safe place or not

bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        // using this we can check the queen moves
        if (answer[i] == col || abs(i-row) == abs(answer[i]-col)) {
            return false;   // if the queen is not safe
        }
    }
    return true;    // if the queen safe
}

// NQueen(k), function call the function recursively for placing next queen

void NQueen(int k) {
    // base case
    if (N == k) {
        printAns(answer);
        return;
    }

    // then
    for (int i = 0; i < N; ++i) {
        if(isSafe(k, i)) {
            answer[k] = i;
            NQueen(k+1);
        }
    }
}

int main() {
    NQueen(0);
    return 0;
}
```

## 2. Permutation  

**Arrangment of laters in specific orders.**   

Example :  
Suppose you have 3 letters: A, B, and C.  
All possible permutations of these 3 letters (arrangements without repetition) are:  
 * ABC
 * ACB
 * BAC
 * BCA
 * CAB
 * CBA  

So, there are 6 **permutations** of the 3 items. This is calculated by.  

**Number of permutations = 3! = _3 x 2 x 1_ = 6**  

**General Formula :**  
For n different items, the number of permutations (arrangements of all items) is : **_P(n) = n!_**  

If we are choosing and arranging **r** items out of **n**, then it is :  $P(n, r) = \frac{n!}{(n - r)!}$  

**Here is the C++ Code For Permutation:**  
```cpp
void Permutation(string str, string ans) {
    int n = str.size();
    if (n == 0) {
        cout << ans << endl;
        return;
    } else {
        for (int i = 0; i < n; ++i) {
            char ch = str[i];
            string nextStr = str.substr(0,i) + str.substr(i+1, n-i-1);
            Permutation(nextStr, ans + ch);
        }
    }
}

int main() {
    string str = "abc";
    string ans = "";

    Permutation(str, ans);
    return 0;
}
```

