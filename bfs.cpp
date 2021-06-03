/* 
Corso di Programmazione II (A-L), Prof. Dario Catalano 

Esercizi su Grafi

Esercizio 3: Algoritmo BFS usando matrici di adiacenza
*/
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

#define W 0
#define G 1
#define B 2
#define inf len+1


class Coda {
private: 
	int* VettoreCoda;
	int DimCoda; 
	int testa;
	int fine; 
	int num_elementi;	
public:
	Coda(int DimCoda); //Costruttore della coda
	void Enqueue(int elemento); //Inserisce un elemento nella coda
	int Dequeue();  //Estrae un elemento dalla coda
	int Testa(); // Legge l'elemento in testa alla coda senza estrarlo 
	int CodaVuota() {return (num_elementi==0);} // Verifica se la coda è vuota
	int CodaPiena() {return (num_elementi==DimCoda);} // Verifica se la coda è piena
}; 

Coda::Coda(int len) {
	DimCoda=len; 
	VettoreCoda = new int[len]; 
	testa=0; fine=-1; num_elementi=0;
} 

void Coda::Enqueue(int x) 
{	
	if (this->CodaPiena())
		cerr << "Coda piena! \n";  	
	else {  
		fine=(fine + 1) % DimCoda; 
		VettoreCoda[fine]=x;
		num_elementi++;
		}
}

int Coda::Testa()
{
	return testa;  
}


int Coda::Dequeue()
{	int x;
	
	if (CodaVuota()) {
		cerr << "Coda Vuota!" << endl; 
		return -1;  }
	else 	{ 
		x=VettoreCoda[testa];
		testa=(testa+1) % DimCoda;
		num_elementi--;
		return x; 
		}
}

template <class H> class MGraph {
	private:
		int len, n, m;
		/* 	n numero di nodi effettivo, 
			m numero di archi effettivo, 
			len numero massimo di nodi
		*/
		int **M; //Matrice di adiacenza
		int t;
		H **K;  // Matrice degli indici
		int *d, *p; //, *f, *c, *r;
		
		
		int findIndex(H x) {
		// Associa un indice al nodo (se esiste)
			for(int i=0; i<n; i++)
				if(*K[i] == x) return i;
			return -1;
		}
		
		void printPath(int x) {
			if(x==-1) return;
			if(p[x]==-1) cout << x; 
			else {
				printPath(p[x]);
				cout << "->" << x; 
			}
		}
		
	public:
		MGraph(int len) {
			this->len = len;
			n = m = 0;
			d = new int[len]; /* vettore delle distanze 
								(dalla sorgente) 
								*/	
			p = new int[len]; // vettore dei precedenti
			
			M = new int*[len];
			for(int i=0; i<len; i++) {
				M[i] = new int[len];
				for(int j=0; j<len; j++)
					M[i][j] = 0;
			}
			K = new H*[len];
			for(int i=0; i<len; i++) K[i] = NULL;
		}
		
		MGraph<H>* addNode(H k) {
			if(n==len) return this;
			if(findIndex(k)>=0) return this;
			K[n] = new H(k);
			n++;
			return this;
		}
		
		MGraph<H>* addEdge(H x, H y) {
			int i = findIndex(x);
			int j = findIndex(y);
			if(i<0 || j<0) return this;
			if(!M[i][j]) {
				M[i][j] = 1;
				m++;
			}
			return this;
		}
		
		void print() {
			for(int i=0; i<n; i++) {
				cout << "(" << i << ", " << *K[i] << ")" << " : ";
				for(int j=0; j<n; j++) {
					if(M[i][j]) cout << *K[j] << " ";
				} 
				cout << endl;
			}
		}
		
		void BFSp(int s) {
			int c[len];
			Coda *Q = new Coda(len);
			//iniz.
			for(int i=0; i<n; i++) {
				c[i] = W;
				p[i] = -1;
				d[i] = inf;
			}
			Q->Enqueue(s);
			c[s] = G;
			d[s] = 0;	
			while(!Q->CodaVuota()) {
				int x = Q->Dequeue();
				for(int i=0; i<n; i++) {
					if(M[x][i]==1) {
						if(c[i]==W) {
							c[i] = G;
							Q->Enqueue(i);
							p[i] = x;
							d[i] = d[x]+1;
						}
					} 
				}
				c[x] = B;
			}
			for(int i=0; i<n; i++) {
				cout << "[" << i << "]->";
				if(d[i]==inf) cout << "inf." << endl;
				else cout << d[i] << endl;
			}
			cout << endl;
		}
		
		void BFS(H x) {
			int s = findIndex(x);
			if(s>=0) BFSp(s);
		}
		
};

int main() {
	MGraph<int> *Gr = new MGraph<int>(3);
	Gr->addNode(2)->addNode(8)->addNode(0);

	
	Gr->addEdge(2,0)->addEdge(0,2);
	Gr->addEdge(8,0);
	Gr->addEdge(0,8);

	Gr->BFS(2);
	return 0;		
}