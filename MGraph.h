#pragma once

template <class T>

class MGraph{

private:

    int capacity, V, E; //Capacità massima del grafo, numero attuale di nodi, numero attuale di archi
    T** Keys; //Matrice quadrata  di oggetti di tipo T
    bool ** mAdj; //Matrice di adiacenza

    int *c; //matrice dei colori
    int *p; //matrice deipadri
    int* d; //matrice delle distanze

    int *in; //matrice dei tempi d'ingresso
    int *out;// matrice tempi di uscita

    int time; // variabile per i tempi

    int findIndex(T val);
    
public:
    // Costruttore al quale va passato un intero che determina la capacità, ovvero il numero massimo di Vertici.
    MGraph(int x);
    MGraph();
    // Distruttore;
    ~MGraph();
    //Metodo che permette di insierire un elemento all'interno del grafo.
    void addNode(T val); //AddNode
    void addEdge(T u, T v);
    //void Delete(T val);
    void show();
    int getCapacity() const;
    int getVetices() const;
    int getEdges() const;


    T& operator [] ( int index) ;
    T operator [] ( int index) const ;
    //T getData(int index) const;

};
