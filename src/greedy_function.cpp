#include <iostream>
#include <vector>


using namespace std;

struct vertice {

	int vert;
	int graus;
	vector<vertice> lista_adj;

};

bool busca_vertice(vertice v, vector<vertice> lista_ordenada){

	for (int i = 0; i < lista_ordenada.size(); ++i)
	{
		if ((v.vert == lista_ordenada[i].vert)){
			return true;
		}
	}

	return false;

}

void OrdenaVertices(vector<vertice> grafo,vector<vertice> &lista_ordenada){

	vertice valor;
	valor.vert  = 0;
	valor.graus = 0;
	int qtd_vertices = 0;

	for (int i = 0; i < grafo.size(); ++i)
	{
		if (grafo[i].graus > 0){
			qtd_vertices++;
		}
	}


	for (int i = 0; i < qtd_vertices; ++i)
	{
		for (int j = 0; j < grafo.size(); ++j)
		{

			if ((grafo[j].graus >= valor.graus) && (!busca_vertice(grafo[j],lista_ordenada)) && (grafo[j].graus > 0)){

				valor = grafo[j];
				

			}
		}

		lista_ordenada.push_back(valor);
	}



}

void greedy_function(vector<vertice> grafo, vector<vertice> &lista_ordenada, vector<vertice> &lista_elite){

	OrdenaVertices(grafo,lista_ordenada);
	vertice vertice_min = lista_ordenada[lista_ordenada.size()-1];
	vertice vertice_max = lista_ordenada[0];
	double alfa = 0.5; //pode variar de 0 à 1

	for (int i = 0; i < grafo.size(); ++i)
	{
		for (int j = 0; j < grafo[i].lista_adj.size(); ++j)
		{
			if ((grafo[i].graus >= (vertice_min.graus + alfa * (vertice_max.graus - vertice_min.graus))) && (!busca_vertice(grafo[i],lista_elite))){

				lista_elite.push_back(grafo[i]);

			}
		}
	}

	// std::cout << vertice_max.vert << endl;
	// std::cout << vertice_min.vert << endl;


	// for (int i = 0; i < lista_elite.size(); ++i)
	// {
	// 	std::cout << lista_elite[i].vert << std::endl;
	// }

}
