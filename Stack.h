#pragma once
#include <iostream>
#include "Nodo.cpp"

template <class T>
class Stack{
    private:
        Nodo<T>* p;
    public: 
        Stack();
        void svuotaStack();//{p = NULL;}
        bool isEmpty();//{return !p;}

        void push(T x);
        T pop();
        ~Stack();
};
