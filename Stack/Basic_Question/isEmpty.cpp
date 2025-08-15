#include "Stack_Implement.h"

template <typename T>
bool Stack<T>::isEmpty() {
    return vec.size() == 0;
}