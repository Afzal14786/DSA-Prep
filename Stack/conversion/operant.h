#ifndef OPERANT_H
#define OPERANT_H

bool isOperant(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) return true;
    return false;
}

#endif