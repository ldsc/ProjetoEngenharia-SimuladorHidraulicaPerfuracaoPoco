/**
@autor Gleison Monteiro | Luisa Campbell
@file CPerdaDeCarga.cpp
@brief CPerdaDeCarga.cpp : Implementa os metodos da classe CPerdaDeCarga.h
*/

// Inclusao de classes e bibliotecas

#include "CPerdaDeCarga.h"   //Inclui o arquivo de cabecalho da classe CPerdaDeCarga.h

void CPerdaDeCarga::EntradaDadosPerdaDeCarga(){

	cout << "Entre com a vazao de bombeio do fluido de perfuracao (em galoes por minuto - gpm):" << endl;
	double _vazao;
	cin >> _vazao;
	cin.get();
	vazao = _vazao;
    cout << " \n";
	
	//Entrada dos valores de OD e ID das tubulacoes no vetor
	tubulacaoID.push_back(4.88);    
	tubulacaoID.push_back(2.81);
	tubulacaoOD.push_back(8.0);
	tubulacaoOD.push_back(5.5);

};

void CPerdaDeCarga::CalculoVelocidadeTubulacao(){
	double velocidade;
	velocidade = vazao / (2.448*tubulacaoID[0] * tubulacaoID[0]);
	velTub.push_back(velocidade);
	velocidade = vazao / (2.448*tubulacaoID[1] * tubulacaoID[1]);
	velTub.push_back(velocidade);

};

void CPerdaDeCarga::CalculoVelocidadeAnular(CGeometriaPoco& objPoco){
	double velocidade;
	vector<double> ajudaVelocidade;
	
	//Fase 1
	velocidade = vazao / (2.448 * ((objPoco.diamPoco[0])*(objPoco.diamPoco[0]) - tubulacaoOD[0] * tubulacaoOD[0])); //Poco aberto e DC;
	velAnularFase1.push_back(velocidade);
	velocidade = vazao / (2.448 * ((objPoco.diamPoco[0])*(objPoco.diamPoco[0]) - tubulacaoOD[1] * tubulacaoOD[1])); //Poco aberto e DP;
	velAnularFase1.push_back(velocidade);

	for (int i = 0; i < 3; i++){

		velocidade = vazao / (2.448 * ((objPoco.diamPoco[i + 1])*(objPoco.diamPoco[i + 1]) - tubulacaoOD[0]*tubulacaoOD[0])); //Poco aberto e DC;
		ajudaVelocidade.push_back(velocidade);
		velocidade = vazao / (2.448 * ((objPoco.diamPoco[i + 1])*(objPoco.diamPoco[i + 1]) - tubulacaoOD[1]*tubulacaoOD[1])); //Poco aberto e DP;
		ajudaVelocidade.push_back(velocidade);
		velocidade = vazao / (2.448 * ((objPoco.revesID[i])*(objPoco.revesID[i]) - tubulacaoOD[1]*tubulacaoOD[1])); //Poco revestido e DP;
		ajudaVelocidade.push_back(velocidade);

	}

        //Alimentando os vetores de velocidade anular por fases
	for (int j = 0; j < 3; j++){
		velAnularFase2.push_back(ajudaVelocidade[j]);
		velAnularFase3.push_back(ajudaVelocidade[3 + j]);
		velAnularFase4.push_back(ajudaVelocidade[6 + j]);
	}

};

void CPerdaDeCarga::CalculoReynoldsTubulacao(CFluido& objFluido){

	double reynolds;
	reynolds = (928 * objFluido.dens * velTub[0] * tubulacaoID[0]) / objFluido.visc;
	reyTub.push_back(reynolds);
	reynolds = (928 * objFluido.dens * velTub[1] * tubulacaoID[1]) / objFluido.visc;
	reyTub.push_back(reynolds);
};

void CPerdaDeCarga::CalculoReynoldsAnular(CFluido& objFluido, CGeometriaPoco& objPoco){

	double reynolds;

	//Fase 1
	reynolds = (757 * objFluido.dens * velAnularFase1[0] * (objPoco.diamPoco[0] - tubulacaoOD[0])) / objFluido.visc; //Poco aberto e DC;
	reyAnularFase1.push_back(reynolds);
	reynolds = (757 * objFluido.dens * velAnularFase1[1] * (objPoco.diamPoco[0] - tubulacaoOD[1])) / objFluido.visc;  //Poco aberto e DP;
	reyAnularFase1.push_back(reynolds);

	//Fase 2
	reynolds = (757 * objFluido.dens * velAnularFase2[0] * (objPoco.diamPoco[1] - tubulacaoOD[0])) / objFluido.visc; //Poco aberto e DC;
	reyAnularFase2.push_back(reynolds);
	reynolds = (757 * objFluido.dens * velAnularFase2[1] * (objPoco.diamPoco[1] - tubulacaoOD[1])) / objFluido.visc; //Poco aberto e DP;
	reyAnularFase2.push_back(reynolds);
	reynolds = (757 * objFluido.dens * velAnularFase2[2] * (objPoco.revesID[0] - tubulacaoOD[1])) / objFluido.visc; //Poco revestido e DP;
	reyAnularFase2.push_back(reynolds);

	//Fase 3
	reynolds = (757 * objFluido.dens * velAnularFase3[0] * (objPoco.diamPoco[2] - tubulacaoOD[0])) / objFluido.visc; // Poco aberto e DC;
	reyAnularFase3.push_back(reynolds);
	reynolds = (757 * objFluido.dens * velAnularFase3[1] * (objPoco.diamPoco[2] - tubulacaoOD[1])) / objFluido.visc; // Poco aberto e DP;
	reyAnularFase3.push_back(reynolds);
	reynolds = (757 * objFluido.dens * velAnularFase3[2] * (objPoco.revesID[1] - tubulacaoOD[1])) / objFluido.visc; // Poco revestido e DP;
	reyAnularFase3.push_back(reynolds);

	//Fase 4
	reynolds = (757 * objFluido.dens * velAnularFase4[0] * (objPoco.diamPoco[3] - tubulacaoOD[0])) / objFluido.visc; // Poco aberto e DC;
	reyAnularFase4.push_back(reynolds);
	reynolds = (757 * objFluido.dens * velAnularFase4[1] * (objPoco.diamPoco[3] - tubulacaoOD[1])) / objFluido.visc;// Poco aberto e DP;
	reyAnularFase4.push_back(reynolds);
	reynolds = (757 * objFluido.dens * velAnularFase4[2] * (objPoco.revesID[2] - tubulacaoOD[1])) / objFluido.visc; // Poco revestido e DP;
	reyAnularFase4.push_back(reynolds);

};

void CPerdaDeCarga::CalculoPDCTubulacao(CFluido& objFluido, CGeometriaPoco& objPoco) {
	double _gradiente;
	
	//Analisando a perda de carga no DP e DC
	
	for (int i = 0; i < 2; i++){
		if (reyTub[i] < 2100) {
			_gradiente = (objFluido.visc * velTub[i]) / (1500 * tubulacaoID[i] * tubulacaoID[i]);
			tiposDeEscoamento.push_back("Laminar");
		}
		else {
			_gradiente = pow(objFluido.dens, 0.75) * pow(objFluido.visc, 0.25) * pow(velTub[i], 1.75) / (1800 * pow(tubulacaoID[i], 1.25));
			tiposDeEscoamento.push_back("Turbulento");
		}

		gradientes.push_back(_gradiente);
			
	}
		
};


void CPerdaDeCarga::CalculoPDCAnular(CFluido& objFluido, CGeometriaPoco& objPoco) {
	double _gradiente;

	//FASE 1
		for (int i = 0; i < 2; i++) {

		if (reyAnularFase1[i] < 2100) {   
			_gradiente = (objFluido.visc * velAnularFase1[i]) / (1000 * pow((objPoco.diamPoco[0] - tubulacaoOD[i]), 2));    //DC e DP
			tiposDeEscoamento.push_back("Laminar");
		}
		else {                     
			_gradiente = pow(objFluido.dens, 0.75) * pow(objFluido.visc, 0.25) * pow(velAnularFase1[i], 1.75) / (1396 * pow((objPoco.diamPoco[0] - tubulacaoOD[i]), 1.25));    //DC e DP
			tiposDeEscoamento.push_back("Turbulento");
		}
		gradientes.push_back(_gradiente);   
		
	}

	//FASE 2

	//DP e DC
	for (int i = 0; i < 2; i++) {

		if (reyAnularFase2[i] < 2100) {
			_gradiente = (objFluido.visc * velAnularFase2[i]) / (1000 * pow((objPoco.diamPoco[1] - tubulacaoOD[i]), 2));    //DC i=0 e DP i=1
			tiposDeEscoamento.push_back("Laminar");
		}
		else {
			_gradiente = pow(objFluido.dens, 0.75) * pow(objFluido.visc, 0.25) * pow(velAnularFase2[i], 1.75) / (1396 * pow((objPoco.diamPoco[1] - tubulacaoOD[i]), 1.25));    //DC e DP
			tiposDeEscoamento.push_back("Turbulento");
		}
		gradientes.push_back(_gradiente);

	}

	// Revestimento DP

	if (reyAnularFase2[2] < 2100) {
		_gradiente = (objFluido.visc * velAnularFase2[2]) / (1000 * pow((objPoco.revesID[0] - tubulacaoOD[1]), 2));    //DC i=0 e DP i=1
		tiposDeEscoamento.push_back("Laminar");
		gradientes.push_back(_gradiente);
	}
	else {
		_gradiente = pow(objFluido.dens, 0.75) * pow(objFluido.visc, 0.25) * pow(velAnularFase2[2], 1.75) / (1396 * pow((objPoco.revesID[0] - tubulacaoOD[1]), 1.25));    //DC e DP
		tiposDeEscoamento.push_back("Turbulento");
		gradientes.push_back(_gradiente);
	}


	//CALCULOS FASE 3

	//DP e DC
	for (int i = 0; i < 2; i++) {

		if (reyAnularFase3[i] < 2100) {
			_gradiente = (objFluido.visc * velAnularFase3[i]) / (1000 * pow((objPoco.diamPoco[2] - tubulacaoOD[i]), 2));    //DC i=0 e DP i=1
			tiposDeEscoamento.push_back("Laminar");
		}
		else {
			_gradiente = pow(objFluido.dens, 0.75) * pow(objFluido.visc, 0.25) * pow(velAnularFase3[i], 1.75) / (1396 * pow((objPoco.diamPoco[2] - tubulacaoOD[i]), 1.25));    //DC e DP
			tiposDeEscoamento.push_back("Turbulento");
		}
		gradientes.push_back(_gradiente);

	}

	// Revestimento DP

	if (reyAnularFase3[2] < 2100) {
		_gradiente = (objFluido.visc * velAnularFase3[2]) / (1000 * pow((objPoco.revesID[1] - tubulacaoOD[1]), 2));    //DC i=0 e DP i=1
		tiposDeEscoamento.push_back("Laminar");
		gradientes.push_back(_gradiente);
	}
	else {
		_gradiente = pow(objFluido.dens, 0.75) * pow(objFluido.visc, 0.25) * pow(velAnularFase3[2], 1.75) / (1396 * pow((objPoco.revesID[1] - tubulacaoOD[1]), 1.25));    //DC e DP
		tiposDeEscoamento.push_back("Turbulento");
		gradientes.push_back(_gradiente);
	}

	//CALCULOS FASE 4

	//DP e DC
	for (int i = 0; i < 2; i++) {

		if (reyAnularFase4[i] < 2100) {
			_gradiente = (objFluido.visc * velAnularFase4[i]) / (1000 * pow((objPoco.diamPoco[3] - tubulacaoOD[i]), 2));    //DC i=0 e DP i=1
			tiposDeEscoamento.push_back("Laminar");
		}
		else {
			_gradiente = pow(objFluido.dens, 0.75) * pow(objFluido.visc, 0.25) * pow(velAnularFase4[i], 1.75) / (1396 * pow((objPoco.diamPoco[3] - tubulacaoOD[i]), 1.25));    //DC e DP
			tiposDeEscoamento.push_back("Turbulento");
		}
		gradientes.push_back(_gradiente);

	}
	
	// Revestimento DP

	if (reyAnularFase4[2] < 2100) {
		_gradiente = (objFluido.visc * velAnularFase4[2]) / (1000 * pow((objPoco.revesID[2] - tubulacaoOD[1]), 2));    //DC i=0 e DP i=1
		tiposDeEscoamento.push_back("Laminar");
		gradientes.push_back(_gradiente);
	}
	else {
		_gradiente = pow(objFluido.dens, 0.75) * pow(objFluido.visc, 0.25) * pow(velAnularFase4[2], 1.75) / (1396 * pow((objPoco.revesID[2] - tubulacaoOD[1]), 1.25));    //DC e DP
		tiposDeEscoamento.push_back("Turbulento");
		gradientes.push_back(_gradiente);
	}
};
