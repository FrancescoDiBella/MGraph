#include "MGraph.h"
#include "MGraph.cpp"
#include <iostream>
#include <ctime>

int randomic(int x){
    return rand()%x;
}

int main(){
    
    srand(time(NULL)); 
    char lettere[16] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};  
    
    /*
    
    for(int i = 0 ; i < 10; i++){
        g.addNode(lettere[randomic(16)]);
    }

       for(int i = 0 ; i < 10; i++){
        g.addEdge(lettere[randomic(16)],lettere[randomic(16)]);
    }

   
    g.BFS('h');

    g.show();
    std:: cout << "\nNumero vertici:\t" << g.getVetices() << "\t Numero archi: \t" <<g.getEdges() <<std::endl;

    g.Delete(lettere[randomic(16)]);

    g.show();
    std:: cout << "\nNumero vertici:\t" << g.getVetices() << "\t Numero archi: \t" <<g.getEdges() <<std::endl;
    
    */
   MGraph<char> g(10);
   char l [10];
   for(int i =0; i<10; i++){
       l[i] = lettere[randomic(16)];
       g.addNode(l[i]);
   }

   for(int i =0; i<10; i++){
       g.addEdge(l[randomic(10)], l[randomic(10)]);
   }
 
    g.show();

    g.BFS(l[randomic(10)]);
    return 0;
}