/** 
 * @file	silvestre.h
 * @brief	Definicao da classe Silvestre para representar
 *			um animal silvestre
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	07/12/2017
 */	

#ifndef SILVESTRE_H
#define SILVESTRE_H

#include <ostream>
using std::ostream;

#include <string>
using std::string;

namespace PetFera {
	
	/**
 	 * @class 	Silvestre silvestre.h
  	 * @brief	Classe que representa um animal Silvestre
  	 * @details Atributo de um animal silveste: ibama
 	 */
	class Silvestre {

		protected:
			string ibama;			/**< identificador do Ibama */

		public:
			/** @brief Construtor padrao */
			Silvestre();

			/** @brief Construtor parametrizado */	
			Silvestre(string _ibama);

			/** @brief Destrutor padrao */
			~Silvestre();

			/** @brief Retorna o identificador do ibama */
			string getIbama();

			/** @brief Modifica o identificador do ibama*/
			void setIbama(string _ibama);

	};
}

#endif