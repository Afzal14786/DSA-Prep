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
    