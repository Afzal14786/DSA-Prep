#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void printAns(vector<int> &result) {
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}


void push_at_bottom(stack<int> &st, int value) {
    if (st.empty()) {
        st.push(value);
        return;
    }

    int hold_value = st.top();
    st.pop();
    push_at_bottom(st, value);
    st.push(hold_value);
}

string reverse_string(string str) {
    string ans;
    stack<char> s;

    for (int i = 0; i < str.length(); ++i) {
        s.push(str[i]);
    }

    while (!s.empty()) {
        char ch = s.top();
        ans += ch;
        s.pop();
    }

    return ans;
}

void reverse_stack(stack<int> &st) {
    if (st.empty()) {
        return;
    }

    int temp = st.top();
    st.pop();
    reverse_stack(st);
    push_at_bottom(st, temp);
}

void calculate_span(vector<int> &stock) {
    stack<int> st;  // holds the previous high values index
    vector<int> span(stock.size());    // hold the answer
    // we know that the first values is always high 
    st.push(0);
    span[0] = 1;

    for (int i = 1; i < stock.size(); ++i) {
        // now check with the current element and calculate it's previous consicutive high element 
        int current_price = stock[i];
        while (!st.empty() && current_price >= stock[st.top()]) {
            st.pop();
        }

        if (st.empty()) {
            span[i] = i + 1;
        } else {
            int previous_high_index = st.top();
            span[i] = i - previous_high_index;
        }
        st.push(i);
    }

    printAns(span);
}


vector<int> next_greater(vector<int> &arr) {
    stack<int> st;
    vector<int> ans(arr.size());

    ans[arr.size()-1] = -1;
    st.push(ans[arr.size()-1]);

    // run a loop in backward
    for (int i = arr.size()-1; i >= 0; --i) {
        int curr_value = arr[i];
        while (!st.empty() && curr_value >= st.top()) {
            st.pop();
        }
        
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }

        st.push(curr_value);
    }

    return ans;
}

bool isBalance2(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) {
                return false;
            }

            char top = st.top();
            if ((top == '(' && ch == ')') ||
                (top == '[' && ch == ']') ||
                (top == '{' && ch == '}') ) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}


bool isBalance(string str) {
    stack<char> st;

    for (int i = 0; i < str.length(); ++i) {
        char curr_chr = str[i];
        if (curr_chr == '(' || curr_chr == '[' || curr_chr == '{') {
            st.push(curr_chr);

        } else if (curr_chr == ')' || curr_chr == ']' || curr_chr == '}') {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

bool duplicate_brackets(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); ++i) {
        char chr = str[i];

        if (chr != ')') {
            st.push(chr);
        } else {
            if (st.top() == '(') {
                return true;
            } else {
                while (st.top() != '(') {
                    st.pop();
                }
                st.pop();
            }
        }
    }

    return false;
}

int maxAreaHistogram(vector<int> &heights) {
    int size = heights.size();
    vector<int> nsl(size);        // calculate the left side smallest number for each location
    vector<int> nsr(size);        // calculate the right side smallest number for each location

    stack<int> st;      // it help us to track the smallest number 

    // calculating the left smallest number for each height[i]
    nsl[0] = -1;    // because it does not have any smallest value in left side
    st.push(0);     // push the index of the value ans store -1 in the array

    for (int i = 1; i < size; ++i) {
        int current_elem = heights[i];
        while (!st.empty() && heights[st.top()] >= current_elem) {
            st.pop();
        }

        if (st.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = st.top();
        }

        st.push(i);
    }

    // empty the stack
    while (!st.empty()) {
        st.pop();
    }

    // now stack is empty, let's find the right smallest number 
    nsr[size-1] = size;
    st.push(size-1);

    // run a reverse loop and find the smallest number 
    for (int i = size-2; i >= 0; --i) {
        int current_elem = heights[i];
        while (!st.empty() && heights[st.top()] >= current_elem) {
            st.pop();
        }

        if(st.empty()) {
            nsr[i] = size-1;
        } else {
            nsr[i] = st.top();
        }

        st.push(i);
    }

    // now let's calculate the area
    int maxArea = 0;
    for (int i = 0; i < size; ++i) {
        int area = heights[i] * (nsr[i] - nsl[i] - 1);
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int maxAreaHistogram2(vector<int> &heights) {
    stack<int> st;
    int maxArea = 0;
    int size = heights.size();

    for (int i  = 0; i <= size; ++i) {
        int current_height = (i == size) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] >= current_height) {
            int h = heights[st.top()];
            st.pop();

            int left_boundry =  st.empty() ? -1 : st.top();

            int width = i - left_boundry - 1;
            
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }

    return maxArea;
}

int main() {
    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);

    // // push_at_bottom(st, 90);

    // reverse_stack(st);

    // while (!st.empty()) {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    // cout << endl;

    // stock price
    // vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    // calculate_span(stock);

    // vector<int> arr = {6,8,0,1,3};
    // vector<int> ans = next_greater(arr);
    // printAns(ans);

    // string str = "(a+b)";
    // string str2 = "((a+b) + z)";
    // string str3 = "(((a+b) + z))";

    // bool ans = isBalance2(str);

    // if (ans) {
    //     cout << "The String Is Balance.\n";
    // } else {
    //     cout << "The String Is Not Balanced.\n";
    // }

    // cout << duplicate_brackets(str) << endl;    // 0
    // cout << duplicate_brackets(str2) << endl;   // 0
    // cout << duplicate_brackets(str3) << endl;   // 1

    // histogram
    vector<int> heights = {2,1,5,6,2,3};
    int maxArea = maxAreaHistogram2(heights);

    cout << "Maximum Area In The Histogram is : " << maxArea << endl;

    return 0;
}