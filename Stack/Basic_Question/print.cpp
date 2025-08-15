#include "Stack_Implement.h"

template <typename T>
void Stack<T>::print() {
    while (!isEmpty()) {
        std::cout << top() << " ";
        pop();
    }

    cout << endl;
}