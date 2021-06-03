#include "MGraph.h"
#include <iostream>

//Colore W -> White 
#define W 0 
//Colore G -> Gray 
#define G 1
//Colore B -> Black 
#define B 2
//CAP è la capacità di default
#define CAP 10


template <class T> // O(capacity^2)
MGraph<T>::MGraph(int x) : capacity(x), V(0), E(0){
    Keys = new T*[capacity];
    mAdj = new bool*[capacity];

    for(int i=0; i<capacity; i++){
        mAdj[i] = new bool[capacity];
        Keys[i] = NULL;

        for(int j=0; j<capacity; j++)
            mAdj[i][j] = false;
            
    }
}

template <class T>
MGraph<T>::MGraph() : capacity(CAP), V(0), E(0){
    Keys = new T*[capacity];
    mAdj = new bool*[capacity];

    for(int i=0; i<capacity; i++){
        mAdj[i] = new bool[capacity];
        Keys[i] = NULL;

        for(int j=0; j<capacity; j++)
            mAdj[i][j] = 0;
            
    }
}

template <class T> 
MGraph<T>::~MGraph(){;}

template <class T>
int MGraph<T>::getCapacity() const{ return this->capacity;}

template <class T>
int MGraph<T>::getVetices() const{ return this->V;}

template <class T>
int MGraph<T>::getEdges() const{ return this->E;}

template <class T>
int MGraph<T>::findIndex(T val){
    //Restituisce -1 se x nons si trova nel grafo
    //Restituisce un intero != -1 altrimenti, in quel caso tale 
    //intero è l'indice per trovarlo nel vettore Keys/mAdj;

    for(int i=0; i<V; i++)
        if(*Keys[i] == val) return i;
    
    return -1;
}

template <class T>
void MGraph<T>::addNode(T val) { //E' possibile inserire solo elementi distinti

    if(V==capacity) {
        std::cout << "ERRORE: \tCapacità massima raggiunta, elimina qualche Vertice.\n";
        return;
    }

    int i = findIndex(val);
    
    if(i < 0)
        Keys[V] = new T(val);

    else {
        std::cout << "ERRORE: \tElemento già presente nel grafo!\n";
        return;
    }

    this->V++;
    return;
}

template <class T>
void MGraph<T>::addEdge(T u, T v) { //E' possibile inserire solo elementi distinti
    int index_u = findIndex(u);
    int index_v = findIndex(v);

    if((index_u >=0) && (index_v >= 0) ){
        if(!mAdj[index_u][index_v]){
            mAdj[index_u][index_v] = true;
            this->E++;
        }
    }else std::cout << "ERRORE: \tAlmeno una delle chiavi non è presente all'interno del grafo!\n";

    return;
}


template <class T>
T& MGraph<T>::operator[]( int index)  { //E' possibile inserire solo elementi distinti
    return *Keys[index];
}

template <class T>
T MGraph<T>::operator[]( int index) const { //E' possibile inserire solo elementi distinti
    return *Keys[index];
}


template<class T>
void MGraph<T>::show(){

    for(int i=0; i<V;i++){
        std::cout << this->operator[](i) << "//" ;
    }

    std::cout <<std::endl;
}

template<class T>
void MGraph<T>::Delete(T x){

    int y = findIndex(x);

    if(y<0) return;
    
    for(int i=0; i<V;i++){
        if(mAdj[y][i] == true){
            mAdj[y][i] = false;
            this->E--;
        }
    }

    for(int i=y; i<V-1;i++){
        Keys[i] = Keys[i+1];
    }
    Keys[V] = NULL;
    this->V--;

    std::cout << "Vertice " <<x <<" eliminato" <<std::endl;
}



