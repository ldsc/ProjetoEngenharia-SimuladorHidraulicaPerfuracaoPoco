/**
@autor Gleison Monteiro | Luisa Campbell
@file main.cpp
@brief Essa fun��o � respons�vel por executar o programa
*/

#include "CFluido.h"
#include "CGeometriaPoco.h"
#include "CPerdaDeCarga.h"
#include "CResultados.h"
#include "CSHPP.h"


int main(int argc, char** argv)
{
 
	CSHPP programa;
	programa.Simulacao();
	
	
	return 0;
}


