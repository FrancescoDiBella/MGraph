#pragma once

template<class T>
struct Nodo
{
    T key;
    Nodo<T>* succ;
    Nodo(T x) : key(x), succ(NULL){}
};
