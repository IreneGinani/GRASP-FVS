#include <chrono>
#include <random>



using namespace std;

struct vertice {

	int vert;
	int &graus;

}

void lerArquivo(std::string arq, vector<vector<vertice>> &G){
	
	std::string line, token,posi, posj, peso;
	int pi,pj;
	double pes;
	std::ifstream info(arq);
	int counter = 0;
	std::vector<vertice> linhas;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::default_random_engine generator (seed);
	
	for (int i =0; i < 6; i++){
		for (int j = 0; j <	 6; j++)
		{
			vertive v.graus = 0;
			linhas.push_back(w);

		}

		G.matriz_adj.push_back(linhas);
		linhas.clear();


	}

	int aux = 0;
	while(!info.eof()){

		getline(info,line);
        std::istringstream ss(line);
        int counter = 1;
        vertice v;
        while(getline(ss, token,' ')) {

        	counter++;
        	
        	if(counter == 3)
        		posi = token;
        	else if (counter == 4)
        		posj = token;
			else if(counter == 2)
				continue;
			else
				break;	

			
		}
		
		pi = atoi(posi.c_str());
		pj = atoi(posj.c_str());

		
		
		G.matriz_adj[pi][pj].vert = pj;
		G.matriz_adj[pi][pj].graus++;
		G.matriz_adj[pj][pi].vert = pi;
		G.matriz_adj[pj][pi].graus++;

		//std::cout <<G.matriz_adj[pi][pj]<<std::endl;

	}
}

void print(vector<vector<vertice>> G){

	for (int i = 0; i < 6; i++){
		std::cout << i <<":";
		for (int j = 0; j < 6; ++j)
		{
			cout << G.matriz_adj[i][j].vert << ",";
		}

		std::cout << endl;
	}

}

int main(int argc, char const *argv[])
{
	if (argc < 2) {
        std::cerr << "Arquivo nao fornecido." << std::endl;
        exit (1);
    }
    vector<vector<vertice>> G;
    std::string arquivo = argv[1];
    lerArquivo(arquivo, G);
    //print(G);

    std::vector<vector<vertice>> matriz_adj (6, std::vector<vertice>(6) );

    
	return 0;
}
