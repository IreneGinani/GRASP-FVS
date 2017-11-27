#include <iostream>

using namespace std;


void adaptative_function(vector<vertice> &grafo, vertice entrada){

	for (int i = 0; i < grafo.size(); ++i)
	{
		grafo[entrada.vert].graus--;
		grafo[i].lista_adj[entrada.vert].graus--;
	}

}