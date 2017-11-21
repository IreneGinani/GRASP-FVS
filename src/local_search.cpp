#include <iostream>

using namespace std;

struct vertice {

	int vert;
	int &graus;

}

void local_search(vector<vector<vertice>> solucoes, vector<vertice> melhor_solc){

	vector <int> valor_funcao;
	int melhor_sol = 0;

	int valor_atual = 0;
	int local_atual;

	for (int i = 0; i < solucoes.size(); ++i)
	{
		for (int j = 0; j < solucoes[i].size(); ++j)
		{
			valor_atual = valor_atual + solucoes[i][j].graus;
		}

		valor_funcao.push_back(valor_atual);
	}

	for (int i = 0; i < valor_funcao.size(); ++i)
	{
		if (valor_funcao[i] > melhor_sol){
			melhor_sol = valor_funcao[i];
			local_atual = i;
		}
	}

	for (int i = 0; i < solucoes[local_atual].size(); ++i)
	{
		melhor_solc.push_back(solucoes[local_atual][i]);
	}
}