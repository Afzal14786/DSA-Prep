#ifndef OPERATOR_H
#define OPERATOR_H

int OperatorPriority(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    return -1;
}

#endif