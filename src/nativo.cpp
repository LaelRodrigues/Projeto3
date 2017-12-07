/** 
 * @file	nativo.cpp
 * @brief	Implementacao da classe Nativo para representar
 *			um animal nativo
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	07/12/2017
 */	


#include "nativo.h"

#include <string>
using std::string;

namespace PetFera {

	// Construtor padrao
	Nativo::Nativo() {}

	/**
	 * @param _ibama Identificador do ibama
	 * @param _uf_origem UF de origem do animal nativo
	 * @param _autorizacao Autorizacao do animal nativo
	 */
	Nativo::Nativo(string _ibama, string _uf_origem, string _autorizacao): Silvestre(_ibama) {
		setUf_origem(_uf_origem);
		setAutorizacao(_autorizacao);
	}

	// Destrutor padrao
	Nativo::~Nativo() {}

	/** @return UF de origem do animal nativo */
	string Nativo::getUf_origem() {
		return uf_origem;
	}

	/** @return A ultima muda do anfibio */
	string Nativo::getAutorizacao() {
		return autorizacao;
	}

	/** @param _uf_origem UF de origem do animal nativo */
	void Nativo::setUf_origem(string _uf_origem) {
		uf_origem = _uf_origem;
	}

	/** @param _autorizacao Autorizacao do animal nativo */
	void Nativo::setAutorizacao(string _autorizacao) {
		autorizacao = _autorizacao;
	}
}