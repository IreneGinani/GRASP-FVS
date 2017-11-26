#include <chrono>
#include <random>


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>

#include "../src/greedy_function.cpp"
#include "../src/random_function.cpp"
#include "../src/adaptative_function.cpp"
#include "../src/local_search.cpp"


using namespace std;


void lerArquivo(std::string arq, vector<vertice> &G){
	
	std::string line, token,posi, posj, peso;
	int pi,pj;
	double pes;
	std::ifstream info(arq);
	int counter = 0;
	std::vector<vertice> linhas;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::default_random_engine generator (seed);
	
	for (int i =0; i < 6; i++){

		vertice v;
		v.vert = i;
		v.graus = 0;

		for (int j = 0; j <	 6; j++)
		{
			vertice w;
		    w.graus = -1;
			w.vert = -1;
			
			v.lista_adj.push_back(w);

		}

		G.push_back(v);


	}

	int aux = 0;

	while(!info.eof()){

		getline(info,line);
        std::istringstream ss(line);
        int counter = 1;
        vertice v;
        if (line != ""){
	        while(getline(ss, token,' ')) {

			

	        	counter++;
	        	
	        	if(counter == 2)
	        		posi = token;
	        	else if (counter == 3)
	        		posj = token;
				else if(counter == 4)
					continue;
				else
					break;	

			}
			
			pi = atoi(posi.c_str());
			pj = atoi(posj.c_str());

			
			G[pi].lista_adj[pj].vert = pj;
			
			G[pi].graus = G[pi].graus + 1;
			G[pj].lista_adj[pi].vert = pi;
			
			G[pj].graus = G[pj].graus + 1;

			for (int i = 0; i < G.size(); ++i)
			{
				G[i].lista_adj[pj].graus++;
				G[i].lista_adj[pi].graus++;
			}



		}
	}
}

void print(vector<vertice> G){

	for (int i = 0; i < 6; i++){
		std::cout << G[i].vert <<":";
		for (int j = 0; j < 6; ++j)
		{
			cout << G[i].lista_adj[j].vert << ",";
		}

		std::cout << endl;
	}

	for (int i = 0; i < 6; i++){
		std::cout << G[i].vert <<":";
		
			cout << G[i].graus<< ",";
		

		std::cout << endl;
	}

}

int main(int argc, char const *argv[])
{
	if (argc < 2) {
        std::cerr << "Arquivo nao fornecido." << std::endl;
        exit (1);
    }
    vector<vertice> G;
    vector<vertice> lista_ordenada;
    vector<vertice> lista_elite;
    vector<vertice> melhor_solc;
    vector<vector<vertice>> lista_solucao;
    std::string arquivo = argv[1];
    vertice v;
    lerArquivo(arquivo, G);
    greedy_function(G,lista_ordenada,lista_elite);
    random_function(lista_elite,lista_solucao,v);
    adaptative_function(G,v);
    local_search(lista_solucao,melhor_solc);
    
    //print(G);

    //std::vector<vector<vertice>> matriz_adj (6, std::vector<vertice>(6) );




    
	return 0;
}
