#ifndef UTILS_UTILS_H
#define UTILS_UTILS_H

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T item;
    Node *next;
    T min;

    Node(T item) {
        this->item = item;
        this->next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    Node<T> *last;
    int size;

public:
   Stack();
    ~Stack();
    bool empty();
    T pop();
    T peek();
    int getSize();
    void push(T item);
    void print();
    T min();
};

template <typename T>
class Queue {
private:
    Node<T> *first;
    Node<T> *last;
public:
    Queue();
    ~Queue();
    void add(T item);
    void remove();
    T peek();
    bool isEmpty();
    void print();
};

#endif
