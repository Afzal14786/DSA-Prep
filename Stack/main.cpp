#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "./Stack_Implement.h"

int main() {
    Stack<int> stack;
    Stack<string> names;

    stack.push(30);
    stack.push(20);
    stack.push(10);
    stack.push(50);
    
    names.push("College");
    names.push("Apna");
    names.push("With");
    names.push("Coding");
    names.push("Learn");
    
    names.print();
    stack.print();
    return 0;
}