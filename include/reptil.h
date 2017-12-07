/** 
 * @file	reptil.h
 * @brief	Definicao das classes Reptil, ReptilNativo e
 *			ReptilExotico
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	06/12/2017
 * @date 	07/12/2017
 */	

#ifndef REPTIL_H
#define REPTIL_H

#include "animal.h"
#include "nativo.h"
#include "exotico.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;

namespace PetFera {
	
	/**
 	 * @class 	Reptil reptil.h
  	 * @brief	Classe que representa um Reptil
  	 * @details Atributos de um reptil sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta,  
  	 *			veterinario, tratador, batismo, venenoso
  	 *			e tipo_veneno
 	 */
	class Reptil : public Animal {

		protected:
			bool venenoso;				/**< Indentifica se o reptil e venenoso */
			string tipo_veneno;			/**< Tipo de veneno do reptil */

		public:
			/** @brief Construtor padrao */
			Reptil();

			/** @brief Construtor parametrizado */	
			Reptil(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
			Tratador _tratador, string _batismo, bool _venenoso, string _tipo_veneno);

			/** @brief Destrutor padrao */
			~Reptil();

			/** @brief Retorna true se reptil for venenoso e false caso contrario */
			bool getVenenoso();

			/** @brief Retorna o tipo de veneno do reptil */
			string getTipo_veneno();

			/** @brief Modifica a Indicacao se o reptil e venenoso ou nao */
			void setVenenoso(bool _venenoso);

			/** @brief Modifica o tipo de veneno do reptil */
			void setTipo_veneno(string _tipo_veneno);

		private:

			/** @brief Metodo para imprimir os dados de um reptil */
			std::ostream& print(std::ostream&);

	};

	/**
 	 * @class 	ReptilNativo reptil.h
  	 * @brief	Classe que representa um ReptilNativo
  	 * @details Atributos de um reptil nativo sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, veterinario,
  	 *			tratador, batismo, venenoso, tipo_veneno, ibama,
  	 *			uf_origem e autorizacao
 	 */
	class ReptilNativo : public Reptil, public Nativo {

		public:
			/** @brief Construtor padrao */
			ReptilNativo();

			/** @brief Construtor parametrizado */	
			ReptilNativo(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
			Tratador _tratador, string _batismo, bool _venenoso, string _tipo_veneno, 
			string _ibama, string _uf_origem, string _autorizacao);

			/** @brief Destrutor padrao */
			~ReptilNativo();

		private:

			/** @brief Metodo para imprimir os dados de um reptil nativo */
			std::ostream& print(std::ostream&);

	};

	/**
 	 * @class 	ReptilExotico reptil.h
  	 * @brief	Classe que representa um ReptilExotico
  	 * @details Atributos de um reptil exotico sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, veterinario,
  	 *			tratador, batismo, venenoso, tipo_veneno, ibama
  	 *			e pais_origem
 	 */
	class ReptilExotico : public Reptil, public Exotico {

		public:
			/** @brief Construtor padrao */
			ReptilExotico();

			/** @brief Construtor parametrizado */	
			ReptilExotico(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, 
			Tratador _tratador, string _batismo, bool _venenoso, string _tipo_veneno, 
			string _ibama, string _pais_origem);

			/** @brief Destrutor padrao */
			~ReptilExotico();

		private:

			/** @brief Metodo para imprimir os dados de um reptil exotico */
			std::ostream& print(std::ostream&);

	};
}

#endif