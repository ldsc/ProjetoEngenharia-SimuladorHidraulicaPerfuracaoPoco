/**
@autor Gleison Monteiro | Luisa Campbell
@file CGeometriaPoco.h
@brief CGeometriaPoco : E uma classe que representa a geometria do poco.
*/

#ifndef CGeometriaPoco_H
#define CGeometriaPoco_H

// Inclusao de classes das bibliotecas basicas
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class CGeometriaPoco {

public:

	//ATRIBUTOS
	vector<double> diamPoco;  ///vetor representando os diametros de poco aberto
	vector<double> revesOD;   ///vetor representando os diametros externos dos revestimentos
	vector<double> revesID;   ///vetor representando os diametros internos dos revestimentos
	double profundidadeM;     ///profundidade total do poco em metros
	//double profundidadeFt;    ///profundidade total do poco em pes
	vector<double> compFases;

	//METODOS

	CGeometriaPoco(){}          //Construtor Default
	virtual ~CGeometriaPoco(){} //Destrutor Default
	
	void EntradaDadosGeometriaPoco(); ///Metodo que permite que o usuario entre com dados de geometria de poco lendo de um arquivo texto
	void CalculoFases();              ///Determina o comprimento de cada fase

};

#endif