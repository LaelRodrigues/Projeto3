/** 
 * @file	anfibio.h
 * @brief	Definicao das classes Anfibio, AnfibioNativo e
 *			AnfibioExotico
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	04/12/2017
 * @date 	07/12/2017
 */	

#ifndef ANFIBIO_H
#define ANFIBIO_H

#include "animal.h"
#include "nativo.h"
#include "exotico.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;

namespace PetFera {
	
	/**
 	 * @class 	Anfibio anfibio.h
  	 * @brief	Classe que representa um Anfibio
  	 * @details Atributos de um anfibio sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, 
  	 *			veterinario, tratador, batismo, total_mudas
  	 *			e ultima_muda
 	 */
	class Anfibio : public Animal {

		protected:
			int total_mudas;			/**< Total de mudas do anfibio */
			string ultima_muda;			/**< Ultima muda do anfibio */

		public:
			/** @brief Construtor padrao */
			Anfibio();

			/** @brief Construtor parametrizado */	
			Anfibio(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, 
			Tratador _tratador, string _batismo, int _total_mudas, string _ultima_muda);

			/** @brief Destrutor padrao */
			~Anfibio();

			/** @brief Retorna o total de mudas do anfibio */
			int getTotal_mudas();

			/** @brief Retorna a ultima muda do anfibio */
			string getUltima_muda();

			/** @brief Modifica o total de mudas do anfibio */
			void setTotal_mudas(int _total_mudas);

			/** @brief Modifica a ultima muda do anfibio */
			void setUltima_muda(string _ultima_muda);

		private:

			/** @brief Metodo para imprimir os dados de um anfibio */
			std::ostream& print(std::ostream&);

	};

	/**
 	 * @class 	AnfibioNativo anfibio.h
  	 * @brief	Classe que representa um AnfibioNativo
  	 * @details Atributos de um anfibio nativo sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, veterinario, 
  	 *			tratador, batismo, total_mudas, ultima_muda, ibama,
  	 *			uf_origem e autorizacao
 	 */
	class AnfibioNativo : public Anfibio, public Nativo {

		public:
			/** @brief Construtor padrao */
			AnfibioNativo();

			/** @brief Construtor parametrizado */	
			AnfibioNativo(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
			Tratador _tratador, string _batismo, int _total_mudas, string _ultima_muda,
			string _ibama, string _uf_origem, string _autorizacao);

			/** @brief Destrutor padrao */
			~AnfibioNativo();

		private:

			/** @brief Metodo para imprimir os dados de um anfibio nativo */
			std::ostream& print(std::ostream&);

	};

	/**
 	 * @class 	AnfibioExotico anfibio.h
  	 * @brief	Classe que representa um AnfibioExotico
  	 * @details Atributos de um anfibio exotico sao: id, classe,
  	 *			nome, cientifico, sexo, tamanho, dieta, veterinario
  	 *			tratador, batismo, total_mudas, ultima_muda, ibama
  	 *			e pais_origem
 	 */
	class AnfibioExotico : public Anfibio, public Exotico {

		public:
			/** @brief Construtor padrao */
			AnfibioExotico();

			/** @brief Construtor parametrizado */	
			AnfibioExotico(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
			Tratador _tratador, string _batismo, int _total_mudas, string _ultima_muda, 
			string _ibama, string _pais_origem);

			/** @brief Destrutor padrao */
			~AnfibioExotico();

		private:

			/** @brief Metodo para imprimir os dados de um anfibio exotico */
			std::ostream& print(std::ostream&);

	};
}

#endif