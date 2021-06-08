
#include <iostream>
#include "Stack.h"


template <class T>
Stack<T>::Stack() : p(NULL){}

template <class T>
void Stack<T>::svuotaStack(){p = NULL;}

template <class T>
bool Stack<T>::isEmpty(){return !p;}

template<class T> 
void Stack<T>::push(T x){
    Nodo<T>* nuovo = new Nodo<T>(x);

    if(p) nuovo->succ = p;
    p = nuovo;
}

template<class T> 
T Stack<T>::pop(){
    if(!isEmpty()){
        Nodo<T>* tmp;

        T val = p->key;
        tmp = p;
        p = p->succ;
        delete tmp;
        return val;
    }else return -1;
}

template <class T>
Stack<T>::~Stack(){
    Nodo<T>* tmp;

    while(p!=NULL){
        tmp = p;
        p = p->succ;
        delete tmp;
    }
}