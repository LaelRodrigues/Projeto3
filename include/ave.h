/** 
 * @file	ave.h
 * @brief	Definicao das classes Ave, AveNativa e
 *			AveExotica
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	06/12/2017
 * @date 	06/12/2017
 */	

#ifndef AVE_H
#define AVE_H

#include "animal.h"
#include "nativo.h"
#include "exotico.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;

namespace PetFera {
	
	/**
 	 * @class 	Ave ave.h
  	 * @brief	Classe que representa um Anfibio
  	 * @details Atributos de um anfibio sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, 		
  	 *			veterinario, tratador, batismo, tamanho_bico,
  	 * 			e envergadura
 	 */
	class Ave : public Animal {

		protected:
			float tamanho_bico;			/**< Tamanho do bico da ave */
			float envergadura;			/**< Envergadura da Ave */

		public:
			/** @brief Construtor padrao */
			Ave();

			/** @brief Construtor parametrizado */	
			Ave(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
			Tratador _tratador, string _batismo, float _tamanho_bico, float _envergadura);

			/** @brief Destrutor padrao */
			~Ave();

			/** @brief Retorna o tamanho do bico da ave */
			float getTamanho_bico();

			/** @brief Retorna a envergadura da ave */
			float getEnvergadura();

			/** @brief Modifica o tamanho do bico da ave */
			void setTamanho_bico(float _tamanho_bico);

			/** @brief Modifica a envergadura da ave */
			void setEnvergadura(float _envergadura);

		private:

			/** @brief Metodo para imprimir os dados de uma ave */
			std::ostream& print(std::ostream&);

	};

	/**
 	 * @class 	AveNativa ave.h
  	 * @brief	Classe que representa um AveNativa
  	 * @details Atributos de um ave nativa sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, veterinario 
  	 *			tratador, batismo, tamanho_bico, envergadura, ibama,
  	 *			uf_origem e autorizacao
 	 */
	class AveNativa : public Ave, public Nativo {

		public:
			/** @brief Construtor padrao */
			AveNativa();

			/** @brief Construtor parametrizado */	
			AveNativa(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
			Tratador _tratador, string _batismo, float _tamanho_bico, float _envergadura, 
			string _ibama, string _uf_origem, string _autorizacao);

			/** @brief Destrutor padrao */
			~AveNativa();

		private:

			/** @brief Metodo para imprimir os dados de uma ave nativa */
			std::ostream& print(std::ostream&);	
	};

	/**
 	 * @class 	AveExotica ave.h
  	 * @brief	Classe que representa um AveExotica
  	 * @details Atributos de um anfibio exotico sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, veterinario
  	 *			tratador, batismo, tamanho_bico, envergadura, ibama
  	 *			e pais_origem
 	 */
	class AveExotica : public Ave, public Exotico {

		public:
			/** @brief Construtor padrao */
			AveExotica();

			/** @brief Construtor parametrizado */	
			AveExotica(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
			Tratador _tratador, string _batismo, float _tamanho_bico, float _envergadura,
			string _ibama, string _pais_origem);

			/** @brief Destrutor padrao */
			~AveExotica();

		private:

			/** @brief Metodo para imprimir os dados de uma ave exotica */
			std::ostream& print(std::ostream&);

	};
}

#endif