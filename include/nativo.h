/** 
 * @file	nativo.h
 * @brief	Definicao da classe Nativo para representar
 *			um animal nativo
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	07/12/2017
 */	

#ifndef NATIVO_H
#define NATIVO_H

#include "silvestre.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;

namespace PetFera {
	
	/**
 	 * @class 	Nativo nativo.h
  	 * @brief	Classe que representa um animal Nativo
  	 * @details Atributos de um animal nativo sao: ibama, uf_origem e
  	 *			autorizacao
 	 */
	class Nativo : public Silvestre {

		protected:
			string uf_origem;			/**< UF de origem do animal nativo */
			string autorizacao;			/**< Autorizacao do animal nativo */

		public:
			/** @brief Construtor padrao */
			Nativo();

			/** @brief Construtor parametrizado */	
			Nativo(string _ibama, string _uf_origem, string _autorizacao);

			/** @brief Destrutor padrao */
			~Nativo();

			/** @brief Retorna a UF de origem do animal nativo */
			string getUf_origem();

			/** @brief Retorna a autorizacao do animal nativo */
			string getAutorizacao();

			/** @brief Modifica a UF de origem do animal nativo */
			void setUf_origem(string _uf_origem);

			/** @brief Modifica a autorizacao do animal nativo */
			void setAutorizacao(string _autorizacao);
	};
}

#endif