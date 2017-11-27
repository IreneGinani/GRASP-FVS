#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 

using namespace std;


int somaGraus(vector<vertice> solucao_melhor){

	 int soma = 0;

	for (int i = 0; i < solucao_melhor.size(); ++i)
	{
		soma = soma + solucao_melhor[i].graus;
	}

	return soma;
}

void local_search(vector<vector<vertice>> solucoes, vector<vertice> &melhor_solc){

	vector <int> valor_funcao;
	int melhor_sol = 0;

	int valor_atual = 0;
	int local_atual;
	int s = 0;

	vertice v;
	v.graus = 10000;
	melhor_solc.push_back(v);


	for (int i = 0; i < solucoes.size(); ++i)
	{
		for (int j = 0; j < solucoes[i].size(); ++j)
		{
			valor_atual = valor_atual + solucoes[i][j].graus;

		    //cout << solucoes[i][j].vert << endl;
		}

		valor_funcao.push_back(valor_atual);
		//cout << "/" << endl;

	}




	for (int i = 0; i < valor_funcao.size(); ++i)
	{
		if (valor_funcao[i] <= somaGraus(melhor_solc)){
			melhor_sol = valor_funcao[i];
			local_atual = i;

		}


	}



	for (int i = 0; i < solucoes[local_atual].size()-1; ++i)
	{
		
		melhor_solc.push_back(solucoes[local_atual][i]);
		//cout << solucoes[local_atual][i].vert << "ppp" <<endl;


	}

	
	
	//cout << escolha << endl;

	while(s=0){

		if (valor_funcao[local_atual] < valor_funcao[valor_funcao.size()-1]){

		

			for (int i = 0; i < melhor_solc.size(); ++i)
			{
				melhor_solc[i] = solucoes[solucoes.size()][i];
			}

			s = 0;
		}else{
			s = 1;
		}
	}

	

	
}