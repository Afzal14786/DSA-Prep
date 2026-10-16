#ifndef PREFIX_H
#define PREFIX_H

#include <iostream>
#include <stack>
#include <string>

#include "./operant.h"

class Prefix {
public:
    std::string PrefixToInfix(std::string prefix);
    std::string PrefixToPostfix(std::string prefix);
};

/**
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */

std::string Prefix::PrefixToInfix(std::string prefix) {
    std::stack<std::string> st;

    for (int i = prefix.size()-1; i >= 0; --i) {
        if (isOperant(prefix[i])) st.push(std::string(1, prefix[i]));
        else {
            std::string t1 = st.top(); st.pop();
            std::string t2 = st.top(); st.pop();
            st.push('(' + t1 + prefix[i] + t2 + ')');
        }
    }
    return st.top();
}

/**
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */

std::string Prefix::PrefixToPostfix(std::string prefix) {
    std::stack<std::string> st;

    for (int i = prefix.size() - 1; i >= 0; --i) {
        if (isOperant(prefix[i])) st.push(std::string(1, prefix[i]));
        else {
            std::string t1 = st.top(); st.pop();
            std::string t2 = st.top(); st.pop();
            st.push('(' + t1 + prefix[i] + t2 + ')');
        }
    }
    return st.top();
}

#endif