/**
@autor Gleison Monteiro | Luisa Campbell
@file CResultados.cpp
@brief CResultados : ? uma classe que disponibiliza ao usuario diversas formas de plotar os resultados.
*/

#include "CResultados.h"  //Inclui o arquivo de cabecalho da classe CResultados.h

void CResultados::GradienteEmMetros(CPerdaDeCarga perdaCarga) {

	for (int i = 0; i < perdaCarga.gradientes.size(); i++){
		gradientesM.push_back(perdaCarga.gradientes[i] * 0.3048);
	}
	
}

void CResultados::VetoresProfundidade(CGeometriaPoco geometria){

	double incremento1, incremento2, incremento3, incremento4;
	incremento1 = geometria.compFases[0] / 100;
	incremento2 = geometria.compFases[1] / 100;
	incremento3 = geometria.compFases[2] / 100;
	incremento4 = geometria.compFases[3] / 100;

	//Preenchimento dos vetores de profundidade por fase
	for (int i = 1; i < 101; i++) {

		xFase1.push_back(i * incremento1);
		xFase2.push_back(i * incremento2);
		xFase3.push_back(i * incremento3);
		xFase4.push_back(i * incremento4);

	}


}

void CResultados::VetoresPressao(CPerdaDeCarga carga, CGeometriaPoco geometria){
	double temp;     
	double compDC = (geometria.profundidadeM)*0.05;  ///comprimento da secao de DC para as fases 2,3 e 4

	//Fase 1
	for (int i = 0; i < xFase1.size(); i++) {

			if (xFase1[i] <= 30) {
				temp = (gradientesM[1] + gradientesM[2])*xFase1[i];
				yFase1.push_back(temp);
				
		}
			else {
				temp = ((gradientesM[0]+gradientesM[3])*(xFase1[i]-30))+((gradientesM[1] + gradientesM[2])*30);
				yFase1.push_back(temp);
			}

		}

	
	// Fase 2

	for (int i = 0; i < xFase2.size(); i++){

		// Menor que DC: apenas tem DC no poco revestido
		if (xFase2[i] <= compDC) {
			temp = (gradientesM[1] + gradientesM[4])*xFase2[i];
			yFase2.push_back(temp);
		}

		// Maior do que DC: > DC e DP no poco revestido (< que fase 1)
		else if ((xFase2[i] >= compDC) && (xFase2[i] <= xFase1[(xFase1.size() - 1)])) {
			temp = (gradientesM[0] + gradientesM[6])*(xFase2[i] - compDC) + ((gradientesM[1] + gradientesM[4]) * compDC);
			yFase2.push_back(temp);
		}

		// Profundidade e  maior que a fase 1, porem menos que fase 1 e compDC: DC no poco aberto, DP no poco revestido 
		else if ((xFase2[i] >= xFase1[xFase1.size() - 1]) && (xFase2[i] <= (compDC + xFase1[xFase1.size() - 1]))){
			temp = ((gradientesM[0] + gradientesM[6]) * (xFase2[i] - compDC)) + ((gradientesM[1] + gradientesM[4]) * compDC);
			yFase2.push_back(temp);
		}

		// Profundidade e maior que a fase 1 e o comprimento do DC, comecando a ter DP no poco aberto
		else if ((xFase2[i] >= (compDC + xFase1[xFase1.size() - 1]))){
			temp = (gradientesM[0] + gradientesM[5]) * (xFase2[i] - compDC - xFase1[(xFase1.size() - 1)]) + (gradientesM[0] + gradientesM[6]) * (xFase1[xFase1.size() - 1]) + ((gradientesM[1] + gradientesM[4]) * compDC);
			yFase2.push_back(temp);
		}

	}

	//Fase 3

	for (int i = 0; i < xFase3.size(); i++){

		// Menor que DC: apenas tem DC no poco revestido
		if (xFase3[i] <= compDC) {
			temp = (gradientesM[1] + gradientesM[7])*xFase3[i];
			yFase3.push_back(temp);
		}

		// Maior do que DC: > DC e DP no poco revestido (< que fase 1)
		else if ((xFase3[i] >= compDC) && (xFase3[i] <= xFase2[(xFase2.size() - 1)])) {
			temp = (gradientesM[0] + gradientesM[9])*(xFase3[i] - compDC) + ((gradientesM[1] + gradientesM[7]) * compDC);
			yFase3.push_back(temp);
		}

		// Profundidade e  maior que a fase 1, porem menos que fase 1 e compDC: DC no poco aberto, DP no poco revestido 
		else if ((xFase3[i] >= xFase2[xFase2.size() - 1]) && (xFase3[i] <= (compDC + xFase2[xFase2.size() - 1]))){
			temp = ((gradientesM[0] + gradientesM[9]) * (xFase3[i] - compDC)) + ((gradientesM[1] + gradientesM[7]) * compDC);
			yFase3.push_back(temp);
		}

		// Profundidade e maior que a fase 1 e o comprimento do DC, comecando a ter DP no poco aberto
		else if ((xFase3[i] >= (compDC + xFase2[xFase2.size() - 1]))){
			temp = (gradientesM[0] + gradientesM[8]) * (xFase3[i] - compDC - xFase2[(xFase2.size() - 1)]) + (gradientesM[0] + gradientesM[9]) * (xFase2[xFase2.size() - 1]) + ((gradientesM[1] + gradientesM[7]) * compDC);
			yFase3.push_back(temp);
		}

	}



	//Fase 4

	for (int i = 0; i < xFase4.size(); i++){

		// Menor que DC: apenas tem DC no poco revestido
		if (xFase4[i] <= compDC) {
			temp = (gradientesM[1] + gradientesM[10])*xFase4[i];
			yFase4.push_back(temp);
		}

		// Maior do que DC: > DC e DP no poco revestido (< que fase 1)
		else if ((xFase4[i] >= compDC) && (xFase4[i] <= xFase3[(xFase3.size() - 1)])) {
			temp = (gradientesM[0] + gradientesM[12])*(xFase4[i] - compDC) + ((gradientesM[1] + gradientesM[10]) * compDC);
			yFase4.push_back(temp);
		}

		// Profundidade e  maior que a fase 1, porem menos que fase 1 e compDC: DC no poco aberto, DP no poco revestido 
		else if ((xFase4[i] >= xFase3[xFase3.size() - 1]) && (xFase4[i] <= (compDC + xFase3[xFase3.size() - 1]))){
			temp = ((gradientesM[0] + gradientesM[12]) * (xFase4[i] - compDC)) + ((gradientesM[1] + gradientesM[10]) * compDC);
			yFase4.push_back(temp);
		}

		// Profundidade e maior que a fase 1 e o comprimento do DC, comecando a ter DP no poco aberto
		else if ((xFase4[i] >= (compDC + xFase3[xFase3.size() - 1]))){
			temp = (gradientesM[0] + gradientesM[11]) * (xFase4[i] - compDC - xFase3[(xFase3.size() - 1)]) + (gradientesM[0] + gradientesM[12]) * (xFase3[xFase3.size() - 1]) + ((gradientesM[1] + gradientesM[10]) * compDC);
			yFase4.push_back(temp);
		}

	}






}

void CResultados::CalculoPerdaPressaoTotal (CPerdaDeCarga carga, CGeometriaPoco geometria){


	pMaxFase1 = yFase1[0];
	pMaxFase2 = yFase2[0];
	pMaxFase3 = yFase3[0];
	pMaxFase4 = yFase4[0];

	for (int i = 1; i < xFase1.size(); i++) {
		pMaxFase1 += yFase1[i];
		pMaxFase2 += yFase2[i];
		pMaxFase3 += yFase3[i];
		pMaxFase4 += yFase4[i];
	}




};

void CResultados::SaidaDeDados(vector<double> x, vector<double> y, string nomeDoArquivo){

	ofstream fout;
	fout.open(nomeDoArquivo.c_str());

	fout << "Profundidade (metros)	"  <<  "Queda de pressao (psi)" << endl;

		for (int i = 0; i < y.size(); i++){
		fout << x[i] << "		" << y[i] << endl;
		}
		
		fout.close();
		cout << "Os dados foram salvos no arquivo " << nomeDoArquivo << "." << endl;
        cout << " \n";

	}

void CResultados::MenuResultados(CPerdaDeCarga perdaCarga){

	bool flag = true;
	int escolha = 0;

    cout << "\n---------------------------------------------------------------------" << endl;
	cout << "     A perda de carga total da fase 1 foi " << pMaxFase1 << " psi." << endl;
	cout << "     A perda de carga total da fase 2 foi " << pMaxFase2 << " psi." << endl;
	cout << "     A perda de carga total da fase 3 foi " << pMaxFase3 << " psi." << endl;
	cout << "     A perda de carga total da fase 4 foi " << pMaxFase4 << " psi." << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	///Criando o objeto da classe Gnuplot e o configurando para as plotagens

	CGnuplot gnu;
	gnu.set_style("lines");
	gnu.set_title("Perda de Carga x Profundidade");
	gnu.set_xlabel("Profundidade (m)");
	gnu.set_ylabel("Perda de carga (psi)");
	

	///O loop apresenta ao usuario as opcoes de entrega de resultados dispon?veis pelo SHPP
	while (flag) {

		cout << "Este e um menu de escolha de como os dados serao salvos. Escolha a opcao desejada:" << endl;
        cout << " \n";
		cout << "Exportar dados de profundidade versus queda de pressao para um arquivo texto:" << endl;
        cout << "1 - Fase 1." << endl;
        cout << "2 - Fase 2." << endl;
        cout << "3 - Fase 3." << endl;
        cout << "4 - Fase 4." << endl;
        cout << "Plotar dados de profundidade versus queda de pressao utilizando o Gnuplot:" << endl;
        cout << "5 - Fase 1." << endl;
        cout << "6 - Fase 2." << endl;
        cout << "7 - Fase 3." << endl;
        cout << "8 - Fase 4." << endl;
		cout << "9 - Todas as fases." << endl;
		cout << "10 - Sair do programa." << endl;

		cin >> escolha;
		cin.get();

		switch (escolha) {

		case 1:
			SaidaDeDados(xFase1, yFase1, "ResultadosFase1.txt");
            cout << " \n";
			break;


		case 2:
			SaidaDeDados(xFase2, yFase2, "ResultadosFase2.txt");
            cout << " \n";
			break;


		case 3:
			SaidaDeDados(xFase3, yFase3, "ResultadosFase3.txt");
            cout << " \n";
			break;


		case 4:
			SaidaDeDados(xFase4, yFase4, "ResultadosFase4.txt");
            cout << " \n";
			break;


		case 5:
			PlotarDados(gnu, xFase1, yFase1);
            cout << " \n";
			break;


		case 6:
			PlotarDados(gnu, xFase2, yFase2);
            cout << " \n";
			break;


		case 7:
			PlotarDados(gnu, xFase3, yFase3);
            cout << " \n";
			break;


		case 8:
			PlotarDados(gnu, xFase4, yFase4);
            cout << " \n";
			break;


		case 9:
			PlotarDados(gnu, xFase1, yFase1, xFase2, yFase2, xFase3, yFase3,  xFase4, yFase4);
			cout << "Grafico comparativo de perda de carga entre as fases" << endl;
            cout << " \n";
			break;

			
		case 10:
			flag = false;
			break;

			//Entrada invalida do usuario
		default:
			cout << "Esta nao e uma opcao valida. Tente novamente" << endl;
            cout << " \n";

		}
		
	}



}

void CResultados::PlotarDados(CGnuplot& gnu, vector<double>& x, vector<double>& y){

string nomeDoArquivo;

gnu.PlotVector(x, y);

cout << "Qual o nome do arquivo em que voce deseja salvar seu grafico? " << endl;
getline(cin,nomeDoArquivo);

gnu.savetopng(nomeDoArquivo);

 cout << "O grafico foi salvo com o nome " + nomeDoArquivo + ".png." << endl;
 

 //gnu.replot();


}

void CResultados::PlotarDados(CGnuplot& gnu, vector<double>& x1, vector<double>& y1, vector<double>& x2, vector<double>& y2, vector<double>& x3, vector<double>& y3, vector<double>& x4, vector<double>& y4){

string nomeDoArquivo;

gnu.PlotVector(x1, y1);
gnu.PlotVector(x2, y2);
gnu.PlotVector(x3, y3);
gnu.PlotVector(x4, y4);

cout << "Qual o nome do arquivo em que voce deseja salvar seu grafico? " << endl;
getline(cin,nomeDoArquivo);

gnu.savetopng(nomeDoArquivo);

 cout << "O grafico foi salvo com o nome " + nomeDoArquivo + ".png." << endl;

 //gnu.replot();

}


