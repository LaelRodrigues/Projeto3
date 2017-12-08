/** 
 * @file	menu.h
 * @brief	Definicao da classe Menu para representar
 *			um menu do PetFera
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	07/12/2017
 * @date 	08/12/2017
 */	

#ifndef MENU_H
#define MENU_H	

#include "petfera.h"

#include <memory>
using std::shared_ptr;

#include <map>
using std::map;

#include <string>
using std::string;

//using namespace PetFera;


namespace PetFera {
	
	/**
 	 * @class 	Menu menu.h
  	 * @brief	Classe que representa um Menu do petfera
 	 * @details Os atributos da classe menu sao: 
 	 *			lista_funcionarios e lista_animais  
 	 */
	class Menu {

		private:
			map<int, shared_ptr<Funcionario>> lista_funcionarios;		/**< Lista de funcionarios */
			map<int, shared_ptr<Animal>> lista_animais;			/**< Lista de Animais */

		public:
			/** @brief Construtor padrao */
			Menu();

			/** @brief Destrutor padrao */
			~Menu();

			/** @brief Metodo para cadastrar um funcionario */
			void cadastroFuncionario();

			/** @brief Metodo para excluir um funcionario */
			void excluirFuncionario();

			/** @brief Metodo para alterar os dados de um funcionario */
			void alterarFuncionario();

			/** @brief Metodo para cadastrar um animal */
			void cadastroAnimal();

			/** @brief Metodo para excluir um animal */
			void excluirAnimal();

			/** @brief Metodo para alterar os dados de um animal */
			void alterarAnimal();

			/** @brief Acessar os dados de um animal */
			void acessar_um_animal();

			/** @brief Acessar os dados de uma classe de animais */
			void acessar_por_classe();

			/** @brief Acessar os dados de animais sobe a responsabilidade de um funcionario */
			void acessar_por_funcionario();
	};
}

#endif