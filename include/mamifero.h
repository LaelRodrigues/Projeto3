/** 
 * @file	mamifero.h
 * @brief	Definicao das classes Mamifero, MamiferoNativo e
 *			MamiferoExotico
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	05/12/2017
 * @date 	07/12/2017
 */	

#ifndef MAMIFERO_H
#define MAMIFERO_H

#include "animal.h"
#include "nativo.h"
#include "exotico.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;

namespace PetFera {
	
	/**
 	 * @class 	Mamifero mamifero.h
  	 * @brief	Classe que representa um Mamifero
  	 * @details Atributos de um mamifero sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta,
  	 *			veterinario, tratador, batismo e cor_pelo
 	 */
	class Mamifero : public Animal {

		protected:
			string cor_pelo;			/**< Cor do pelo do mamifero */

		public:
			/** @brief Construtor padrao */
			Mamifero();

			/** @brief Construtor parametrizado */	
			Mamifero(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, 
			Tratador _tratador, string _batismo, string _cor_pelo);

			/** @brief Destrutor padrao */
			~Mamifero();

			/** @brief Retorna a cor do pelo do mamifero */
			string getCor_pelo();

			/** @brief Modifica a cor do pelo do mamifero */
			void setCor_pelo(string _cor_pelo);

		private:

			/** @brief Metodo para imprimir os dados de um mamifero */
			std::ostream& print(std::ostream&);

	};

	/**
 	 * @class 	MamiferoNativo mamifero.h
  	 * @brief	Classe que representa um MamiferoNativo
  	 * @details Atributos de um mamifero nativo sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, veterinario,  
  	 *			tratador, batismo, cor_pelo, ibama, uf_origem
  	 *			e autorizacao
 	 */
	class MamiferoNativo : public Mamifero, public Nativo {

		public:
			/** @brief Construtor padrao */
			MamiferoNativo();

			/** @brief Construtor parametrizado */	
			MamiferoNativo(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
			Tratador _tratador,string _batismo, string _cor_pelo, string _ibama,
			string _uf_origem, string _autorizacao);

			/** @brief Destrutor padrao */
			~MamiferoNativo();

		private:

			/** @brief Metodo para imprimir os dados de um mamifero nativo */
			std::ostream& print(std::ostream&);


	};

	/**
 	 * @class 	MamiferoExotico mamifero.h
  	 * @brief	Classe que representa um MamiferoNativo
  	 * @details Atributos de um mamifero exotico sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, veterinario, 
  	 *			tratador, batismo, cor_pelo, ibama e pais_origem
  	 *
 	 */
	class MamiferoExotico : public Mamifero, public Exotico {

		public:
			/** @brief Construtor padrao */
			MamiferoExotico();

			/** @brief Construtor parametrizado */	
			MamiferoExotico(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
			Tratador _tratador, string _batismo, string _cor_pelo, string _ibama, 
			string _pais_origem);

			/** @brief Destrutor padrao */
			~MamiferoExotico();

		private:

			/** @brief Metodo para imprimir os dados de um mamifero exotico */
			std::ostream& print(std::ostream&);


	};
}

#endif