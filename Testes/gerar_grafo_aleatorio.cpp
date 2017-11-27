#include <chrono>
#include <random>

#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>
#include <chrono>

#include "../src/greedy_function.cpp"
#include "../src/random_function.cpp"
#include "../src/adaptative_function.cpp"
#include "../src/local_search.cpp"


using namespace std;


void grafo_aleatorio(vector<vertice> &G){


		for (int i = 0; i < G.size(); ++i)
		{
			for (int j = 0; j < G[i].lista_adj.size(); ++j)
			{

				if(( i%2 == 0) || (j%2 == 0)){

		
					G[i].lista_adj[j].vert = j;
					
					G[i].graus = G[i].graus + 1;
					G[j].lista_adj[i].vert = i;
					
					G[j].graus = G[j].graus + 1;

					for (int i = 0; i < G.size(); ++i)
					{
						G[i].lista_adj[j].graus++;
						G[i].lista_adj[i].graus++;
					}
				}

			}
		}
	
}

void print(vector<vertice> G){

	for (int i = 0; i < 200; i++){
		std::cout << G[i].vert <<":";
		for (int j = 0; j < 200; ++j)
		{
			cout << G[i].lista_adj[j].vert << ",";
		}

		std::cout << endl;
	}

	// for (int i = 0; i < 6; i++){
	// 	std::cout << G[i].vert <<":";
		
	// 		cout << G[i].graus<< ",";
		

	// 	std::cout << endl;
	// }

}

bool tem_ciclo(vector<vertice> grafo,vector<vertice> listas_solucao){



	std::stack<int> pilha;
	int ciclo;
	std::vector<vector <int>> marcados;
	vector <int> list;
	vector <int> marcados1;
	int ant,antj;

	int v = 0;


	for (int i = 0; i < listas_solucao.size(); ++i)
	{
		for (int j = 0; j < grafo.size(); ++j)
		{
			

			grafo[listas_solucao[i].vert].lista_adj[j].vert = -1;
			grafo[listas_solucao[i].vert].lista_adj[j].vert = -1;

			//cout << grafo[listas_solucao[i].vert].lista_adj[j].vert << endl;
		}
		
	}

	for (int i = 0; i < grafo.size(); ++i)
	{
		for (int j = 0; j < grafo.size(); ++j)
		{
			list.push_back(0);
		}
		marcados.push_back(list);
		list.clear();
		marcados1.push_back(0);
	}

	//


	while(true){

		
		
		if (marcados1[v]== 0){

			marcados1[v] = 1;


			pilha.push(v);
		
		}


		int achou = 0; 
		int j = 0;


			for (j; j < grafo[v].lista_adj.size(); ++j)
			{
				// print(grafo);
				if((grafo[v].lista_adj[j].vert >= 0) && (marcados1[j] == 0)){
					achou = 1; 
					grafo[v].lista_adj[j].vert == -2;
					marcados1[j] = 1;
					marcados[v][j] = 1;
					marcados[j][v] = 1;
					break;
				}else if ((marcados1[j] == 1) && (v!=j) && (grafo[v].lista_adj[j].vert >= 0) && (marcados[v][j] == 0)){
					 return true;
				}
			
			} 
			
			if (achou == 1){
				ant = v;
				v = j;
				// cout << v << "MM" << endl;

			}
			else if (v!=grafo.size()-1)
				v++;
			else{

				pilha.pop();

				if(pilha.empty()){
					break;
				}

				v = pilha.top();
			}

	}

	return false;
}


int main(int argc, char const *argv[])
{
	vector<vertice> G;
    vector<vertice> lista_ordenada;
    vector<vertice> lista_elite;
    vector<vertice> melhor_solc;
    vector<vertice> solucao (3);
    vector<vertice> lista_solucao;
    vector<vector<vertice>> listas_solucao (1, std::vector<vertice>(1) );
    std::string arquivo = argv[1];
    vertice v;
    vertice w;
    w.graus = 100000;
    solucao.push_back(w);
    grafo_aleatorio(G);
    int c = 0;
    int c1 = 0;

    srand((unsigned)time(0));

    std::chrono::time_point<std::chrono::system_clock> inicio, fim;
	unsigned long long int nanosegundos_decorridos;

	inicio = std::chrono::system_clock::now();

     while (c < 100){

    	 	do{
    	 		greedy_function(G,lista_ordenada,lista_elite);
		   		random_function(lista_elite,lista_solucao,v);
				adaptative_function(G,v);

				
		 		c1++;
    	 	}while (tem_ciclo(G,lista_solucao));
		   
		//cout << "sim" << endl;

		listas_solucao.push_back(lista_solucao);

		melhor_solc.clear();

	   local_search(listas_solucao,melhor_solc);

	    

	    //cout << "sim" << somaGraus(melhor_solc) << endl;

	    if (somaGraus(melhor_solc) < somaGraus(solucao)) {



	    	for (int i = 0; i < melhor_solc.size(); ++i)
	    	{

	    	 	solucao[i] = melhor_solc[i];
	    	 	//cout << melhor_solc[i].vert << endl;
	    	}
	    }

	    // lista_ordenada.clear();
    	// lista_elite.clear();

    	c++;
    	c1 = 0;
    	

    	
	 }

	 fim = std::chrono::system_clock::now();
    
 //    //print(G);

	 nanosegundos_decorridos = std::chrono::duration_cast<std::chrono::nanoseconds> (fim-inicio).count();

	 std::cout<<nanosegundos_decorridos<<" ns" << endl;

	cout << "tamanho do conjunto: " << solucao.size() -2 << endl;

	cout << "Vertices na solução: " << endl;

    for (int i = 1; i < solucao.size() -1 ; ++i)
	{
	    cout << solucao[i].vert << endl;
   	}

    //std::vector<vector<vertice>> matriz_adj (6, std::vector<vertice>(6) );




    
	return 0;
}
