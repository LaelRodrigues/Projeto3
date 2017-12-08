/** 
 * @file	veterinario.h
 * @brief	Definicao da classe Veterinario para representar
 *			um veterinario
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	02/12/2017
 * @date 	07/12/2017
 */	

#ifndef VETERINARIO_H
#define VETERINARIO_H

#include "funcionario.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;

namespace PetFera {
	
	/**
 	 * @class 	Veterinario veterinario.h
  	 * @brief	Classe que representa um Veterinario
 	 */
	class Veterinario : public Funcionario {

		public:
			/** @brief Construtor padrao */
			Veterinario();

			/** @brief Construtor parametrizado */	
			Veterinario(int _id, string _nome, string _funcao, string _cpf, int _idade,
			string _tipo_sanguineo, char _fatorRH, string _especialidade);

			/** @brief Destrutor padrao */
			~Veterinario();

		private:
			
			/** @brief Metodo para imprimir os dados de um veterinario */
			std::ostream& print(std::ostream &o) const;
	};
}

#endif