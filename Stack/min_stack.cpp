/**
 * Desing a stack that allow following operations
 * 1. push
 * 2. pop
 * 3. top
 * 4. getMin
 * 
 * All the operation must be in constant time
 */

/**
 * Approach 1 : Using pair<> in stack
 * Time Complexity : O(1)
 * Space Complexity : O(2N)
 */

#include <iostream>
#include <climits>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st;
    void push(int val);
    void pop();
    int top();
    int getMin();
};

void MinStack::push(int val) {
    if (st.empty()) {
        st.push({val, val});
    } else {
        st.push({val, min(val, st.top().second)});
    }
}

void MinStack::pop() {
    st.pop();
}

int MinStack::top() {
    return st.top().first;
}

int MinStack::getMin() {
    return st.top().second;
}

/**
 * Approach 2 : With O(N) spacce complexity & O(1) Time Complexity
 */

class MinStack2 {
public:
    stack<int> st;
    int min = INT_MAX;
    void push(int val);
    void pop();
    int top();
    int getMin();
};

void MinStack2::push(int val) {
    if (st.empty()) {
        min = val;
        st.push(val);
    } else {
        if (val > min) st.push(val);
        else {
            st.push(2*val - min);
            min = val;
        }
    }
}

void MinStack2::pop() {
    if (st.empty()) return;
    int x = st.top(); st.pop();
    (x < min) ? min = 2*min - x : x;
}

int MinStack2::top() {
    if (st.empty()) return -1;
    int x = st.top();
    return (x < min) ? min : x;
}

int MinStack2::getMin() {
    if (min == INT_MAX) return -1;
    return min;
}


class MinStack3 {
public:
    stack<long long> st;
    long long minVal; 

    MinStack3() {
        minVal = LLONG_MAX;
    }

    void push(int val) {
        long long v = val;
        if (st.empty()) {
            minVal = v;
            st.push(v);
        } else {
            if (v >= minVal) {
                st.push(v);
            } else {
                // Encoding formula: 2 * val - min
                st.push(2 * v - minVal);
                minVal = v;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        // If x is less than minVal, it's a flag that the min is changing
        if (x < minVal) {
            minVal = 2 * minVal - x;
        }
    }

    int top() {
        if (st.empty()) return -1;
        
        long long x = st.top();
        // If x < minVal, the actual value is minVal itself
        return (x < minVal) ? (int)minVal : (int)x;
    }

    int getMin() {
        return (int)minVal;
    }
};
