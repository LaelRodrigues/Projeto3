/** 
 * @file	animal.h
 * @brief	Definicao da classe Animal para representar
 *			um animal
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	07/12/2017
 */	

#ifndef ANIMAL_H
#define ANIMAL_H	

#include "tratador.h"
#include "veterinario.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;


namespace PetFera {
	
	/**
 	 * @class 	Animal animal.h
  	 * @brief	Classe que representa um Animal
 	 * @details Os atributos da classe animal sao: id,
 	 *			classe, nome, cientifico, sexo, tamanho, dieta,
 	 *			veterinariom, tratador e batismo.	
 	 */
	class Animal {
		
		protected:		
			int id;								/**< Identificador do animal */
			string classe;						/**< Classe do animal */
			string nome;						/**< Nome do animal */
			string cientifico;					/**< Nome cientifico do animal */
			char sexo;							/**< Sexo do animal */
			float tamanho;						/**< Tamanho do animal */
			string dieta;						/**< Dieta do animal */
			Veterinario veterinario;			/**< Veterinario do animal */
			Tratador tratador;					/**< Tratador do animal */
			string batismo;						/**< Nome de batismo do animal */

		public:

			/** @brief Construtor padrao */
			Animal();

			/** @brief Construtor parametrizado */	
			Animal(int _id, string _classe, string _nome, string _cientifico,
			char _sexo, float _tamanho, string _dieta, Veterinario _veterinairo,
			Tratador _tratador, string _batismo);

			/** @brief Destrutor padrao */
			~Animal();

			/** @brief Retorna o identificador do animal */
			int getId();

			/** @brief Retorna a classe do animal */
			string getClasse();

			/** @brief Retorna o nome do animal */
			string getNome();

			/** @brief Retorna o nome cientifico do animal */
			string getCientifico();

			/** @brief Retorna o sexo do animal */
			char getSexo();

			/** @brief Retorna o tamanho do animal */
			float getTamanho();

			/** @brief Retorna a dieta do animal */
			string getDieta();

			/** @brief Retorna o veterinario do animal */
			Veterinario getVeterinario();

			/** @brief Retorna o tratador do animal */
			Tratador getTratador();

			/** @brief Retorna o nome batismo do animal */
			string getBatismo();

			/** @brief Modifica o identificador do animal */
			void setId(int _id);

			/** @brief Modifica a classe do animal */
			void setClasse(string _classe);

			/** @brief Modifica o nome do animal */
			void setNome(string _nome);

			/** @brief Modifica o nome cientifico do animal */
			void setCientifico(string _cientifico);

			/** @brief Modifica o sexo do animal */
			void setSexo(char _sexo);

			/** @brief Modifica o tamanho do animal */
			void setTamanho(float _tamanho);

			/** @brief Modifica a dieta do animal */
			void setDieta(string _dieta);

			/** @brief Modifica o veterinario do animal*/
			void setVeterinario(Veterinario _veterinairo);

			/** @brief Modifica o tratador do animal */
			void setTratador(Tratador _tratador);

			/** @brief Modifica o nome batismo do animal */
			void setBatismo(string _batismo);

			/** @brief Sobrecarga do operador de insercao em stream */
			friend std::ostream& operator<< (std::ostream &o, Animal &a);

			/** @brief Sobrecarga do operador de comparacao */
			bool operator==(const Animal &a);
 
		private:

			/** @brief Metodo virtual puro para imprimir os dados de um animal */
			virtual std::ostream& print(std::ostream&);

	};
}

#endif