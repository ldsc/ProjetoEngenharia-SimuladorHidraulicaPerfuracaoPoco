/**
@autor Gleison Monteiro | Luisa Campbell
@file CFluido.h
@brief CFluido : E uma classe que representa o fluido usado na perfuracao do poço.
*/

#ifndef CFluido_H
#define CFluido_H

//Inclusao de classes das bibliotecas basicas
#include <string>
#include <iostream>

using namespace std;

class CFluido {

public:
	//ATRIBUTOS
	double visc = 25; /// Viscosidade do fluido. OBS: Fluido polimerico
	double dens = 10; /// Densidade do fluido. OBS: Fluido polimerico

	//METODOS
	CFluido(){} // Construtor Default
	virtual ~CFluido(){} // Destrutor Default
	void EntradaDadosFluido();  /// Metodo que permite a entrada de dados do fluido pelo usuario

};

#endif
