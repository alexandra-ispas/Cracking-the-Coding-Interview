#include "Utils.h"

template <typename T>
Stack<T>::Stack () {
    last = nullptr;
    size = 0;
}

template <typename T>
Stack <T>::~Stack () {
    if (size > 0) {
        while (last != nullptr) {
            Node<T> *aux = last;
            last = last->next;
            delete aux;
        }
    }
}

template <typename T>
bool Stack <T>::empty () {
    return (last == nullptr);
}

template <typename T>
T Stack <T>::peek () {
    if(last == nullptr){
        throw ("empty stack");
    }
    return last->item;
}

template <typename T>
int Stack<T>::getSize () {
    return size;
}

template <typename T>
T Stack <T>::pop () {
    if (last != nullptr) {
        T toReturn = last->item;
        if (last->next == nullptr) {
            delete last;
            last = nullptr;
        } else {
            Node<T> *aux = last;
            last = last->next;
            delete aux;
        }
        size --;
        return toReturn;
    } else {
        throw("empty stack");
    }
}

template <typename T>
void Stack <T>::push (T value) {
    Node<T> *newNode = new Node<T> (value);
    if (last == nullptr) {
        newNode->min = value;
        last = newNode;
    } else {
        newNode->min = value < last->min ? value : last->min;
        newNode->next = last;
        last = newNode;
    }
    size ++;
}

template <typename T>
void Stack<T>::print () {
    Node<T> *aux = last;
    while(aux != nullptr){
        cout << aux->item << " ";
        aux = aux->next;
    }
}

template <typename T>
T Stack<T>::min () {
    if(last == nullptr){
        throw("empty stack");
    } else {
        return last->min;
    }
}

template <typename T>
void sortStack (Stack<T> *stack, Stack<T> *auxStack) {
    if(stack->empty()) {
        while(!auxStack->empty()){
            stack->push(auxStack->pop());
        }
    } else {
        T elem = stack->pop();
        if(auxStack->empty() || auxStack->peek() < elem) {
            auxStack->push(elem);
        } else {
            T iterator = auxStack->peek();
            while (iterator > elem) {
                stack->push(auxStack->pop());
                if(auxStack->empty()){
                    break;
                }
                iterator = auxStack->peek();
            }
            auxStack->push(elem);
        }
        sortStack(stack, auxStack);
    }
}
