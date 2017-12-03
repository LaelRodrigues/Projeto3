/** 
 * @file	tratador.cpp
 * @brief	Implementacao da classe Tratador para representar
 *			um tratador
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	02/12/2017
 * @date 	02/12/2017
 */	


#include "tratador.h"


namespace PetFera {

	// Construtor padrao
	Tratador::Tratador() {}

	/**
	 * @param _id Identificador do funcionario
	 * @param _nome Nome do funcionario
	 * @param _cpf Cpf do funcionario
	 * @param _idade Idade do funcionario
	 * @param _tipo_sanguineo Tipo sanguineo do funcionario
	 * @param _fatorRH Fator RH do funcionario
	 * @param _especialidade Especialidade do funcionario
	 */
	Tratador::Tratador(int _id, string _nome, string _cpf, int _idade,
	string _tipo_sanguineo, char _fatorRH, string _especialidade):
	Funcionario(_id, _nome, _cpf, _idade, _tipo_sanguineo, _fatorRH,
	_especialidade)  {}

	//	Destrutor padrao
	Tratador::~Tratador() {}
}