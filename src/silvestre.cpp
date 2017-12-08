/** 
 * @file	silvestre.cpp
 * @brief	Implementacao da classe Silvestre para representar
 *			um animal silvestre
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	07/12/2017
 */	


#include "silvestre.h"

#include <string>
using std::string;

namespace PetFera {

	// Construtor padrao
	Silvestre::Silvestre() {}

	/**
	 * @param _ibama Identificador do ibama
	 */
	Silvestre::Silvestre(string _ibama) {
		setIbama(_ibama);
	}

	// Destrutor padrao
	Silvestre::~Silvestre() {}

	/** @return Identificador do ibama*/
	string Silvestre::getIbama() {
		return ibama;
	}

	/** @param _ibama Identificador do ibama */
	void Silvestre::setIbama(string _ibama) {
		ibama = _ibama;
	}
}