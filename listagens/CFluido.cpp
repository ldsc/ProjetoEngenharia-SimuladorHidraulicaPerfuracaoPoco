/**
@autor Gleison Monteiro | Luisa Campbell
@file CFluido.cpp
@brief CFluido.cpp : Implementa os metodos da classe CFluido.h
*/

// Inclusao de classes e bibliotecas

#include "CFluido.h"   //Inclui o arquivo de cabecalho da classe CFluido

void CFluido::EntradaDadosFluido(){        

	bool flag = false;

	cout << "\n  Os valores padrao do fluido de perfuracao polimerico sao: viscosidade = 25cp (centipoise) e densidade = 10ppg (ponds per gallon, ou libras por galoes).\n Deseja alterar as propriedades do fluido?\n Se sim, digite 's'; se nao, digite 'n'." << endl;
	string resposta;
	///O loop ira garantir a entrada de uma opcao valida pelo usuario
	while (!flag){

		cin >> resposta;
		cin.get();

		if (resposta == "s"){     ///Nesta opcao, o usuario ira entrar manualmente com os valores de densidade e viscosidade do fluido
			double nVisc, nDens;
			cout << "\t Entre o novo valor da viscosidade (em cp):" << endl;
			cin >> nVisc;
			cin.get();
			visc = nVisc;
            cout << " \n";
			cout << "\t Entre o novo valor da densidade (em ppg):" << endl;
			cin >> nDens;
			cin.get();
			dens = nDens;
            cout << " \n";
			flag = true;
		}
		else if (resposta == "n"){   ///Nesta opcao, o usuario escolhe manter os valores de densidade e viscosidade do fluido sugeridos
			cout << "Os dados serao mantidos." << endl;
            cout << " \n";
			flag = true;
		}
		else{           ///Esta opcao ira detectar erros de possiveis entradas do usuario
			cout << "Voce nao entrou um valor valido.\n Tente novamente.\n " << endl;
		}

	}
};
