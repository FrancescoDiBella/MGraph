#pragma once
#include "Queue.h"
#include "Stack.h"

template <class T>
class MGraph{

private:

    int capacity, V, E; //Capacità massima del grafo, numero attuale di nodi, numero attuale di archi
    T** Keys; //Matrice quadrata  di oggetti di tipo T
    bool ** mAdj; //Matrice di adiacenza
    bool ** TAdj; //Matrice di adiacenza

    int *color; //matrice dei colori
    int *parent; //matrice deipadri
    int * distanza; //matrice delle distanze
    int * f; //marche temporali
    int *in; //matrice dei tempi d'ingresso
    int *radici;// matrice tempi di uscita
    int currentRoot = 0;
    int pathCount = 0;

    int time; // variabile per i tempi
    Queue<int> coda;
    Stack<int> pila;
    int findIndex(T val);

    void BFS_private(int u);
    void DFS_visit(int u);
    int DFS_cycleVisit(int u);

    
    
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
    int getIndex(T x);


    void BFS(T);
    void DFS();
    void ShowAdj();
    void ShowF();
    void ShowParent();

    int DFS_cycle();

    int camminiSDvisit(int x, int y);
    int camminiSD(T x, T y);

    void calcolaTrasposta();
    void DFS_T();
    void DFS_Tvisit(int );

    void TopSort();
    void printSCC();
    void sort(int* a, int n, int* f);
    T& operator [] ( int index);
    T operator [] ( int index) const ;

};
