/** 
 * @file	funcionario.cpp
 * @brief	Implementacao da classe Funcionario para representar
 *			um funcionario
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	03/12/2017
 */	


#include "funcionario.h"


namespace PetFera {

	// Construtor padrao
	Funcionario::Funcionario() {}

	/**
	 * @param _id Identificador do funcionario
	 * @param _nome Nome do funcionario
	 * @param _cpf Cpf do funcionario
	 * @param _idade Idade do funcionario
	 * @param _tipo_sanguineo Tipo sanguineo do funcionario
	 * @param _fatorRH Fator RH do funcionario
	 * @param _especialidade Especialidade do funcionario
	 */
	Funcionario::Funcionario(int _id, string _nome, string _cpf, int _idade,
	string _tipo_sanguineo, char _fatorRH, string _especialidade) {
		setId(_id);
		setNome(_nome);
		setCpf(_cpf);
		setIdade(_idade);
		setTipo_sanguineo(_tipo_sanguineo);
		setFatorRH(_fatorRH);
		setEspecialidade(_especialidade);
	}

	//	Destrutor padrao
	Funcionario::~Funcionario() {}

	/** @return Identificador do funcionario */
	int Funcionario::getId() {
		return id;
	}

	/** @return Nome do funcionario */
	string Funcionario::getNome() {
		return nome;
	}

	/** @return Cpf do funcionario */
	string Funcionario::getCpf() {
		return cpf;
	}

	/** @return Idade do funcionario */
	int Funcionario::getIdade() {
		return idade;
	}

	/** @return Tipo sanguineo do funcionario */
	string Funcionario::getTipo_sanguineo() {
		return tipo_sanguineo;
	}

	/** @return Fator RH do funcionario */
	char Funcionario::getFatorRH() {
		return fatorRH;
	}

	/** @return Especialidade do funcionario */
	string Funcionario::getEspecialidade() {
		return especialidade;
	}

	/** @param _id Identificador do funcionario */
	void Funcionario::setId(int _id) {
		id = _id;
	}

	/** @param _nome Nome do funcionario */
	void Funcionario::setNome(string _nome) {
		nome = _nome;
	}

	/** @param _cpf Cpf do funcionario */
	void Funcionario::setCpf(string _cpf) {
		cpf = _cpf;
	}

	/** @param _idade Idade do funcionario */
	void Funcionario::setIdade(int _idade) {
		idade = _idade;
	}

	/** @param _tipo_sanguineo Tipo sanguineo do funcionario */
	void Funcionario::setTipo_sanguineo(string _tipo_sanguineo) {
		tipo_sanguineo = _tipo_sanguineo;
	}

	/** @param _fatorRH Fator RH do funcionario */
	void Funcionario::setFatorRH(char _fatorRH) {
		fatorRH = _fatorRH;
	}

	/** @param _especialidade Especialidade do funcionario */
	void Funcionario::setEspecialidade(string _especialidade) {
		especialidade = _especialidade;
	}
}