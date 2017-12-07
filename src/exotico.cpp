/** 
 * @file	exotico.h
 * @brief	Implementacao da classe Exotico para representar
 *			um animal exotico
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	07/12/2017
 */	


#include "exotico.h"

#include <string>
using std::string;

namespace PetFera {

	// Construtor padrao
	Exotico::Exotico() {}

	/**
	 * @param _ibama Identificador do ibama
	 * @param _pais_origem Pais de origem do animal exotico
	 */
	Exotico::Exotico(string _ibama, string _pais_origem): Silvestre(_ibama) {
		setPais_origem(_pais_origem);
	}

	// Destrutor padrao
	Exotico::~Exotico() {}

	/** @return Pais de origem do animal exotico */
	string Exotico::getPais_origem() {
		return pais_origem;
	}

	/** @param _pais_origem Pais de origem do animal nativo */
	void Exotico::setPais_origem(string _pais_origem) {
		pais_origem = _pais_origem;
	}
}