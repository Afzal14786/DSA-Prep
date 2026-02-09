#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include <stack>
#include <string>

#include "./operant.h"

class Postfix {
public:
    std::string PostfixToInfix(std::string postfix);
    std::string PostfixToPrefix(std::string postfix);
};

/**
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */

std::string Postfix::PostfixToInfix(std::string postfix) {
    std::stack<std::string> st;
    for (char ch : postfix) {
        if (isOperant(ch)) st.push(std::string(1, ch));
        else {
            std::string t1 = st.top(); st.pop();
            std::string t2 = st.top(); st.pop();
            st.push('(' + t2 + ch + t1 + ')');
        }
    }

    return st.top();
}

/**
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */

std::string Postfix::PostfixToPrefix(std::string postfix) {
    std::stack<std::string> st;
    for (char ch : postfix) {
        if (isOperant(ch)) st.push(std::string(1, ch));
        else {
            std::string t1 = st.top(); st.pop();
            std::string t2 = st.top(); st.pop();
            st.push(ch + t2 + t1);
        }
    }

    return st.top();
}

#endif