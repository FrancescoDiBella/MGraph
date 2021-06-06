#pragma once
#include "Queue.h"

template <class T>
class MGraph{

private:

    int capacity, V, E; //Capacità massima del grafo, numero attuale di nodi, numero attuale di archi
    T** Keys; //Matrice quadrata  di oggetti di tipo T
    bool ** mAdj; //Matrice di adiacenza

    int *color; //matrice dei colori
    int *parent; //matrice deipadri
    int* distanza; //matrice delle distanze
    int* f;
    int *in; //matrice dei tempi d'ingresso
    int *out;// matrice tempi di uscita

    int time; // variabile per i tempi
    Queue<int> coda;
    int findIndex(T val);

    void BFS_private(int u);
    void DFS_visit(int u);

    
    
public:
    // Costruttore al quale va passato un intero che determina la capacità, ovvero il numero massimo di Vertici.
    MGraph(int x);
    MGraph();
    // Distruttore;
    ~MGraph();
    //Metodo che permette di inserire un elemento all'interno del grafo.
    void addNode(T val); //AddNode
    void addEdge(T u, T v);
    void Delete(T val);
    void show();
    int getCapacity() const;
    int getVetices() const;
    int getEdges() const;

    void BFS(T);
    void DFS();
    void ShowAdj();
    void ShowF();
    void ShowParent();

    T& operator [] ( int index);
    T operator [] ( int index) const ;

};
