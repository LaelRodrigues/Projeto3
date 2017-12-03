/** 
 * @file	tratador.h
 * @brief	Definicao da classe Tratador para representar
 *			um tratador
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	02/12/2017
 * @date 	02/12/2017
 */	

#ifndef TRATADOR_H
#define TRATADOR_H

#include "funcionario.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;

namespace PetFera {
	
	/**
 	 * @class 	Tratador tratador.h
  	 * @brief	Classe que representa um Tratador
 	 */
	class Tratador : public Funcionario {

		public:
			/** @brief Construtor padrao */
			Tratador();

			/** @brief Construtor parametrizado */	
			Tratador(int _id, string _nome, string _cpf, int _idade,
			string _tipo_sanguineo, char _fatorRH, string _especialidade);

			/** @brief Destrutor padrao */
			~Tratador();
	};
}

#endif