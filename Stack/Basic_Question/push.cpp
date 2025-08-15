#include "Stack_Implement.h"

template <typename T>
void Stack<T>::push(T data) {
    vec.push_back(data);
}