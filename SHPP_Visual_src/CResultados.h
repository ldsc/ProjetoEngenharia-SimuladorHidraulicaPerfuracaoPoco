/**
@autor Gleison Monteiro | Luisa Campbell
@file CResultados.h
@brief CResultados : E uma classe que disponibiliza ao usuario diversas formas de plotar os resultados. 
*/


#ifndef CResultados_H
#define CResultados_H

//Inclusao de classes das bibliotecas basicas
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


#include "CFluido.h"       //Inclui o arquivo de cabecalho da classe CFluido.h
#include "CGeometriaPoco.h"  //Inclui o arquivo de cabecalho da classe CGeometriaPoco.h
#include "CPerdaDeCarga.h"   //Inclui o arquivo de cabecalho da classe CPerdaDeCarga.h
#include "CGnuplot.h"        //Inclui a classe CGnuplot


using namespace std;

class CResultados {

public:

	//ATRIBUTOS
	vector<double> gradientesM;     ///vetor de gradientes de perda de carga em psi/metro

	vector<double> xFase1;          ///vetor de profundidade para plotar a fase 1
	vector<double> xFase2;          ///vetor de profundidade para plotar a fase 2
	vector<double> xFase3;          ///vetor de profundidade para plotar a fase 3
	vector<double> xFase4;          ///vetor de profundidade para plotar a fase 4

	vector<double> yFase1;          ///vetor de queda de pressao acumulada para plotar a fase 1
	vector<double> yFase2;          ///vetor de queda de pressao acumulada para plotar a fase 2
	vector<double> yFase3;          ///vetor de queda de pressao acumulada para plotar a fase 3
	vector<double> yFase4;          ///vetor de queda de pressao acumulada para plotar a fase 4

	double pMaxFase1;				///representa a perda de pressao total da fase 1
	double pMaxFase2;				///representa a perda de pressao total da fase 2
	double pMaxFase3;				///representa a perda de pressao total da fase 3
	double pMaxFase4;				///representa a perda de pressao total da fase 4

	//double deltaPMax;             ///representa a queda de pressao maxima no poco

	
	//METODOS

	CResultados(){}           // Construtor Default
	virtual ~CResultados(){} // Destrutor Default

	void GradienteEmMetros(CPerdaDeCarga perdaCarga);               ///Converte o gradiente para psi por metro
	void SaidaDeDados(vector<double> x, vector<double> y, string nomeDoArquivo);   ///Permite salvar os dados em arquivo texto
	void MenuResultados(CPerdaDeCarga perdaCarga);                                 ///Oferece ao usuario opcoes de saida de dados
	void VetoresProfundidade(CGeometriaPoco geometria);                            ///Define as profundidades para plotar graficos exportar os resultados
	void VetoresPressao(CPerdaDeCarga carga, CGeometriaPoco geometria);            ///Define as quedas de pressao em cada profundidade 
	void CalculoPerdaPressaoTotal (CPerdaDeCarga carga, CGeometriaPoco geometria); ///
	void PlotarDados(CGnuplot& graficos, vector<double>& x, vector<double>& y);    ///Define como salvar os graficos gerados pelo programa com o auxilio da biblioteca externa Gnuplot
	void PlotarDados(CGnuplot& graficos, vector<double>& x1, vector<double>& y1, vector<double>& x2, vector<double>& y2, vector<double>& x3, vector<double>& y3, vector<double>& x4, vector<double>& y4);    ///Define como salvar os graficos gerados pelo programa com o auxilio da biblioteca externa Gnuplot		

};
#endif
