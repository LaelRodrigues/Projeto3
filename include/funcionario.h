/** 
 * @file	funcionario.h
 * @brief	Definicao da classe Funcionario para representar
 *			um funcionario
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	07/12/2017
 */	

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H	

#include <ostream>
using std::ostream;

#include <string>
using std::string;



namespace PetFera {
	
	/**
 	 * @class 	Funcionario funcionario.h
  	 * @brief	Classe que representa um Funcionario
 	 * @details Os atributos da classe funcionario sao: id, 
 	 *			nome, funcao, cpf, idade, tipo_sanguineo, fatorRH e
 	 *			especialidade
 	 */
	class Funcionario {
		
		protected:		
			int id;					/**< Identificador do funcionario */
			string nome;			/**< Nome do funcionario */
			string funcao;			/**< Funcao do funcionario */
			string cpf;				/**< Cpf do funcionario */
			int idade;				/**< idade do funcionario */
			string tipo_sanguineo;	/**< Tipo sanguineo do funcionario */
			char fatorRH;			/**< Fator RH do funcionario */
			string especialidade;	/**< Especialidade do funcionario */

		public:

			/** @brief Construtor padrao */
			Funcionario();

			/** @brief Construtor parametrizado */	
			Funcionario(int _id, string _nome, string _funcao, string _cpf, int _idade,
			string _tipo_sanguineo, char _fatorRH, string _especialidade);

			/** @brief Destrutor padrao */
			~Funcionario();

			/** @brief Retorna o identificador do funcionario */
			int getId();

			/** @brief Retorna o nome do funcionario */
			string getNome();

			/** @brief Retorna a funcao do funcionario */
			string getFuncao();

			/** @brief Retorna o cpf do funcionario */
			string getCpf();

			/** @brief Retorna a idade do funcionario */
			int getIdade();

			/** @brief Retorna o tipo sanguineo do funcionario */
			string getTipo_sanguineo();

			/** @brief Retorna o fator RH do funcionario */
			char getFatorRH();

			/** @brief Retorna a especialidade do funcionario */
			string getEspecialidade();

			/** @brief Modifica o identificador do funcionario */
			void setId(int _id);

			/** @brief Modifica o nome do funcionario */
			void setNome(string _nome);

			/** @brief Modifica a funcao do funcionario */
			void setFuncao(string _funcao);

			/** @brief Modifica o cpf do funcionario */
			void setCpf(string _cpf);

			/** @brief Modifica a idade do funcionario */
			void setIdade(int _idade);

			/** @brief Modifica o tipo sanguineo do funcionario */
			void setTipo_sanguineo(string _tipo_sanguineo);

			/** @brief Modifica o fator RH do funcionario */
			void setFatorRH(char _fatorRH);

			/** @brief Modifica a especialidade do funcionario */
			void setEspecialidade(string _especialidade);

			/** @brief Sobrecarga do operador de insercao em stream */
			friend std::ostream& operator<< (std::ostream &o, Funcionario const &f);

			/** @brief Sobrecarga do operador de comparacao */
			bool operator==(const Funcionario &f);
 
		private:

			/** @brief Metodo virtual puro para imprimir os dado do funcionario */
			virtual std::ostream& print(std::ostream&) const = 0;
	};
}

#endif