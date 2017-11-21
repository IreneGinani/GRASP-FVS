#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       


using namespace std;

struct vertice {

	int vert;
	int graus;

}

void random_function(vector<vertice> lista_elite, vector<vertice> &lista_solucao){

	srand (time(NULL));
	int escolha = rand()%(lista_elite.size()-1);

	if (!busca_vertice(escolha,lista_solucao))
		lista_solucao.push_back(lista_elite[escolha]);
}