/** 
 * @file	veterinario.cpp
 * @brief	Implementacao da classe Veterinario para representar
 *			um veterinario
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	02/12/2017
 * @date 	07/12/2017
 */	


#include "veterinario.h"

#include <string>
using std::string;

#include <iostream>
using std::endl;

namespace PetFera {

	// Construtor padrao
	Veterinario::Veterinario() {}

	/**
	 * @param _id Identificador do funcionario
	 * @param _nome Nome do funcionario
	 * @param _funcao Funcao do funcionario
	 * @param _cpf Cpf do funcionario
	 * @param _idade Idade do funcionario
	 * @param _tipo_sanguineo Tipo sanguineo do funcionario
	 * @param _fatorRH Fator RH do funcionario
	 * @param _especialidade Especialidade do funcionario
	 */
	Veterinario::Veterinario(int _id, string _nome, string _funcao, string _cpf, 
	int _idade, string _tipo_sanguineo, char _fatorRH, string _especialidade):
	Funcionario(_id, _nome, _funcao, _cpf, _idade, _tipo_sanguineo, _fatorRH,
	_especialidade){}

	//	Destrutor padrao
	Veterinario::~Veterinario() {}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream&
	Veterinario::print(std::ostream &o) const {
		o << "Identificador: " << id << endl;
		o << "Nome: " << nome << endl;
		o << "CPF: " << cpf << endl;
		o << "Funcao: " << funcao << endl; 
		o << "Idade: " << idade << endl;
		o << "Tipo sanguineo: " << tipo_sanguineo << endl;
		o << "Fator Rh: "<< fatorRH << endl;
		o << "Especialidade: " << especialidade; 
		return o;
	}
}