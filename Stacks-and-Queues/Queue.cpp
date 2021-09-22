#include "Utils.h"

template <typename T>
Queue<T>::Queue () {
    first = nullptr;
    last = nullptr;
}

template <typename T>
Queue<T>::~Queue () {
    while(first != nullptr) {
        Node<T> *aux = first;
        first = first->next;
        delete aux->item;
        delete aux;
    }
}

template <typename T>
void Queue<T>::add (T item) {
    Node<T> *newNode = new Node<T>(item);
    if(first == nullptr) {
        first = newNode;
        last = first;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

template <typename T>
void Queue<T>::remove () {
    if(first == nullptr){
        throw ("empty queue");
    } else {
        Node<T> *aux = first;
        first = first->next;
        delete aux;
    }
}

template <typename T>
T Queue<T>::peek () {
    if(first == nullptr){
        throw ("empty queue");
    } else {
        return first->item;
    }
}

template <typename T>
bool Queue<T>::isEmpty () {
    return (first == nullptr);
}

template <typename T>
void Queue<T>::print () {
    Node<T> *aux = first;
    while(aux != nullptr){
        cout << aux->item << " ";
        aux = aux->next;
    }
}
