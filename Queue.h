#pragma once


template <class T>
class Queue{
    private:
    int capacity;
    T * arr;
    int head;
    int tail;
    int numeroElementi;

    public:
        Queue(int n); 
        void Enqueue(T val);
        T Dequeue();
        bool isEmpty(); //true if it is empty
        bool isFull(); //true if it is full
        void Stampa();

};
