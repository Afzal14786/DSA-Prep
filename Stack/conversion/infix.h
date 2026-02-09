#ifndef INFIX_H
#define INFIX_H

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

#include "./operant.h"
#include "./operator.h"

class Infix {
public:
    std::string InfixToPostfix(std::string infix);
    std::string InfixToPrefix(std:: string infix);
};

/**
 * Time Complexity : O(2N)
 * Space Complexity : O(N)
 */
std::string Infix::InfixToPostfix(std::string infix) {
    std::stack<char> st;
    std::string ans = "";
    for (char ch : infix) {
        if (isOperant(ch)) ans += ch;
        else if (ch == '(') st.push(ch);
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && OperatorPriority(ch) <= OperatorPriority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

/**
 * Time Complexity : O(3N)
 * Space Complexity : O(N)
 */

std::string Infix::InfixToPrefix(std::string infix) {
    std::stack<char> st;
    std::string ans = "";
    /**
     * step 1 : Reverse the given infix and change the brakates
     */

    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.size(); ++i) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    /**
     * step 2 : Convert the reversed infix to postfix under some conditions
     */

    for (char ch : infix) {
        if (isOperant(ch)) ans += ch;
        else if (ch == '(') st.push(ch);
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            if (ch == '^') {
                while (!st.empty() && OperatorPriority(ch) <= OperatorPriority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            } else {
                while (!st.empty() && OperatorPriority(ch) < OperatorPriority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(ch);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    /**
     * step 3 : Again Reverse The Postfix String
     */
    reverse(ans.begin(), ans.end());
    return ans;
}

#endif