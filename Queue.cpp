#include "Queue.h"
#include <iostream>

template <class T>
Queue<T>::Queue(int val) : capacity(val), tail(-1), head(0), numeroElementi(0) {
    arr=new T[capacity];
}

template <class T>
bool Queue<T>::isFull(){return (numeroElementi==capacity);}

template <class T>
bool Queue<T>::isEmpty(){return (numeroElementi==0);}

template <class T>
void Queue<T>::Enqueue(T val){
    if(!isFull()){
        tail = (tail+1) % capacity;
        arr[tail] = val;
        numeroElementi++;
    }
}

template <class T>
T Queue<T>::Dequeue(){
    
    T val = arr[head];
    head = (head+1) % capacity;
    numeroElementi--;
    return val;
}

template <class T>
void Queue<T>::Stampa(){
    int j = head;
    for(int i = 0; i < numeroElementi; i++){
        std::cout << arr[j] << " ";
        j = (j+1)%capacity;
    }
    std::cout << std::endl;
}