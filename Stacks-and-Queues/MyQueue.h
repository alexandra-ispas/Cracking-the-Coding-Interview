#ifndef STACKS_AND_QUEUES_MYQUEUE_H
#define STACKS_AND_QUEUES_MYQUEUE_H

#include "Utils.h"

template <typename T>
class MyQueue {
private:
    Stack<T> *left, *right;

public:
    MyQueue();
    ~MyQueue();
    void push(T item);
    T pop();
    void print();
};

#endif //STACKS_AND_QUEUES_MYQUEUE_H
