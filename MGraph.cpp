#include "MGraph.h"
#include "Queue.h"
#include "Queue.cpp"
#include "Nodo.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include <iostream>

//Colore W -> White 
#define W 0 
//Colore G -> Gray 
#define G 1
//Colore B -> Black 
#define B 2
//CAP è la capacità di default
#define CAP 10

#define MAX_INT capacity+1


template <class T> // O(capacity^2)
MGraph<T>::MGraph(int x) : capacity(x), V(0), E(0), color(new int[capacity]), parent(new int[capacity]), distanza(new int[capacity]),f(new int[capacity]), coda(capacity), radici(new int[capacity]){ //Aggiunta inizializzazione degli array : color, parent, distanza
    Keys = new T*[capacity];
    mAdj = new bool*[capacity];
    TAdj = new bool*[capacity];

    for(int i=0; i<capacity; i++){
        mAdj[i] = new bool[capacity];
        TAdj[i] = new bool[capacity];
        Keys[i] = NULL;

        for(int j=0; j<capacity; j++){
            mAdj[i][j] = false;
            TAdj[i][j] = false;
        }       
    }
}

template <class T>
MGraph<T>::MGraph() : capacity(CAP), V(0), E(0), color(new int[capacity]), parent(new int[capacity]), distanza(new int[capacity]),f(new int[capacity]), coda(capacity), pila(new Stack<T>), radici(new int[capacity]){
    Keys = new T*[capacity];
    mAdj = new bool*[capacity];
    TAdj = new bool*[capacity];

    for(int i=0; i<capacity; i++){
        mAdj[i] = new bool[capacity];
        TAdj[i] = new bool[capacity];
        Keys[i] = NULL;

        for(int j=0; j<capacity; j++){
            mAdj[i][j] = false;
            TAdj[i][j] = false;
        }
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
    
    for(int i=0; i<capacity;i++){
        if(mAdj[y][i] == true){
            mAdj[y][i] = false;
            this->E--;
        }
        if(mAdj[i][y] == true){
            mAdj[i][y] = false;
            this->E--;
        }
    }

    for(int i=y; i<V-1;i++){
        Keys[i] = Keys[i+1];
    }
    Keys[V] = NULL;
    this->V--;

    for(int i=0; i<capacity; i++){
        for(int j=y; j<capacity-1; j++){
            mAdj[i][j] = mAdj[i][j+1];
        }
    }
    for(int i=y; i<capacity-1; i++){
        for(int j=0; j<V; j++){
            mAdj[i][j] = mAdj[i+1][j];
        }
    }
}

template <class T>
void MGraph<T>::BFS(T s){
    int i = findIndex(s);

    if(i>=0) BFS_private(i);
    else std::cout << "La chiave non è presente! Ritenta.\n";
}

template <class T>
void MGraph<T>::BFS_private(int u){
    
    for(int i=0; i<V; i++){
        color[i] = W;
        parent[i] = -1;
        distanza[i] = MAX_INT;
    }

    color[u] = G;
    distanza[u] = 0;
    coda.Enqueue(u);

    while(!coda.isEmpty()){
        int x = coda.Dequeue();
        for(int i = 0; i<V; i++){
            if(mAdj[x][i]==true && color[i]==W){
                color[i] = G;
                coda.Enqueue(i);
                parent[i] = x;
                distanza[i] = distanza[x]+1;
            }
        }

        color[x] = B; 
    }
    
    for(int i =0; i<V; i++){
        std::cout << "[ " <<i <<"] ->";
        if(distanza[i]==MAX_INT) std::cout << "inf." <<std::endl;
        else std::cout << distanza[i] <<std::endl;
    }
    
}

template <class T>
void MGraph<T>::ShowAdj(){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(j<V-1)
                std::cout << mAdj[i][j] << "__";
            else
                std::cout << mAdj[i][j];
        }
            
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

template <class T>
void MGraph<T>::DFS(){
   for(int i =0; i<V; i++){
       color[i] = W;
       parent[i] = -1;
   }
   time=0;
   for(int i =0; i<V; i++){
       if(color[i]==W){
           currentRoot = i;
           DFS_visit(i);
       }
   }
}

template <class T>
void MGraph<T>::DFS_visit(int s){
   color[s] = G;
   distanza[s] = time++;
   radici[s] = currentRoot;
   for(int i =0; i<V; i++){
       if(mAdj[s][i] == true && color[i]==W){
           parent[i]=s;
           DFS_visit(i);
       }
   }

   color[s] = B;
   f[s]=time;
   pila.push(s);
}


template <class T>
void MGraph<T>::ShowF(){
   for(int i =0; i<V; i++)
        std::cout << std::endl << " F di " << *Keys[i] << "___ " << f[i] << std::endl; 
}

template <class T>
void MGraph<T>::ShowParent(){
   for(int i =0; i<V; i++){
       if(parent[i]!=-1)
             std::cout << std::endl << "Keys["<<i<<"] :::> " << *Keys[i] << "\tPadre :::>" << *Keys[parent[i]] << std::endl;
       else std::cout << std::endl << "Keys["<<i<<"] :::> " << *Keys[i] << " non ha predecessori.\n"; 
   }
}

template <class T>
int MGraph<T>::DFS_cycle(){
    int cycle = 0;

    for(int i =0; i<V; i++){
       color[i] = W;
       parent[i] = -1;
    }

    this->time = 0;

    for(int i=0; i<V; i++)
        if(color[i]==W)
            cycle|=DFS_cycleVisit(i);

    return cycle;
}

template <class T>
int MGraph<T>::DFS_cycleVisit(int s){
    int cycle=0;
    color[s] = G;
    distanza[s] = time++;

    for(int i = 0; i<V; i++ ){
        if(mAdj[s][i]==true){
            if(color[i]==W){
                parent[i] = s;
                cycle|=DFS_cycleVisit(i);
            }
            if(color[i]==G)
                cycle=1;
            
        }
    }

    color[s] = B;
    f[s]=time++;

    return cycle;
}

/*
template<class T>
void MGraph<T>::TopSort+(){
    for(int i=0; i<V; i++){
        std::cout << *Keys[coda.Dequeue()] << "_";
    }
}*/

template<class T>
void MGraph<T>::TopSort(){
    int cycle = this->DFS_cycle();
    if(cycle) std::cout << "Il Grafo contiene almeno un ciclo.\n";
    else {
        int *s = new int[V];
        for(int i=0; i<V; i++) s[i] = i;
        sort(s,V,f);
        
        for(int i=0; i<V; i++){
            std::cout << "CHIAVE :::> " <<*Keys[s[i]] << " marca temporale uscita ::::> " << f[s[i]] << std::endl;
        }
    }
}

template<class T>
void MGraph<T>::sort(int* a, int n, int* f){
    for(int i =1; i<n; i++){
        int j = i-1;
        while(j>=0 && f[a[j]]<f[a[j+1]]){
            int temp = a[j+1];
            a[j+1] = a[j];
            a[j] = temp;
            j--;
        }
    }
}

template<class T>
int MGraph<T>::getIndex(T x){
    for(int i =0; i<V; i++){
        if(*Keys[i]==x) return i;
    }

    return -1;
}

template<class T>
int MGraph<T>::camminiSD(T x , T y){
    int index = getIndex(x);
    int search = getIndex(y);

    int cycle = this->DFS_cycle();

    if(cycle) {
        std::cout << "Il Grafo contiene almeno un ciclo.\n";
        return -1;
    }

    if(index==-1) return -1;

    for(int i=0; i<V; i++){
        color[i]=W;
        parent[i]=-1;
    }
    pathCount = 0;
    time=0;
    
    return camminiSDvisit(index,search);
}

template<class T>
int MGraph<T>::camminiSDvisit(int u , int v){
    distanza[u] = time++;
    for(int i = 0; i<V; i++){
        if(mAdj[u][i]==true){
            if(i==v) pathCount++;
            parent[i]=u;
            camminiSDvisit(i,v);
        }
    }

    return this->pathCount;
}

template<class T>
void MGraph<T>::calcolaTrasposta(){
    for(int i=0; i<V; i++){
        for(int j =0; j<V; j++){
            TAdj[i][j] = mAdj[j][i];
        }
    }
}

template<class T>
void MGraph<T>::DFS_T(){
    for(int i=0; i<V; i++){
        color[i]=W;
        parent[i]=-1;
    }

    time=0;
    while(!pila.isEmpty()){
        int i = pila.pop();

        if(color[i]==W){
            currentRoot=i;
            DFS_Tvisit(i);
        }
    }
}

template<class T>
void MGraph<T>::DFS_Tvisit(int s){
    color[s]=G;
    radici[s]=currentRoot;

    for(int i=0; i<V; i++){
        if(TAdj[s][i]==true && color[i]==W){
            parent[i] = s;
            DFS_Tvisit(i);
        }
    }
    color[s]=B;
}

template <class T>
void MGraph<T>::printSCC(){
    std::cout << "Componenti Fortemente Connesse : \n";

    int flag=0;

    for(int i =0; i<V; i++){
        for(int j=0; j<V; j++)
            if(radici[j]==i) {
                flag=1;
                std::cout << *Keys[j] << " ";
            }
        
        if(flag){
            std::cout <<"\n";
            flag=0;
        }
    }
}