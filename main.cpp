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
   
   MGraph<int> g(10);
   /*
   char l [10];
   for(int i =0; i<10; i++){
       l[i] = lettere[randomic(16)];
       g.addNode(l[i]);
   }

   for(int i =0; i<10; i++){
       g.addEdge(l[randomic(10)], l[randomic(10)]);
   }
    */
   g.addNode(4);
   g.addNode(8);
   g.addNode(5);
   g.addNode(7);
   g.addNode(1);
   g.addNode(3);

   g.addEdge(7,3);
    g.addEdge(3,8);
    g.addEdge(8,7);
    g.addEdge(8,1);
 g.addEdge(1,5);
  g.addEdge(5,4);
   g.addEdge(4,1);
  
   



    //g.show();
    /*
        creare  una classe F_BST e un  metodo della classe0 che, preso in input un file con chiavi e chiavi padre
        riesca a creare una foresta BST;
    */
    //g.BFS(8);
    g.DFS();
    g.calcolaTrasposta();
    g.DFS_T();
    g.printSCC();
    //g.ShowParent();
    //g.TopSort();
    /*int source = 5;
    int dest = 4;
    std::cout <<"NUMERO DI CAMMINI SEMPLICI DA " <<source << " A " <<dest << " ::::>  " << g.camminiSD(source,dest) <<std::endl;
    */
    return 0;
}