#include "LinkedList.h"

template <typename T>
int List<T>::recursiveSearch(T value) {
    return helper(head, value);
}