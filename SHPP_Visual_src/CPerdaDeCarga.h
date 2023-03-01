/**
@autor Gleison Monteiro | Luisa Campbell
@file CPerdaDeCarga.h
@brief CPerdaDeCarga.h : E uma classe que determina a perda de carga no poco.
*/

#ifndef CPerdaDeCarga_H
#define CPerdaDeCarga_H

//Inclusao de classes das bibliotecas basicas
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "CFluido.h"       //Inclui o arquivo de cabecalho da classe CFluido
#include"CGeometriaPoco.h"  //Inclui o arquivo de cabecalho da classe CGeometriaPoco

using namespace std;

class CPerdaDeCarga {

public:

	//ATRIBUTOS
	double vazao;     ///representa a vazao da bomba 
	double NRec = 2100;  ///representa o numero de reynolds critico

	// Dados relacionados as tubulacoes
	vector<double> tubulacaoID;  ///vetor com os diametros internos das tubulacoes
	vector<double> tubulacaoOD;  ///vetor com os diametros externos das tubulacoes
	
	// Vetores para calculos de velocidade
	vector<double> velTub;         ///vetor que armazena as velocidades calculadas dentro da tubulacao
	vector<double> velAnularFase1; ///vetor que armazena as velocidades na espaco anular da fase 1
	vector<double> velAnularFase2; ///vetor que armazena as velocidades na espaco anular da fase 2
	vector<double> velAnularFase3; ///vetor que armazena as velocidades na espaco anular da fase 3
	vector<double> velAnularFase4; ///vetor que armazena as velocidades na espaco anular da fase 4

	// Vetores para calculo do Numero de Reynolds
	vector<double> reyTub;         ///vetor que armazena os numeros de Reynolds dentro da tubulacao
	vector<double> reyAnularFase1; ///vetor que armazena os numeros de Reynolds no anular da fase 1
	vector<double> reyAnularFase2; ///vetor que armazena os numeros de Reynolds no anular da fase 2
	vector<double> reyAnularFase3; ///vetor que armazena os numeros de Reynolds no anular da fase 3
	vector<double> reyAnularFase4; ///vetor que armazena os numeros de Reynolds no anular da fase 4

	vector<double> gradientes;   ///vetor que armazena os gradientes de perda de carga no poco
	vector<string> tiposDeEscoamento;  ///vetor que armazena o tipo de escoamento nos intervalos

	//METODOS
	CPerdaDeCarga(){}           // Construtor Default
	virtual ~CPerdaDeCarga(){} // Destrutor Default

	void EntradaDadosPerdaDeCarga();  ///Metodo que permite a entrada de parametros da operacao pelo usuario
	void CalculoVelocidadeTubulacao();  ///Calcula as velocidades dentro da tubulacao
	void CalculoVelocidadeAnular(CGeometriaPoco& objPoco);  ///Calcula as velocidades no espaco anular
	void CalculoReynoldsTubulacao(CFluido& objFluido);      ///Calcula os numeros de Reynolds na tubulacao
	void CalculoReynoldsAnular(CFluido& objFluido, CGeometriaPoco& objPoco);  ///Calcula os numeros de Reynolds no anular
	void CalculoPDCTubulacao(CFluido& objFluido, CGeometriaPoco& objPoco);    ///Calcula o gradiente de perda de carga na tubulacao considerando o tipo de regime
	void CalculoPDCAnular(CFluido& objFluido, CGeometriaPoco& objPoco);       ///Calcula o gradiente de perda de carga no espaco anular considerando o tipo de regime
	
	};

#endif