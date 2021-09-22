#include "SetOfStacks.h"

template <typename T>
SetOfStacks<T>::SetOfStacks(int cap) {
    capacity = cap;
}

template <typename T>
SetOfStacks<T>::~SetOfStacks() {
    for(Stack<T> * stack : array){
        delete stack;
    }
}

template <typename T>
void SetOfStacks<T>::push (T item) {
    if(array.empty() ||
        array.at(array.size() - 1)->getSize() == capacity) {
        Stack<T> *newStack = new Stack<T>;
        newStack->push(item);
        array.push_back(newStack);
    } else {
        array.at(array.size() - 1)->push(item);
    }
}

template <typename T>
T SetOfStacks<T>::pop () {
    if(array.at(0)->empty()) {
        throw("set empty");
    } else {
        return array.at(array.size() - 1)->pop();
    }
}

template <typename T>
void SetOfStacks<T>::print () {
    for(Stack<T> *st : array) {
        st->print();
        cout << endl;
    }
}

template <typename T>
int SetOfStacks<T>::getCapacity () {
    return capacity;
}

template <typename T>
T SetOfStacks<T>::popAt (int idx) {
    T toReturn =  array.at(idx)->pop();
    if(array.at(idx)->empty()){
        Stack<T> *aux = array.at(idx);
        array.erase(array.begin() + idx);
        delete aux;
    }
    return toReturn;
}
