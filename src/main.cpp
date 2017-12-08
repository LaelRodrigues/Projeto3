/** 
 * @file	main.h
 * @brief	Implementacao da classe Menu para representar
 *			um menu do PetFera
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	08/12/2017
 * @date 	08/12/2017
 */	

#include "petfera.h"
#include "menu.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <memory>
using std::shared_ptr;
using std::make_shared;

int main () {

	PetFera::Menu menu;
	int opcao;
	while(true) {
		cout << endl << "----------Pet Fera----------" << endl;
		cout << "(1) Cadastrar animal" << endl;
		cout << "(2) Comercializar animal" << endl;
		cout << "(3) Aterar os dados do animal" << endl;
		cout << "(4) Consultar os dados de um animal" << endl;
		cout << "(5) Consultar os dados de uma classe de animais" << endl;
		cout << "(6) Consultar os dados dos animais de um funcionario" << endl;
		cout << "(7) Cadastrar funcionario" << endl;
		cout << "(8) Remover funcionario" << endl;
		cout << "(9) Aterar os dados do funcionario" << endl;
		cout << "(0) Sair" << endl;
		cout << "opcao: ";
		cin >> opcao;	
		switch(opcao) {
			case 1:
				menu.cadastroAnimal();
				break;
			case 2:
				menu.excluirAnimal();
				break;
			case 3:
				menu.alterarAnimal();
				break;
			case 4:
				menu.acessar_um_animal();
				break;
			case 5:
				menu.acessar_por_classe();
				break;
			case 6:
				menu.acessar_por_funcionario();
				break;
			case 7:
				menu.cadastroFuncionario();
				break;
			case 8:
				menu.excluirFuncionario();
				break;
			case 9:
				menu.alterarFuncionario();
				break;
			case 0:
				cout << "Programa finalizado." << endl;
				return 0;
			default:
				cout << "Valor invalido." << endl;
				break;
		}

	}
	
	return 0;
}
