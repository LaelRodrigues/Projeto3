/** 
 * @file	exotico.h
 * @brief	Definicao da classe Exotico para representar
 *			um animal exotico
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	07/12/2017
 */	

#ifndef EXOTICO_H
#define EXOTICO_H

#include "silvestre.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;

namespace PetFera {
	
	/**
 	 * @class 	Exotico exotico.h
  	 * @brief	Classe que representa um animal Exotico
  	 * @details Atributos de um animal exotico sao: pais_origem
 	 */
	class Exotico : public Silvestre {

		protected:
			string pais_origem;			/**< Pais de origem do animal exotico */

		public:
			/** @brief Construtor padrao */
			Exotico();

			/** @brief Construtor parametrizado */	
			Exotico(string _ibama, string _pais_origem);

			/** @brief Destrutor padrao */
			~Exotico();

			/** @brief Retorna o pais de origem do animal exotico */
			string getPais_origem();

			/** @brief Modifica o pais de origem do animal exotico */
			void setPais_origem(string _pais_origem);

	};
}

#endif