#include "MyQueue.h"

template <typename T>
MyQueue<T>::MyQueue() {
    left = new Stack<T>();
    right = new Stack<T>();
}

template <typename T>
MyQueue<T>::~MyQueue() {
    delete left;
    delete right;
}

template <typename T>
void MyQueue<T>::push (T item) {
    right->push(item);
}

template <typename T>
T MyQueue<T>::pop () {
    if(left->empty()) {
        if (right->empty()) {
            throw("empty stack");
        } else {
            while(! right->empty()) {
                left->push(right->pop());
            }
        }
    }
    return left->pop();
}

template <typename T>
void MyQueue<T>::print () {
    cout << "left :";
    left->print();
    cout << endl << "right :";
    right->print();
}
