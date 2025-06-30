# Time & Space Complexty

### This is one of the most importent topic when we are learning data structure or we are implementing any algorithm.  

## Time Complexity  

### `Time Complexity` is not the actual time taken by the machine to execute the code. 

**Time Complexty : Actually it is an amount of time taken up by a function as algorithm to execute it and complete the `operations` based on input(n)**.  

**Example**
```cpp
// `n` represent that, it is execute for n times
void printNum(int n) {
    for (int i = 0; i < n; ++i) {
        cout << i << " ";   // this line is the operation
    }
}
```

In above example code, we clearly see that, the operation will happen for given input `n` times. Means the `cout << i << " "`, will perform `n` times .  

So `The Time Complexity` is the relation between the input size of a function or an algorithm and the number of operations it performs to complete te function call, As input size grow or down.  

## Notations to represent time complexity.  

### 1. Big `'O'` Notation  
**Big `'O'` notation is used to represent the `wrost case time complexity` or `Upper Bound Time Complexity`, Means that any algorithms can not take more then Upper Bound Time Complexity**   

**And most of the time we are dealing with only Big `'O'` notation because if any function has best case time complexity then we not nead to optimize it.**  

**Mathematical Formula For Best Case Time Complexty**  

Big O notation is a mathematical notation that describes the limiting behavior of a function when the argument tends towards a particular value or infinity. In computer science, it's used to classify algorithms according to how their running time or space requirements grow as the input size grows.

$$f(n) \leq c \cdot g(n)$$

$$\lim_{n\to \infty} |\frac {f(n)}{g(n)}| < \infty $$

### Some time complexities  

a. `O(1)` : This is known as the best case time complexty.  
b. `O(logn)` : This is known as `logarathmic` time complexity.  
c. `O(n)` : Constant time complexity  
d. `O(nlogn)` : log linear time complexty  
e. `O(n^2)` : polynomial time complexity.  
f. `O(2^n)` : exponential time complexty
g `O(n!)`   :   Wrost Case Time Complexty  

![Time Complexity Graph](https://miro.medium.com/v2/resize:fit:1400/1*dWet_YU-5072Kcko7LzsuQ.jpeg "Time Complexty Graph")  

## Space Complexty  
**It is the amount of space taken by the an algorithm as a function of input `n`**.  

**Space Occupied** in two factors  
    1. Input Size.  
    2. Auxilary Space {Extra Memory}  

In `Space Complexity` we are calculating the extra amount of memory, how much an algorithm takes to complete the task.  

**Example**
```cpp
int printSmallest(int nums[]) {
    int ans = nums[0]; // `ans` take 1 unit space
    return ans;
}
```
In this example only ans is one extra variable that is used so it takes only `constant time` .  

Similar notations are used to represent the space complexty as we see in the `time complexity`.  

Most of the time we are dealing with time complexity .    

## Recurrence Relation  
`Recurrence Relation` is a mathematical function used to represent time taken by an algorithm or function . Using **recurrence relation** we can find how much amount of time actually taken by a recursion algorithm .  

### General formula for decreasing `recurrence relation`  
`T(n) = aT(n-b) + f(n)` where  
1. `a` is the no of times recurrence relation called in the function.  
2. `b` is the decreasing value means at which rate the function decrease.  
3. `f(n)` represent the work done by the function.  

**Example**  
```cpp
Algo fun(n) {
    if (n > 0) {
        cout << n << " ";   // work done (constant time)
        fun(n-1);   // recursive call for onw time so `a` = 1
    }
}

// for this algorithm, recurrence relation is : T(n) = T(n-1) + 1
// T(n) is the total time taken by the function .
```
**Time Complexity for the above algo code is :** = `O(n)` that is linear.  
And we can solve this recurrence relation using `Subsitude Method` Or `Master Theorem`  

**Another Function**  
```cpp
Algo fun(n) {
    
    if (n > 0) {
        for (i = 1; i <= n; ++i) {
            cout << i << " ";   // here work done for n times not 1 time 
        }

        fun(n-1);   // no of recursive call is 1
    }
}
// recurrence relation is : T(n) = T(n-1) + n
```
**Time Complexity for the above algo code is :** = `O(n^2)` that is polynomail.  

**Another Example**  
```cpp
Algo fun(n) {
    if (n > 0) {
        cout << n " ";  // work done : constant
        fun(n-1);
        fun(n-1);

        // no of recursive calls are 2
    }
    // recursion relation for this is : T(n) = 2T(n-1) + 1
}
**Time Complexity for the above algo code is :** = `O(2^n)` that is polynomial and it is a very bad time complexity.  
```

### Master Theorem & Short Formula For Calculation The Time Complexity  

Above all the recurrence relation if you see vary carefully, there is some unique point, let see using the relations...   

**Relation 1** : `T(n) = T(n-1) + 1` and it's time complexity is `O(n)`.  
**Relation 2** : `T(n) = T(n-1) + n` and it's time complexity is `O(n^2)`.  
**Relation 3** : `T(n) = 2T(n-1) + 1` and it's time complexity is `O(2^n)`.  

If we see the `n 1`, `a` value is `1` and `f(n)` value is also `1` and the relation is decreased by `(n-1)` : So you can say time complexity is `O(n * f(n))` means `O(n * 1)`.  

If we see the `relation 2`, the value of `a` is `1`, value of `f(n)` is `n`, therefore it's time complexity is `O(n * f(n))` = `O(n * n)` which is `O(n^2)` .

So Conclusion is if the value of `a`==`1` then we can find the time complexity for decreasing recursive function just multiply it with the `O(n * f(n))`.

**In Relation 3 if we see the value of a > 1, so for this we can consider another example**  

General Formaula is : `T(n)  = aT(n-b) + f(n)`  
If `a > 1` then for decreasing recursive function the formula become's :  

**$O(a^{n/b} \cdot f(n))$.** 

### Recurrence Relation For Dividing Function  

### General formula for `dividing recurrence relation : ` `T(n) = aT(n/b) + f(n)`

### Consider f(n) = $n^{k} \cdot log^{p}n$

**Example 1**
```cpp
Algo fun(n) {
    if (n > 1) {
        cout << n " ";  // constant work done 
        fun(n/2);   // calling the function but `/2`
    }
}

// recurrence relation for this is : T(n) = T(n/2) + 1;
```
**If we solve the above recurrence relation using subsitute method then time complexity is :** `O(logn)`.  

**Example 2**
```cpp
Algo fun(n) {
    if (n > 1) {
        for (i = 1; i <= n; ++i) {
            cout << i << " ";   // operation happen for `n` times
        }

        fun(n/2);   // no of recursive calls = 1
    }
    // recurrence relation = T(n) = T(n/2) + n
}
```
**If we solve the above recurrence relation using subsitute method then time complexity is :** `O(n)`.  

**Example 3**  
```cpp
Algo fun(n) {
    if (n > 1) {
        cout << i << " ";   // operation happen for `1` for constant time
        fun(n/2);
        fun(n/2);
    }

    // no of recursive calls = 2, therefore 
    // recurrence relation is : T(n) = 2T(n/2) + 1
}
```
**If we solve the above recurrence relation using subsitute method then time complexity is :** `O(n)`.  


**Example 4**  
```cpp
Algo fun(n) {
    if (n > 1) {
        for (i = 1; i <= n; ++i) {
            cout << i << " ";   // operation happen for `n` times
        }

        fun(n/2);   // no of recursive calls = 2
        fun(n/2);
    }
    // recurrence relation = T(n) = 2T(n/2) + n
}
```

**If we solve the above recurrence relation using subsitute method then time complexity is :** `O(nlogn)`.  

**Example 5**  
```cpp
Algo fun(n) {
    if (n > 1) {
        for (i = 1; i <= n; ++i) {
            for (j = 0; j <=n; ++j) {
                cout << i << " ";   // operation happen for `n^2` times
            }
        }

        fun(n/2);   // no of recursive calls = 2
        fun(n/2);
    }
    // recurrence relation = T(n) = 2T(n/2) + n^2
}
```
**If we solve the above recurrence relation using subsitute method then time complexity is :** `O(n^2)`.  

If we observe all the 5 examples we will find some hints for preparing `Master's Theorem For Dividing Functions`.  

As we know the `General Formula` is 
$$T(n) = a \cdot T(n/b) + f(n)$$

Where `f(n)` is also represent as 
    $$n{^k} \cdot log{^p}n$$ 

So As Per Master Theorem For Diving Function  

**Case 1:**  
`If` $log_ba > k$ then, time complextiy will be **O($n^{log_ba}$)**  
Here is some recurrence relation  
`1. T(n) = 2T(n/2) + 1`     Time Complexity = `O(n)`  


**Case 2**  
`If` $log_ba == k$ then, time complexity will be **O($f(n) \cdot logn$)**  
Here is some recurrence relation  
`1. T(n) = T(n/2) + 1`      Time Complexity = `O(logn)`  
`2. T(n) = 2T(n/2) + n`     Time Complexity = `O(nlogn)`  


**Case 3**  
`If` $log_ba < k$ then time complexity will be **O($f(n)$)**  
**Example**  
Here is some recurrence relation  
`1. T(n) = T(n/2) + n`      Time Complexity = `O(n)`  
`2. T(n) = 2T(n/2) + n^2`   Time Complexity = `O(n^2)`
