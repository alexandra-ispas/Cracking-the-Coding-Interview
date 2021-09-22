#ifndef STACKS_AND_QUEUES_SETOFSTACKS_H
#define STACKS_AND_QUEUES_SETOFSTACKS_H

#include "Utils.h"
#include <vector>

template <typename T>
class SetOfStacks {
private:
    vector<Stack<T> *> array;
    int capacity;

public:
    SetOfStacks(int capacity);
    ~SetOfStacks();
    int getCapacity();
    void push(T item);
    T pop();
    T popAt(int idx);
    void print();
};

#endif //STACKS_AND_QUEUES_SETOFSTACKS_H
