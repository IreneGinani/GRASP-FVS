#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>


using namespace std;


void random_function(vector<vertice> lista_elite, vector<vector<vertice>> &lista_solucao, vertice &v){

	srand (time(NULL));
	int escolha = rand()%(lista_elite.size()-1);

	vector <vertice> listas_solucao;

	v.vert = escolha;

	if (!busca_vertice(v,listas_solucao))
		lista_solucao.push_back(listas_solucao);


}