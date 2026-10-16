#include "Stack_Implement.h"

template <typename T>
T Stack<T>::top() {
    // check for the emoty case
    if (isEmpty()) {
        throw std::runtime_error("stack is empty");
    }

    int lastIdx = vec.size()-1;
    return vec[lastIdx];
}