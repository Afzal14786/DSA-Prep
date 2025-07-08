## Backtracking  

### Backtracking is a strategies for finding a solution to a problem.  
**Backtracking is used to solve those type of problems or specific problems which have more than one possible solutions and we want all the solutions, then we'll use backtracking.**   

**Example Problems :**  
1. SUDOKU
2. N-Queens
3. Rat In A Maze
4. Permutation  
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
### There are three variations of _N-Queen_ question.  *
1. **Find answer exist or not return _true / false_**
2. **Print all possible solutions**
3. **Count of all possible solutions**  


