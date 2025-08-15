#include <vector>

#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
    vector<T> vec;
    public:
        void push(T data);
        void pop();
        T top();
        bool isEmpty();
        void print();
};

#include "Basic_Question/push.cpp"
#include "Basic_Question/pop.cpp"
#include "Basic_Question/top.cpp"
#include "Basic_Question/isEmpty.cpp"
#include "Basic_Question/print.cpp"

#endif

