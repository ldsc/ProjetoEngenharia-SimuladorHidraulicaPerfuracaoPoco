/**
@autor Gleison Monteiro | Luisa Campbell
@file CGeometriaPoco.cpp
@brief CGeometriaPoco.cpp : Implementa os metodos da classe CGeometriaPoco
*/

// Inclusao de classes e bibliotecas
#include <fstream>
#include <string>

#include "CGeometriaPoco.h"    //Inclui o arquivo de cabecalho da classe CGeometriaPoco

using namespace std;

void CGeometriaPoco::EntradaDadosGeometriaPoco(){

	bool flag = false;
	cout << "Entre com o nome do arquivo texto de onde deseja ler os dados da geometria do poco - diametro do poco (in), diametro externo do revestimento (in) e diametro interno do revestimento (in):" << endl;
	string nomeArquivo;
	
	///O loop ira garantir que o usuario entre com um nome de arquivo existente no diretorio local
	while (!flag){

		cin >> nomeArquivo;
		cin.get();
		nomeArquivo.append(".txt");
		
		ifstream fin(nomeArquivo);
				

		if (!fin.is_open()){    ///Nesta opcao, o usuario entrou com um nome de arquivo invalido e tera que repetir a entrada
			cout << "Erro: Arquivo nao encontrado." << endl;
			cout << "Entre novamente o nome do arquivo." << endl;
		}

		else {     ///Nesta opcao, os dados serao lidos e armazenados

			string cabecalho;
			getline(fin, cabecalho);

			while (!fin.eof()) {
				string _diamPoco, _revesOD, _revesID;   
									
				fin >> _diamPoco;  
				fin >> _revesOD;   
				fin >> _revesID;  

				diamPoco.push_back(stod(_diamPoco));
				revesOD.push_back(stod(_revesOD));
				revesID.push_back(stod(_revesID));

			}

			fin.close();
			flag = true;
		}

	}
	
	cout << " \n";
};


void CGeometriaPoco::CalculoFases(){

	cout << "Entre com a profundidade total do poco, em metros:" << endl;
	cin >> profundidadeM;
	cin.get();
    cout << " \n";

	//O comprimento de cada fase foi baseado em um historico de perfuracao dos pocos do pre sal

	compFases.push_back(profundidadeM*0.02); // Determinar a profundidade da fase 1 (superficie)
	compFases.push_back(profundidadeM*0.38); // Determinar a profundidade da fase 2 (intermediaria 1)
	compFases.push_back(profundidadeM*0.87); // Determinar a profundidade da fase 3 (intermediaria 2)
	compFases.push_back(profundidadeM); // Determinar a profundidade da fase 4 (reservatorio)
	
};
