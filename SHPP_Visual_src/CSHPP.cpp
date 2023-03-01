/**
@autor Gleison Monteiro | Luisa Campbell
@file CSHPP.cpp
@brief CSHPP.cpp : Implementa os metodos da classe CSHPP.h
*/

// Inclusao de classes e bibliotecas
#include "CSHPP.h"

void CSHPP::Simulacao() {

	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                    Universidade Estadual do Norte Fluminense Darcy Ribeiro - UENF                    |" << endl;
	cout << "|                      Laboratorio de Engenharia e Exploracao de Petroleo - LENEP                      |" << endl;
	cout << "|                                    Programacao Pratica - Projeto C++                                 |" << endl;
	cout << "|                                      Professor: Andre Duarte Bueno                                   |" << endl;
	cout << "|                                 Alunos: Gleison Monteiro e Luisa Campbell                            |" << endl;
	cout << "|                           SIMULADOR DE HIDRAULICA DE PERFURACAO DE POCO - SHPP                       |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	
	CFluido fluido;
	fluido.EntradaDadosFluido();

	CGeometriaPoco geomPoco;
	geomPoco.EntradaDadosGeometriaPoco();
	geomPoco.CalculoFases();

	CPerdaDeCarga perdaCarga;
	perdaCarga.EntradaDadosPerdaDeCarga();
	perdaCarga.CalculoVelocidadeTubulacao();
	perdaCarga.CalculoVelocidadeAnular(geomPoco);
	perdaCarga.CalculoReynoldsTubulacao(fluido);
	perdaCarga.CalculoReynoldsAnular(fluido, geomPoco);
	perdaCarga.CalculoPDCTubulacao(fluido, geomPoco);
	perdaCarga.CalculoPDCAnular(fluido, geomPoco);

	CResultados resultados;
	resultados.GradienteEmMetros(perdaCarga);
	resultados.VetoresProfundidade(geomPoco);
	resultados.VetoresPressao(perdaCarga, geomPoco);
	resultados.CalculoPerdaPressaoTotal(perdaCarga, geomPoco);
	resultados.MenuResultados(perdaCarga);
	
	
};
