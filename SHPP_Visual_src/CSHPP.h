/**
@autor Gleison Monteiro | Luisa Campbell
@file CSHPP.h
@brief CSHPP.h: E uma classe que representa o simulador de hidraulica de perfuracao
*/

#ifndef CSHPP_H
#define CSHPP_H

//Inclusao das bibliotecas basicas
#include <string>
#include <iostream>

#include "CFluido.h"         //Inclui o arquivo de cabecalho da classe CFluido.h
#include "CGeometriaPoco.h"  //Inclui o arquivo de cabecalho da classe CGeometriaPoco.h
#include "CPerdaDeCarga.h"   //Inclui o arquivo de cabecalho da classe CPerdaDeCarga.h
#include "CResultados.h"     //Inclui o arquivo de cabecalho da classe CResultados.h
#include "CGnuplot.h"        //Inclui a classe CGnuplot

using namespace std;

class CSHPP {

public:

	//ATRIBUTOS


	//METODOS
	CSHPP(){}           // Construtor Default
	virtual ~CSHPP(){} // Destrutor Default
	void Simulacao();  ///Metodo que representa a simulacao de hidraulica






};




#endif
