#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>


using namespace std;

int numeroAleatorio( int maior) {
       return rand()%maior;
}

void random_function(vector<vertice> lista_elite, vector<vertice> &lista_solucao, vertice &v){

	
		int escolha = numeroAleatorio(lista_elite.size());


		v.vert = lista_elite[escolha].vert;
		v.graus = lista_elite[escolha].graus;

		
		if (!busca_vertice(v,lista_solucao) && (v.graus > 0)){
			//cout << v.vert << endl;
			lista_solucao.push_back(v);
			//cout << lista_elite[escolha].vert << endl;
		}

		


	  

	


}