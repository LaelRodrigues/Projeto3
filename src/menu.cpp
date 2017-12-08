/** 
 * @file	menu.cpp
 * @brief	Implementacao da classe Menu para representar
 *			um menu do PetFera
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	07/12/2017
 * @date 	08/12/2017
 */	


#include "menu.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <string>
using std::getline;

#include <typeinfo>

#include <map>
using std::pair;


namespace PetFera {
	
	// Construtor padrao 
	Menu::Menu() {}

	// Destrutor padrao
	Menu::~Menu() {}


	// Metodo para cadastra um funcionario
	void Menu::cadastroFuncionario() {
		int id, idade;
		string nome, funcao, cpf, tipo_sanguineo, especialidade;
		char fator_RH;
		shared_ptr<Funcionario> func;
		map<int, shared_ptr<Funcionario>>::iterator it; 

		cout << "Digite o identificador: ";
		cin >> id;
		cout << "Digite o nome: ";
		cin.ignore();
		getline(cin, nome);
		cout << "Digite a funcao(Tratador ou Veterinario): ";
		getline(cin, funcao);
		cout << "Digite o CPF: ";
		getline(cin, cpf);
		cout << "Digite a idade: ";
		cin >> idade;
		cout << "Digite o tipo sanguineo: ";
		cin.ignore();
		getline(cin, tipo_sanguineo);
		cout << "Digite o fator Rh: ";
		cin >> fator_RH;
		cout << "Digite a especialidade: ";
		cin.ignore();
		getline(cin, especialidade);
		if(id <= 0) {
			cout << endl << "Identificador invalido." << endl;
			cout << "O valor do identificador deve ser maior que 0." << endl;
			return;
		}
		if(funcao == "Tratador") {
			func = make_shared<Tratador>(id, nome, funcao, cpf, idade, tipo_sanguineo, fator_RH, especialidade);
			it = lista_funcionarios.find(id);
			if(it != lista_funcionarios.end()) {
				cout << endl << "Erro no cadastramento." << endl;
				cout << "O Funcionario ja foi cadastrado." << endl << endl;
				return;
			}
			lista_funcionarios[id] = func;
			cout << endl << "-----Funcionario cadastrado-----" << endl << endl;
			return;
		}
		else if(funcao == "Veterinario") {
			func = make_shared<Veterinario>(id, nome, funcao, cpf, idade, tipo_sanguineo, fator_RH, especialidade);
			it = lista_funcionarios.find(id);
			if(it != lista_funcionarios.end()) {
				cout << endl << "Erro no cadastramento." << endl;
				cout << "O Funcionario ja foi cadastrado." << endl << endl;
				return;
			}
			lista_funcionarios[id] = func;
			cout << endl << "-----Funcionario cadastrado-----" << endl << endl;
		}
		else {
			cout << endl << "Erro no cadastramento " << endl;
			cout << "A funcao do funcionario e invalida." << endl << endl;
			return;
		}
	}

	// Metodo para remover um funcionario
	void Menu::excluirFuncionario() {
		int id;
		map<int, shared_ptr<Funcionario>>::iterator it; 

		cout << "Digite o identificador ";
		cin >> id;
		it = lista_funcionarios.find(id);
		if(it != lista_funcionarios.end()) {
			lista_funcionarios.erase(it);
			cout << endl << "Funcionario removido com sucesso." << endl << endl;
			return;
		}
		cout << endl << "Erro na remocao." << endl;
		cout << "Funcionario Inexistente." << endl << endl;
	}

	void Menu::alterarFuncionario() {
		int id;
		map<int, shared_ptr<Funcionario>>::iterator it; 

		cout << "Digite o identificador ";
		cin >> id;
		it = lista_funcionarios.find(id);
		if(it != lista_funcionarios.end()) {
			shared_ptr<Funcionario> f = it->second;
			int novo_id, idade;
			string nome, funcao, cpf, tipo_sanguineo, especialidade;
			char fator_RH;
			cout << "Digite o novo identificador: ";
			cin >> novo_id;
			cout << "Digite o nome: ";
			cin.ignore();
			getline(cin, nome);
			cout << "Digite a funcao(Tratador ou Veterinario): ";
			getline(cin, funcao);
			cout << "Digite o CPF: ";
			getline(cin, cpf);
			cout << "Digite a idade: ";
			cin >> idade;
			cout << "Digite o tipo sanguineo: ";
			cin.ignore();
			getline(cin, tipo_sanguineo);
			cout << "Digite o fator Rh: ";
			cin >> fator_RH;
			cout << "Digite a especialidade: ";
			cin.ignore();
			getline(cin, especialidade);
			it = lista_funcionarios.find(novo_id);
			if(novo_id <= 0) {
				cout << endl << "Identificador invalido." << endl;
				cout << "O valor do identificador deve ser maior que 0." << endl;
				return;
			}
			if(it != lista_funcionarios.end()) {
				cout << endl << "Erro na alteracao." << endl;
				cout << "O Funcionario ja foi cadastrado." << endl << endl;
				return;
			}
			if(funcao != "Tratador" && funcao != "Veterinario") {
				cout << endl << "Erro no cadastramento " << endl;
				cout << "A funcao do funcionario e invalida." << endl << endl;
				return;
			}
			f->setId(novo_id);
			f->setNome(nome);
			f->setFuncao(funcao);
			f->setCpf(cpf);
			f->setIdade(idade);
			f->setFatorRH(fator_RH);
			f->setTipo_sanguineo(tipo_sanguineo);
			f->setEspecialidade(especialidade);
		}
	}
	void Menu::cadastroAnimal() {
		int id, idvet, idtrat;
		string classe, nome, cientifico, dieta, batismo, tipo;
		float tamanho;
		char sexo;
		shared_ptr<Animal> animal;
		shared_ptr<Tratador> trat = make_shared<Tratador>();
		shared_ptr<Veterinario> vet = make_shared<Veterinario>();

		map<int, shared_ptr<Animal>>::iterator it1;
		map<int, shared_ptr<Funcionario>>::iterator it2;
		map<int, shared_ptr<Funcionario>>::iterator it3; 


		cout << "Digite o identificador: ";
		cin >> id;
		cout << "Digite a classe(Amphibia, Mammalia, Reptilia ou Aves): ";
		cin.ignore();
		getline(cin, classe);
		cout << "Digite o nome: ";
		getline(cin, nome);
		cout << "Digite o nome cientifico: ";
		getline(cin, cientifico);
		cout << "Digite o sexo: ";
		cin >> sexo;
		cout << "Digite o tamanho: ";
		cin >> tamanho;
		cout << "Digite a dieta: ";
		cin.ignore();
		getline(cin, dieta);
		cout << "Digite o identificador do Veterinario(digite 0 caso nao exista): ";
		cin >> idvet;
		cout << "Digite o identificador do Tratador(digite 0 caso nao exista): ";
		cin >> idtrat;
		cout << "Digite o nome de batismo: ";
		cin.ignore();
		getline(cin, batismo);
		cout << "Digite a classificacao do animal se e Nativo, Exotico ou Domestico: ";
		getline(cin, tipo);
		if(id <= 0) {
			cout << endl << "Identificador invalido." << endl;
			cout << "O valor do identificador deve ser maior que 0." << endl;
			return;
		}

		it1 = lista_animais.find(id);
		if(it1 != lista_animais.end()) {
			cout << endl << "Erro no cadastramento." << endl;
			cout << "O Animal ja foi cadastrado." << endl << endl;
			return;
		}

		if(idvet < 0) {
			cout << endl << "Erro no cadastramento." << endl;
			cout << "Identificador do Veterinario e invalido." << endl << endl;
			return;
		}

		if(idtrat < 0) {
			cout << endl << "Erro no cadastramento." << endl;
			cout << "Identificador do Tratador e invalido." << endl << endl;
			return;
		}

		vet->setId(0);
		trat->setId(0);

		if(classe == "Amphibia") {
			int total_mudas;
			string ultima_muda;
			cout << "Digite o total de mudas: ";
			cin >> total_mudas;
			cout << "Digite a ultima muda: ";
			cin >> ultima_muda;
			if(tipo == "Nativo") {
				string ibama, uf_origem, autorizacao;
				cout << "Digite o identificador do ibama: ";
				cin >> ibama;
				cout << "Digite a uf de origem: ";
				cin >> uf_origem;
				cout << "Digite a autorizacao: ";
				cin >> autorizacao;
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<AnfibioNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda, ibama, uf_origem, autorizacao);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						shared_ptr<AnfibioNativo> animal = make_shared<AnfibioNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<AnfibioNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<AnfibioNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
				}
			}
			else if(tipo == "Exotico") {
				string ibama, pais_origem;
				cout << "Digite o identificador do ibama: ";
				cin >> ibama;
				cout << "Digite o pais de origem: ";
				cin >> pais_origem;
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<AnfibioExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda, ibama, pais_origem);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<AnfibioExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<AnfibioExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<AnfibioExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					return;
				}
			}
			else if(tipo == "Domestico") {
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<Anfibio>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<Anfibio>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<Anfibio>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<Anfibio>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, total_mudas, ultima_muda);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					return;
				}
			}
			else {
				cout << endl << "Erro, classificacao do animal e invalida." << endl << endl;
				return;
			}
		}
		else if(classe == "Mammalia") {
			string cor_pelo;
			cout << "Digite a cor do pelo: ";
			cin >> cor_pelo;
			if(tipo == "Nativo") {
				string ibama, uf_origem, autorizacao;
				cout << "Digite o identificador do ibama: ";
				cin >> ibama;
				cout << "Digite a uf de origem: ";
				cin >> uf_origem;
				cout << "Digite a autorizacao: ";
				cin >> autorizacao;
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<MamiferoNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo, ibama, uf_origem, autorizacao);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<MamiferoNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<MamiferoNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<MamiferoNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
				}
			}
			else if(tipo == "Exotico") {
				string ibama, pais_origem;
				cout << "Digite o identificador do ibama: ";
				cin >> ibama;
				cout << "Digite o pais de origem: ";
				cin >> pais_origem;
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<MamiferoExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo, ibama, pais_origem);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<MamiferoExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<MamiferoExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<MamiferoExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					return;
				}
			}
			else if(tipo == "Domestico") {
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<Mamifero>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<Mamifero>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<Mamifero>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<Mamifero>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, cor_pelo);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					return;
				}
			}
			else {
				cout << endl << "Erro, classificacao do animal e invalida." << endl << endl;
				return;
			}
			
		}
		else if(classe == "Reptilia") {
			bool venenoso;
			string tipo_veneno;
			cout << "Digite (1) se for venenoso ou (0) caso contrario: ";
			cin >> venenoso;
			cout << "Digite o tipo de veneno: ";
			cin >> tipo_veneno;
			if(tipo == "Nativo") {
				string ibama, uf_origem, autorizacao;
				cout << "Digite o identificador do ibama: ";
				cin >> ibama;
				cout << "Digite a uf de origem: ";
				cin >> uf_origem;
				cout << "Digite a autorizacao: ";
				cin >> autorizacao;
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<ReptilNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno, ibama, uf_origem, autorizacao);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<ReptilNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<ReptilNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<ReptilNativo>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					return;
				}
			}
			else if(tipo == "Exotico") {
				string ibama, pais_origem;
				cout << "Digite o identificador do ibama: ";
				cin >> ibama;
				cout << "Digite o pais de origem: ";
				cin >> pais_origem;
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<ReptilExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno, ibama, pais_origem);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<ReptilExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<ReptilExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<ReptilExotico>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					return;
				}
			}
			else if(tipo == "Domestico") {
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<Reptil>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<Reptil>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<Reptil>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<Reptil>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, venenoso, tipo_veneno);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					return;
				}
			}
			else {
				cout << endl << "Erro, classificacao do animal e invalida." << endl << endl;
				return;
			}
		}
		else if(classe == "Aves"){
			float tamanho_bico, envergadura;
			cout << "Digite o tamanho do bico: ";
			cin >> tamanho_bico;
			cout << "Digite envergadura: ";
			cin >> envergadura;
			if(tipo == "Nativo") {
				string ibama, uf_origem, autorizacao;
				cout << "Digite o identificador do ibama: ";
				cin >> ibama;
				cout << "Digite a uf de origem: ";
				cin >> uf_origem;
				cout << "Digite a autorizacao: ";
				cin >> autorizacao;
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<AveNativa>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura, ibama, uf_origem, autorizacao);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<AveNativa>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<AveNativa>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<AveNativa>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura, ibama, uf_origem, autorizacao);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
				}
			}
			else if(tipo == "Exotico") {
				string ibama, pais_origem;
				cout << "Digite o identificador do ibama: ";
				cin >> ibama;
				cout << "Digite o pais de origem: ";
				cin >> pais_origem;
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<AveExotica>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura, ibama, pais_origem);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<AveExotica>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<AveExotica>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<AveExotica>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura, ibama, pais_origem);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					return;
				}
			}
			else if(tipo == "Domestico") {
				if(idvet == 0 && idtrat == 0 ) { 
					animal = make_shared<Ave>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura);
					lista_animais[id] = animal;
					cout << endl << "-----Animal cadastrado-----" << endl << endl;
					return;
				}
				else if(idvet > 0 && idtrat == 0) {
					it2 = lista_funcionarios.find(idvet);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						animal = make_shared<Ave>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
					return;
				}
				else if(idvet == 0 && idtrat > 0) {
					it2 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
						animal = make_shared<Ave>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, tratador nao encontrado." << endl << endl;
					return;
				}
				else {
					it2 = lista_funcionarios.find(idvet);
					it3 = lista_funcionarios.find(idtrat);
					if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
						vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
						trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
						animal = make_shared<Ave>(id, classe, nome, cientifico, sexo, tamanho, dieta, (*vet), (*trat), batismo, tamanho_bico, envergadura);
						lista_animais[id] = animal;
						cout << endl << "-----Animal cadastrado-----" << endl << endl;
						return;
					}
					cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					return;
				}
			}
			else {
				cout << endl << "Erro, classificacao do animal e invalida." << endl << endl;
				return;
			}
		}
		else {
			return;
		}
	}
	void Menu::excluirAnimal() {

		int id;
		map<int, shared_ptr<Animal>>::iterator it; 

		cout << "Digite o identificador ";
		cin >> id;
		it = lista_animais.find(id);
		if(it != lista_animais.end()) {
			lista_animais.erase(it);
			cout << endl << "Animal comercializado com sucesso." << endl << endl;
			return;
		}
		cout << endl << "Erro na comercializacao." << endl;
		cout << "Animal Inexistente." << endl << endl;	
	}

	void Menu::alterarAnimal() {

		int id_atual;
		map<int, shared_ptr<Animal>>::iterator it; 

		cout << "Digite o identificador ";
		cin >> id_atual;
		it = lista_animais.find(id_atual);
		if(it != lista_animais.end()) {
			shared_ptr<Animal> animal = it->second;

			int id, idvet, idtrat;
			string classe, nome, cientifico, dieta, batismo, tipo;
			float tamanho;
			char sexo;
			shared_ptr<Tratador> trat = make_shared<Tratador>();
			shared_ptr<Veterinario> vet = make_shared<Veterinario>();

			map<int, shared_ptr<Animal>>::iterator it1;
			map<int, shared_ptr<Funcionario>>::iterator it2;
			map<int, shared_ptr<Funcionario>>::iterator it3; 

			cout << "Digite o novo identificador: ";
			cin >> id;
			cout << "Digite a classe(Amphibia, Mammalia, Reptilia ou Aves): ";
			cin.ignore();
			getline(cin, classe);
			cout << "Digite o nome: ";
			getline(cin, nome);
			cout << "Digite o nome cientifico: ";
			getline(cin, cientifico);
			cout << "Digite o sexo: ";
			cin >> sexo;
			cout << "Digite o tamanho: ";
			cin >> tamanho;
			cout << "Digite a dieta: ";
			cin.ignore();
			getline(cin, dieta);
			cout << "Digite o identificador do Veterinario(digite 0 caso nao exista): ";
			cin >> idvet;
			cout << "Digite o identificador do Tratador(digite 0 caso nao exista): ";
			cin >> idtrat;
			cout << "Digite o nome de batismo: ";
			cin.ignore();
			getline(cin, batismo);
			cout << "Digite a classificacao do animal se e Nativo, Exotico ou Domestico: ";
			getline(cin, tipo);
			if(id <= 0) {
				cout << endl << "Identificador invalido." << endl;
				cout << "O valor do identificador deve ser maior que 0." << endl;
				return;
			}
			if(idvet < 0) {
				cout << endl << "Erro na alteracao." << endl;
				cout << "Identificador do Veterinario e invalido." << endl << endl;
				return;
			}

			if(idtrat < 0) {
				cout << endl << "Erro na alteracao." << endl;
				cout << "Identificador do Tratador e invalido." << endl << endl;
				return;
			}
			vet->setId(0);
			trat->setId(0);
			if(classe == "Amphibia") {
				int total_mudas;
				string ultima_muda;
				cout << "Digite o total de mudas: ";
				cin >> total_mudas;
				cout << "Digite a ultima muda: ";
				cin >> ultima_muda;
				if(tipo == "Nativo") {
					string ibama, uf_origem, autorizacao;
					cout << "Digite o identificador do ibama: ";
					cin >> ibama;
					cout << "Digite a uf de origem: ";
					cin >> uf_origem;
					cout << "Digite a autorizacao: ";
					cin >> autorizacao;
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<AnfibioNativo> a = std::dynamic_pointer_cast<AnfibioNativo>(animal);
						a->setId(id);
						a->setClasse(classe);
						a->setNome(nome);
						a->setCientifico(cientifico);
						a->setSexo(sexo);
						a->setTamanho(tamanho);
						a->setDieta(dieta);
						a->setVeterinario((*vet));
						a->setTratador((*trat));
						a->setBatismo(batismo);
						a->setTotal_mudas(total_mudas);
						a->setUltima_muda(ultima_muda);
						a->setIbama(ibama);
						a->setUf_origem(uf_origem);
						a->setAutorizacao(autorizacao);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<AnfibioNativo> a = std::dynamic_pointer_cast<AnfibioNativo>(animal);
							a->setId(id);
							a->setClasse(classe);
							a->setNome(nome);
							a->setCientifico(cientifico);
							a->setSexo(sexo);
							a->setTamanho(tamanho);
							a->setDieta(dieta);
							a->setVeterinario((*vet));
							a->setTratador((*trat));
							a->setBatismo(batismo);
							a->setTotal_mudas(total_mudas);
							a->setUltima_muda(ultima_muda);
							a->setIbama(ibama);
							a->setUf_origem(uf_origem);
							a->setAutorizacao(autorizacao);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<AnfibioNativo> a = std::dynamic_pointer_cast<AnfibioNativo>(animal);
							a->setId(id);
							a->setClasse(classe);
							a->setNome(nome);
							a->setCientifico(cientifico);
							a->setSexo(sexo);
							a->setTamanho(tamanho);
							a->setDieta(dieta);
							a->setVeterinario((*vet));
							a->setTratador((*trat));
							a->setBatismo(batismo);
							a->setTotal_mudas(total_mudas);
							a->setUltima_muda(ultima_muda);
							a->setIbama(ibama);
							a->setUf_origem(uf_origem);
							a->setAutorizacao(autorizacao);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<AnfibioNativo> a = std::dynamic_pointer_cast<AnfibioNativo>(animal);
							a->setId(id);
							a->setClasse(classe);
							a->setNome(nome);
							a->setCientifico(cientifico);
							a->setSexo(sexo);
							a->setTamanho(tamanho);
							a->setDieta(dieta);
							a->setVeterinario((*vet));
							a->setTratador((*trat));
							a->setBatismo(batismo);
							a->setTotal_mudas(total_mudas);
							a->setUltima_muda(ultima_muda);
							a->setIbama(ibama);
							a->setUf_origem(uf_origem);
							a->setAutorizacao(autorizacao);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					}
				}
				else if(tipo == "Exotico") {
					string ibama, pais_origem;
					cout << "Digite o identificador do ibama: ";
					cin >> ibama;
					cout << "Digite o pais de origem: ";
					cin >> pais_origem;
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<AnfibioExotico> a = std::dynamic_pointer_cast<AnfibioExotico>(animal);
						a->setId(id);
						a->setClasse(classe);
						a->setNome(nome);
						a->setCientifico(cientifico);
						a->setSexo(sexo);
						a->setTamanho(tamanho);
						a->setDieta(dieta);
						a->setVeterinario((*vet));
						a->setTratador((*trat));
						a->setBatismo(batismo);
						a->setTotal_mudas(total_mudas);
						a->setUltima_muda(ultima_muda);
						a->setIbama(ibama);
						a->setPais_origem(pais_origem);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<AnfibioExotico> a = std::dynamic_pointer_cast<AnfibioExotico>(animal);
							a->setId(id);
							a->setClasse(classe);
							a->setNome(nome);
							a->setCientifico(cientifico);
							a->setSexo(sexo);
							a->setTamanho(tamanho);
							a->setDieta(dieta);
							a->setVeterinario((*vet));
							a->setTratador((*trat));
							a->setBatismo(batismo);
							a->setTotal_mudas(total_mudas);
							a->setUltima_muda(ultima_muda);
							a->setIbama(ibama);
							a->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<AnfibioExotico> a = std::dynamic_pointer_cast<AnfibioExotico>(animal);
							a->setId(id);
							a->setClasse(classe);
							a->setNome(nome);
							a->setCientifico(cientifico);
							a->setSexo(sexo);
							a->setTamanho(tamanho);
							a->setDieta(dieta);
							a->setVeterinario((*vet));
							a->setTratador((*trat));
							a->setBatismo(batismo);
							a->setTotal_mudas(total_mudas);
							a->setUltima_muda(ultima_muda);
							a->setIbama(ibama);
							a->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<AnfibioExotico> a = std::dynamic_pointer_cast<AnfibioExotico>(animal);
							a->setId(id);
							a->setClasse(classe);
							a->setNome(nome);
							a->setCientifico(cientifico);
							a->setSexo(sexo);
							a->setTamanho(tamanho);
							a->setDieta(dieta);
							a->setVeterinario((*vet));
							a->setTratador((*trat));
							a->setBatismo(batismo);
							a->setTotal_mudas(total_mudas);
							a->setUltima_muda(ultima_muda);
							a->setIbama(ibama);
							a->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
						return;
					}
				}
				else if(tipo == "Domestico") {
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<Anfibio> a = std::dynamic_pointer_cast<Anfibio>(animal);
						a->setId(id);
						a->setClasse(classe);
						a->setNome(nome);
						a->setCientifico(cientifico);
						a->setSexo(sexo);
						a->setTamanho(tamanho);
						a->setDieta(dieta);
						a->setVeterinario((*vet));
						a->setTratador((*trat));
						a->setBatismo(batismo);
						a->setTotal_mudas(total_mudas);
						a->setUltima_muda(ultima_muda);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<Anfibio> a = std::dynamic_pointer_cast<Anfibio>(animal);
							a->setId(id);
							a->setClasse(classe);
							a->setNome(nome);
							a->setCientifico(cientifico);
							a->setSexo(sexo);
							a->setTamanho(tamanho);
							a->setDieta(dieta);
							a->setVeterinario((*vet));
							a->setTratador((*trat));
							a->setBatismo(batismo);
							a->setTotal_mudas(total_mudas);
							a->setUltima_muda(ultima_muda);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<Anfibio> a = std::dynamic_pointer_cast<Anfibio>(animal);
							a->setId(id);
							a->setClasse(classe);
							a->setNome(nome);
							a->setCientifico(cientifico);
							a->setSexo(sexo);
							a->setTamanho(tamanho);
							a->setDieta(dieta);
							a->setVeterinario((*vet));
							a->setTratador((*trat));
							a->setBatismo(batismo);
							a->setTotal_mudas(total_mudas);
							a->setUltima_muda(ultima_muda);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<Anfibio> a = std::dynamic_pointer_cast<Anfibio>(animal);
							a->setId(id);
							a->setClasse(classe);
							a->setNome(nome);
							a->setCientifico(cientifico);
							a->setSexo(sexo);
							a->setTamanho(tamanho);
							a->setDieta(dieta);
							a->setVeterinario((*vet));
							a->setTratador((*trat));
							a->setBatismo(batismo);
							a->setTotal_mudas(total_mudas);
							a->setUltima_muda(ultima_muda);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
						return;
					}
				}
				else {
					cout << endl << "Erro, classificacao do animal e invalida." << endl << endl;
					return;
				}
			}
			else if(classe == "Mammalia") {
				string cor_pelo;
				cout << "Digite a cor do pelo: ";
				cin >> cor_pelo;
				if(tipo == "Nativo") {
					string ibama, uf_origem, autorizacao;
					cout << "Digite o identificador do ibama: ";
					cin >> ibama;
					cout << "Digite a uf de origem: ";
					cin >> uf_origem;
					cout << "Digite a autorizacao: ";
					cin >> autorizacao;
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<MamiferoNativo> m = std::dynamic_pointer_cast<MamiferoNativo>(animal);
						m->setId(id);
						m->setClasse(classe);
						m->setNome(nome);
						m->setCientifico(cientifico);
						m->setSexo(sexo);
						m->setTamanho(tamanho);
						m->setDieta(dieta);
						m->setVeterinario((*vet));
						m->setTratador((*trat));
						m->setBatismo(batismo);
						m->setCor_pelo(cor_pelo);
						m->setIbama(ibama);
						m->setUf_origem(uf_origem);
						m->setAutorizacao(autorizacao);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<MamiferoNativo> m = std::dynamic_pointer_cast<MamiferoNativo>(animal);
							m->setId(id);
							m->setClasse(classe);
							m->setNome(nome);
							m->setCientifico(cientifico);
							m->setSexo(sexo);
							m->setTamanho(tamanho);
							m->setDieta(dieta);
							m->setVeterinario((*vet));
							m->setTratador((*trat));
							m->setBatismo(batismo);
							m->setCor_pelo(cor_pelo);
							m->setIbama(ibama);
							m->setUf_origem(uf_origem);
							m->setAutorizacao(autorizacao);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<MamiferoNativo> m = std::dynamic_pointer_cast<MamiferoNativo>(animal);
							m->setId(id);
							m->setClasse(classe);
							m->setNome(nome);
							m->setCientifico(cientifico);
							m->setSexo(sexo);
							m->setTamanho(tamanho);
							m->setDieta(dieta);
							m->setVeterinario((*vet));
							m->setTratador((*trat));
							m->setBatismo(batismo);
							m->setCor_pelo(cor_pelo);
							m->setIbama(ibama);
							m->setUf_origem(uf_origem);
							m->setAutorizacao(autorizacao);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<MamiferoNativo> m = std::dynamic_pointer_cast<MamiferoNativo>(animal);
							m->setId(id);
							m->setClasse(classe);
							m->setNome(nome);
							m->setCientifico(cientifico);
							m->setSexo(sexo);
							m->setTamanho(tamanho);
							m->setDieta(dieta);
							m->setVeterinario((*vet));
							m->setTratador((*trat));
							m->setBatismo(batismo);
							m->setCor_pelo(cor_pelo);
							m->setIbama(ibama);
							m->setUf_origem(uf_origem);
							m->setAutorizacao(autorizacao);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					}
				}
				else if(tipo == "Exotico") {
					string ibama, pais_origem;
					cout << "Digite o identificador do ibama: ";
					cin >> ibama;
					cout << "Digite o pais de origem: ";
					cin >> pais_origem;
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<MamiferoExotico> m = std::dynamic_pointer_cast<MamiferoExotico>(animal);
						m->setId(id);
						m->setClasse(classe);
						m->setNome(nome);
						m->setCientifico(cientifico);
						m->setSexo(sexo);
						m->setTamanho(tamanho);
						m->setDieta(dieta);
						m->setVeterinario((*vet));
						m->setTratador((*trat));
						m->setBatismo(batismo);
						m->setCor_pelo(cor_pelo);
						m->setIbama(ibama);
						m->setPais_origem(pais_origem);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<MamiferoExotico> m = std::dynamic_pointer_cast<MamiferoExotico>(animal);
							m->setId(id);
							m->setClasse(classe);
							m->setNome(nome);
							m->setCientifico(cientifico);
							m->setSexo(sexo);
							m->setTamanho(tamanho);
							m->setDieta(dieta);
							m->setVeterinario((*vet));
							m->setTratador((*trat));
							m->setBatismo(batismo);
							m->setCor_pelo(cor_pelo);
							m->setIbama(ibama);
							m->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<MamiferoExotico> m = std::dynamic_pointer_cast<MamiferoExotico>(animal);
							m->setId(id);
							m->setClasse(classe);
							m->setNome(nome);
							m->setCientifico(cientifico);
							m->setSexo(sexo);
							m->setTamanho(tamanho);
							m->setDieta(dieta);
							m->setVeterinario((*vet));
							m->setTratador((*trat));
							m->setBatismo(batismo);
							m->setCor_pelo(cor_pelo);
							m->setIbama(ibama);
							m->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<MamiferoExotico> m = std::dynamic_pointer_cast<MamiferoExotico>(animal);
							m->setId(id);
							m->setClasse(classe);
							m->setNome(nome);
							m->setCientifico(cientifico);
							m->setSexo(sexo);
							m->setTamanho(tamanho);
							m->setDieta(dieta);
							m->setVeterinario((*vet));
							m->setTratador((*trat));
							m->setBatismo(batismo);
							m->setCor_pelo(cor_pelo);
							m->setIbama(ibama);
							m->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
						return;
					}
				}
				else if(tipo == "Domestico") {
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<Mamifero> m = std::dynamic_pointer_cast<Mamifero>(animal);
						m->setId(id);
						m->setClasse(classe);
						m->setNome(nome);
						m->setCientifico(cientifico);
						m->setSexo(sexo);
						m->setTamanho(tamanho);
						m->setDieta(dieta);
						m->setVeterinario((*vet));
						m->setTratador((*trat));
						m->setBatismo(batismo);
						m->setCor_pelo(cor_pelo);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<Mamifero> m = std::dynamic_pointer_cast<Mamifero>(animal);
							m->setId(id);
							m->setClasse(classe);
							m->setNome(nome);
							m->setCientifico(cientifico);
							m->setSexo(sexo);
							m->setTamanho(tamanho);
							m->setDieta(dieta);
							m->setVeterinario((*vet));
							m->setTratador((*trat));
							m->setBatismo(batismo);
							m->setCor_pelo(cor_pelo);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<Mamifero> m = std::dynamic_pointer_cast<Mamifero>(animal);
							m->setId(id);
							m->setClasse(classe);
							m->setNome(nome);
							m->setCientifico(cientifico);
							m->setSexo(sexo);
							m->setTamanho(tamanho);
							m->setDieta(dieta);
							m->setVeterinario((*vet));
							m->setTratador((*trat));
							m->setBatismo(batismo);
							m->setCor_pelo(cor_pelo);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<Mamifero> m = std::dynamic_pointer_cast<Mamifero>(animal);
							m->setId(id);
							m->setClasse(classe);
							m->setNome(nome);
							m->setCientifico(cientifico);
							m->setSexo(sexo);
							m->setTamanho(tamanho);
							m->setDieta(dieta);
							m->setVeterinario((*vet));
							m->setTratador((*trat));
							m->setBatismo(batismo);
							m->setCor_pelo(cor_pelo);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
						return;
					}
				}
				else {
					cout << endl << "Erro, classificacao do animal e invalida." << endl << endl;
					return;
				}
			}
			else if(classe == "Reptilia") {
				bool venenoso;
				string tipo_veneno;
				cout << "Digite (1) se for venenoso ou (0) caso contrario: ";
				cin >> venenoso;
				cout << "Digite o tipo de veneno: ";
				cin >> tipo_veneno;
				if(tipo == "Nativo") {
					string ibama, uf_origem, autorizacao;
					cout << "Digite o identificador do ibama: ";
					cin >> ibama;
					cout << "Digite a uf de origem: ";
					cin >> uf_origem;
					cout << "Digite a autorizacao: ";
					cin >> autorizacao;
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<ReptilNativo> r = std::dynamic_pointer_cast<ReptilNativo>(animal);
						r->setId(id);
						r->setClasse(classe);
						r->setNome(nome);
						r->setCientifico(cientifico);
						r->setSexo(sexo);
						r->setTamanho(tamanho);
						r->setDieta(dieta);
						r->setVeterinario((*vet));
						r->setTratador((*trat));
						r->setBatismo(batismo);
						r->setVenenoso(venenoso);
						r->setTipo_veneno(tipo_veneno);
						r->setIbama(ibama);
						r->setUf_origem(uf_origem);
						r->setAutorizacao(autorizacao);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<ReptilNativo> r = std::dynamic_pointer_cast<ReptilNativo>(animal);
							r->setId(id);
							r->setClasse(classe);
							r->setNome(nome);
							r->setCientifico(cientifico);
							r->setSexo(sexo);
							r->setTamanho(tamanho);
							r->setDieta(dieta);
							r->setVeterinario((*vet));
							r->setTratador((*trat));
							r->setBatismo(batismo);
							r->setVenenoso(venenoso);
							r->setTipo_veneno(tipo_veneno);
							r->setIbama(ibama);
							r->setUf_origem(uf_origem);
							r->setAutorizacao(autorizacao);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<ReptilNativo> r = std::dynamic_pointer_cast<ReptilNativo>(animal);
							r->setId(id);
							r->setClasse(classe);
							r->setNome(nome);
							r->setCientifico(cientifico);
							r->setSexo(sexo);
							r->setTamanho(tamanho);
							r->setDieta(dieta);
							r->setVeterinario((*vet));
							r->setTratador((*trat));
							r->setBatismo(batismo);
							r->setVenenoso(venenoso);
							r->setTipo_veneno(tipo_veneno);
							r->setIbama(ibama);
							r->setUf_origem(uf_origem);
							r->setAutorizacao(autorizacao);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<ReptilNativo> r = std::dynamic_pointer_cast<ReptilNativo>(animal);
							r->setId(id);
							r->setClasse(classe);
							r->setNome(nome);
							r->setCientifico(cientifico);
							r->setSexo(sexo);
							r->setTamanho(tamanho);
							r->setDieta(dieta);
							r->setVeterinario((*vet));
							r->setTratador((*trat));
							r->setBatismo(batismo);
							r->setVenenoso(venenoso);
							r->setTipo_veneno(tipo_veneno);
							r->setIbama(ibama);
							r->setUf_origem(uf_origem);
							r->setAutorizacao(autorizacao);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
					}
				}
				else if(tipo == "Exotico") {
					string ibama, pais_origem;
					cout << "Digite o identificador do ibama: ";
					cin >> ibama;
					cout << "Digite o pais de origem: ";
					cin >> pais_origem;
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<ReptilExotico> r = std::dynamic_pointer_cast<ReptilExotico>(animal);
						r->setId(id);
						r->setClasse(classe);
						r->setNome(nome);
						r->setCientifico(cientifico);
						r->setSexo(sexo);
						r->setTamanho(tamanho);
						r->setDieta(dieta);
						r->setVeterinario((*vet));
						r->setTratador((*trat));
						r->setBatismo(batismo);
						r->setVenenoso(venenoso);
						r->setTipo_veneno(tipo_veneno);
						r->setIbama(ibama);
						r->setPais_origem(pais_origem);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<ReptilExotico> r = std::dynamic_pointer_cast<ReptilExotico>(animal);
							r->setId(id);
							r->setClasse(classe);
							r->setNome(nome);
							r->setCientifico(cientifico);
							r->setSexo(sexo);
							r->setTamanho(tamanho);
							r->setDieta(dieta);
							r->setVeterinario((*vet));
							r->setTratador((*trat));
							r->setBatismo(batismo);
							r->setVenenoso(venenoso);
							r->setTipo_veneno(tipo_veneno);
							r->setIbama(ibama);
							r->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<ReptilExotico> r = std::dynamic_pointer_cast<ReptilExotico>(animal);
							r->setId(id);
							r->setClasse(classe);
							r->setNome(nome);
							r->setCientifico(cientifico);
							r->setSexo(sexo);
							r->setTamanho(tamanho);
							r->setDieta(dieta);
							r->setVeterinario((*vet));
							r->setTratador((*trat));
							r->setBatismo(batismo);
							r->setVenenoso(venenoso);
							r->setTipo_veneno(tipo_veneno);
							r->setIbama(ibama);
							r->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<ReptilExotico> r = std::dynamic_pointer_cast<ReptilExotico>(animal);
							r->setId(id);
							r->setClasse(classe);
							r->setNome(nome);
							r->setCientifico(cientifico);
							r->setSexo(sexo);
							r->setTamanho(tamanho);
							r->setDieta(dieta);
							r->setVeterinario((*vet));
							r->setTratador((*trat));
							r->setBatismo(batismo);
							r->setVenenoso(venenoso);
							r->setTipo_veneno(tipo_veneno);
							r->setIbama(ibama);
							r->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
						return;
					}
				}
				else if(tipo == "Domestico") {
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<Reptil> r = std::dynamic_pointer_cast<Reptil>(animal);
						r->setId(id);
						r->setClasse(classe);
						r->setNome(nome);
						r->setCientifico(cientifico);
						r->setSexo(sexo);
						r->setTamanho(tamanho);
						r->setDieta(dieta);
						r->setVeterinario((*vet));
						r->setTratador((*trat));
						r->setBatismo(batismo);
						r->setVenenoso(venenoso);
						r->setTipo_veneno(tipo_veneno);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<Reptil> r = std::dynamic_pointer_cast<Reptil>(animal);
							r->setId(id);
							r->setClasse(classe);
							r->setNome(nome);
							r->setCientifico(cientifico);
							r->setSexo(sexo);
							r->setTamanho(tamanho);
							r->setDieta(dieta);
							r->setVeterinario((*vet));
							r->setTratador((*trat));
							r->setBatismo(batismo);
							r->setVenenoso(venenoso);
							r->setTipo_veneno(tipo_veneno);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<Reptil> r = std::dynamic_pointer_cast<Reptil>(animal);
							r->setId(id);
							r->setClasse(classe);
							r->setNome(nome);
							r->setCientifico(cientifico);
							r->setSexo(sexo);
							r->setTamanho(tamanho);
							r->setDieta(dieta);
							r->setVeterinario((*vet));
							r->setTratador((*trat));
							r->setBatismo(batismo);
							r->setVenenoso(venenoso);
							r->setTipo_veneno(tipo_veneno);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<Reptil> r = std::dynamic_pointer_cast<Reptil>(animal);
							r->setId(id);
							r->setClasse(classe);
							r->setNome(nome);
							r->setCientifico(cientifico);
							r->setSexo(sexo);
							r->setTamanho(tamanho);
							r->setDieta(dieta);
							r->setVeterinario((*vet));
							r->setTratador((*trat));
							r->setBatismo(batismo);
							r->setVenenoso(venenoso);
							r->setTipo_veneno(tipo_veneno);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
						return;
					}
				}
				else {
					cout << endl << "Erro, classificacao do animal e invalida." << endl << endl;
					return;
				}
			}
			else if(classe == "Aves"){
				float tamanho_bico, envergadura;
				cout << "Digite o tamanho do bico: ";
				cin >> tamanho_bico;
				cout << "Digite envergadura: ";
				cin >> envergadura;
				if(tipo == "Nativo") {
					string ibama, uf_origem, autorizacao;
					cout << "Digite o identificador do ibama: ";
					cin >> ibama;
					cout << "Digite a uf de origem: ";
					cin >> uf_origem;
					cout << "Digite a autorizacao: ";
					cin >> autorizacao;
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<AveNativa> av = std::dynamic_pointer_cast<AveNativa>(animal);
						av->setId(id);
						av->setClasse(classe);
						av->setNome(nome);
						av->setCientifico(cientifico);
						av->setSexo(sexo);
						av->setTamanho(tamanho);
						av->setDieta(dieta);
						av->setVeterinario((*vet));
						av->setTratador((*trat));
						av->setBatismo(batismo);
						av->setTamanho_bico(tamanho_bico);
						av->setEnvergadura(envergadura);
						av->setIbama(ibama);
						av->setUf_origem(uf_origem);
						av->setAutorizacao(autorizacao);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<AveNativa> av = std::dynamic_pointer_cast<AveNativa>(animal);
							av->setId(id);
							av->setClasse(classe);
							av->setNome(nome);
							av->setCientifico(cientifico);
							av->setSexo(sexo);
							av->setTamanho(tamanho);
							av->setDieta(dieta);
							av->setVeterinario((*vet));
							av->setTratador((*trat));
							av->setBatismo(batismo);
							av->setTamanho_bico(tamanho_bico);
							av->setEnvergadura(envergadura);
							av->setIbama(ibama);
							av->setUf_origem(uf_origem);
							av->setAutorizacao(autorizacao);
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<AveNativa> av = std::dynamic_pointer_cast<AveNativa>(animal);
							av->setId(id);
							av->setClasse(classe);
							av->setNome(nome);
							av->setCientifico(cientifico);
							av->setSexo(sexo);
							av->setTamanho(tamanho);
							av->setDieta(dieta);
							av->setVeterinario((*vet));
							av->setTratador((*trat));
							av->setBatismo(batismo);
							av->setTamanho_bico(tamanho_bico);
							av->setEnvergadura(envergadura);
							av->setIbama(ibama);
							av->setUf_origem(uf_origem);
							av->setAutorizacao(autorizacao);
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<AveNativa> av = std::dynamic_pointer_cast<AveNativa>(animal);
							av->setId(id);
							av->setClasse(classe);
							av->setNome(nome);
							av->setCientifico(cientifico);
							av->setSexo(sexo);
							av->setTamanho(tamanho);
							av->setDieta(dieta);
							av->setVeterinario((*vet));
							av->setTratador((*trat));
							av->setBatismo(batismo);
							av->setTamanho_bico(tamanho_bico);
							av->setEnvergadura(envergadura);
							av->setIbama(ibama);
							av->setUf_origem(uf_origem);
							av->setAutorizacao(autorizacao);
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
						return;
					}
				}
				else if(tipo == "Exotico") {
					string ibama, pais_origem;
					cout << "Digite o identificador do ibama: ";
					cin >> ibama;
					cout << "Digite o pais de origem: ";
					cin >> pais_origem;
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<AveExotica> av = std::dynamic_pointer_cast<AveExotica>(animal);
						av->setId(id);
						av->setClasse(classe);
						av->setNome(nome);
						av->setCientifico(cientifico);
						av->setSexo(sexo);
						av->setTamanho(tamanho);
						av->setDieta(dieta);
						av->setVeterinario((*vet));
						av->setTratador((*trat));
						av->setBatismo(batismo);
						av->setTamanho_bico(tamanho_bico);
						av->setEnvergadura(envergadura);
						av->setIbama(ibama);
						av->setPais_origem(pais_origem);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<AveExotica> av = std::dynamic_pointer_cast<AveExotica>(animal);
							av->setId(id);
							av->setClasse(classe);
							av->setNome(nome);
							av->setCientifico(cientifico);
							av->setSexo(sexo);
							av->setTamanho(tamanho);
							av->setDieta(dieta);
							av->setVeterinario((*vet));
							av->setTratador((*trat));
							av->setBatismo(batismo);
							av->setTamanho_bico(tamanho_bico);
							av->setEnvergadura(envergadura);
							av->setIbama(ibama);
							av->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<AveExotica> av = std::dynamic_pointer_cast<AveExotica>(animal);
							av->setId(id);
							av->setClasse(classe);
							av->setNome(nome);
							av->setCientifico(cientifico);
							av->setSexo(sexo);
							av->setTamanho(tamanho);
							av->setDieta(dieta);
							av->setVeterinario((*vet));
							av->setTratador((*trat));
							av->setBatismo(batismo);
							av->setTamanho_bico(tamanho_bico);
							av->setEnvergadura(envergadura);
							av->setIbama(ibama);
							av->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<AveExotica> av = std::dynamic_pointer_cast<AveExotica>(animal);
							av->setId(id);
							av->setClasse(classe);
							av->setNome(nome);
							av->setCientifico(cientifico);
							av->setSexo(sexo);
							av->setTamanho(tamanho);
							av->setDieta(dieta);
							av->setVeterinario((*vet));
							av->setTratador((*trat));
							av->setBatismo(batismo);
							av->setTamanho_bico(tamanho_bico);
							av->setEnvergadura(envergadura);
							av->setIbama(ibama);
							av->setPais_origem(pais_origem);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
						return;
					}
				}
				else if(tipo == "Domestico") {
					if(idvet == 0 && idtrat == 0 ) { 
						shared_ptr<Ave> av = std::dynamic_pointer_cast<Ave>(animal);
						av->setId(id);
						av->setClasse(classe);
						av->setNome(nome);
						av->setCientifico(cientifico);
						av->setSexo(sexo);
						av->setTamanho(tamanho);
						av->setDieta(dieta);
						av->setVeterinario((*vet));
						av->setTratador((*trat));
						av->setBatismo(batismo);
						av->setTamanho_bico(tamanho_bico);
						av->setEnvergadura(envergadura);
						cout << endl << "-----Animal Alterado-----" << endl << endl;
						return;
					}
					else if(idvet > 0 && idtrat == 0) {
						it2 = lista_funcionarios.find(idvet);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" ) {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							shared_ptr<Ave> av = std::dynamic_pointer_cast<Ave>(animal);
							av->setId(id);
							av->setClasse(classe);
							av->setNome(nome);
							av->setCientifico(cientifico);
							av->setSexo(sexo);
							av->setTamanho(tamanho);
							av->setDieta(dieta);
							av->setVeterinario((*vet));
							av->setTratador((*trat));
							av->setBatismo(batismo);
							av->setTamanho_bico(tamanho_bico);
							av->setEnvergadura(envergadura);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario nao encontrado." << endl << endl;
						return;
					}
					else if(idvet == 0 && idtrat > 0) {
						it2 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Tratador") {
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it2->second);
							shared_ptr<Ave> av = std::dynamic_pointer_cast<Ave>(animal);
							av->setId(id);
							av->setClasse(classe);
							av->setNome(nome);
							av->setCientifico(cientifico);
							av->setSexo(sexo);
							av->setTamanho(tamanho);
							av->setDieta(dieta);
							av->setVeterinario((*vet));
							av->setTratador((*trat));
							av->setBatismo(batismo);
							av->setTamanho_bico(tamanho_bico);
							av->setEnvergadura(envergadura);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, tratador nao encontrado." << endl << endl;
						return;
					}
					else {
						it2 = lista_funcionarios.find(idvet);
						it3 = lista_funcionarios.find(idtrat);
						if(it2 != lista_funcionarios.end() && (it2->second)->getFuncao() == "Veterinario" && it3 != lista_funcionarios.end() && (it3->second)->getFuncao() == "Tratador") {
							vet = std::dynamic_pointer_cast<PetFera::Veterinario>(it2->second);
							trat = std::dynamic_pointer_cast<PetFera::Tratador>(it3->second);
							shared_ptr<Ave> av = std::dynamic_pointer_cast<Ave>(animal);
							av->setId(id);
							av->setClasse(classe);
							av->setNome(nome);
							av->setCientifico(cientifico);
							av->setSexo(sexo);
							av->setTamanho(tamanho);
							av->setDieta(dieta);
							av->setVeterinario((*vet));
							av->setTratador((*trat));
							av->setBatismo(batismo);
							av->setTamanho_bico(tamanho_bico);
							av->setEnvergadura(envergadura);
							cout << endl << "-----Animal Alterado-----" << endl << endl;
							return;
						}
						cout << endl << "Erro, veterinario ou/e tratador nao encontrado." << endl << endl;
						return;
					}
				}
				else {
					cout << endl << "Erro, classificacao do animal e invalida." << endl << endl;
					return;
				}
			}
		}
	}
	void Menu::acessar_um_animal() {
		int id;
		map<int, shared_ptr<Animal>>::iterator it; 
		cout << "Digite o identificador: ";
		cin >> id;

		it = lista_animais.find(id);
		if(it != lista_animais.end()) {
			cout << endl << *(it->second) << endl << endl;
			return;
		}
		cout << endl <<"Animal Inexistente." << endl << endl;	
		return;
	}

	void Menu::acessar_por_classe() {
		string classe;
		int cont = 0;
		map<int, shared_ptr<Animal>>::iterator it; 
		cout << "Digite a classe(Amphibia, Mammalia, Reptilia ou Aves): ";
		cin >> classe;
		for(it = lista_animais.begin(); it != lista_animais.end(); ++it) {
			if((it->second)->getClasse() == classe) {
				cout << "--------------------------------------" << endl;
				cout << endl << *(it->second) << endl << endl;
				cout << "--------------------------------------" << endl;;
				cont++;
			}
		}
		if(cont == 0) {
			cout << endl << "Nao existe animais presentes na classe digitada" << endl << endl;
		}
	}
	void Menu::acessar_por_funcionario() {
		int id;
		int cont = 0;
		map<int, shared_ptr<Animal>>::iterator it;
		map<int, shared_ptr<Funcionario>>::iterator it2; 
		cout << "Digite o identificador: ";
		cin >> id;

		it2 = lista_funcionarios.find(id);
		if(it2 != lista_funcionarios.end()) {
			cout << endl << "Funcionario removido com sucesso." << endl << endl;
			for(it = lista_animais.begin(); it != lista_animais.end(); ++it) {
				if((it->second)->getVeterinario().getId() == id || (it->second)->getTratador().getId() == id) {
					cout << "--------------------------------------" << endl;
					cout << endl << *(it->second) << endl << endl;
					cout << "--------------------------------------" << endl;;
					cont++;
				}
			}
			if(cont == 0) {
				cout << endl << "Nao existe animais associados ao funcionario digitado" << endl << endl;
			}
		}
		cout << endl << "Funcionario Inexistente" << endl << endl;
	}
}
