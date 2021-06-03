#include "MGraph.h"
#include "MGraph.cpp"
#include <iostream>
#include<ctime>

int randomic(int x){
    return rand()%x;
}

int main(){
    srand(time(NULL)); 
    char lettere[16] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};  
    MGraph<char> g(25);
    
    for(int i = 0 ; i < 10; i++){
        g.addNode(lettere[randomic(16)]);
    }

       for(int i = 0 ; i < 10; i++){
        g.addEdge(lettere[randomic(16)],lettere[randomic(16)]);
    }


    g.show();
    std:: cout << "\nNumero vertici:\t" << g.getVetices() << "\t Numero archi: \t" <<g.getEdges() <<std::endl;

    g.Delete(lettere[randomic(16)]);

    g.show();
    std:: cout << "\nNumero vertici:\t" << g.getVetices() << "\t Numero archi: \t" <<g.getEdges() <<std::endl;

    return 0;
}