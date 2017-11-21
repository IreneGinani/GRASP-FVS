#include <iostream>
#include <vector>


using namespace std;

struct vertice {

	int vert;
	int graus;

}


void greedy_funciont(vector<vector<vertice>> grafo, vector<vertice> lista_ordenada, vector<vertice> lista_elite){

	vertice vertice_min = lista_ordenada[lista_ordenada.size()-1];
	vertice vertice_max = lista_ordenada[0];
	alfa = 0.5 //pode variar de 0 à 1

	for (int i = 0; i < grafo.size(); ++i)
	{
		for (int j = 0; j < grafo[0].size(); ++j)
		{
			if ((grafo[i][j] >= (vertice_min + alfa * (vertice_max - vertice_min))) && (!busca_vertice(valor,lista_elite))){

				lista_elite.push_back(grafo[i][j]);

			}
		}
	}

}

void OrdenaVertices(vector<vector<vertice>> grafo){

	vector<vertice> lista_ordenada;

	vertice valor;

	for (int i = 0; i < grafo.size(); ++i)
	{
		for (int j = 0; j < grafo[0].size(); ++j)
		{

			if ((grafo[i][i].graus > grafo[i][j].graus) && (!busca_vertice(valor))){

				valor = grafo[i][i];

			}else if (!busca_vertice(valor,lista_ordenada)){
				
				valor = grafo[i][j];

			}
		}

		lista_ordenada.push_back(valor, lista_ordenada);
	}



}

bool busca_vertice(vertice v, vector<vertice> lista_ordenada){

	for (int i = 0; i < lista_ordenada.size(); ++i)
	{
		if ((v.vert == lista_ordenada[i].vert) && (v.graus == lista_ordenada[i].graus)){
			return true;
		}
	}

	return false;

}