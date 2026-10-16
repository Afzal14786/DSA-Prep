#include "Stack_Implement.h"

template <typename T>
void Stack<T>::pop() {
    // check for the empty case
    if (isEmpty()) {
        // throw error
        throw std::runtime_error("cannot pop from an empty stack");
    }
    vec.pop_back();
}