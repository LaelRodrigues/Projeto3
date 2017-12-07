/** 
 * @file	mamifero.cpp
 * @brief	Implementacao das classe Mamifero, MamiferoNativo e
 *			MamiferoExotico
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	05/12/2017
 * @date 	07/12/2017
 */	


#include "mamifero.h"

#include <string>
using std::string;

#include <iostream>
using std::endl;

namespace PetFera {

	// Construtor padrao
	Mamifero::Mamifero() {}

	/**
	 * @param _id Identificador do animal
	 * @param _classe Classe do animal
	 * @param _nome Nome do animal
	 * @param _cientifico Nome cientifico do animal
	 * @param _sexo Sexo do animal
	 * @param _tamanho Tamanho do animal
	 * @param _dieta Dieta do animal
	 * @param _veterinario Veterinario do animal
	 * @param _tratador Tratador do animal
	 * @param _batismo Nome de batismo do animal
	 * @param _cor_pelo Cor do pelo do mamifero
	 */
		
	Mamifero::Mamifero(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
	Tratador _tratador, string _batismo, string _cor_pelo): 
	Animal(_id, _classe, _nome, _cientifico,_sexo, _tamanho, _dieta, _veterinario,
	_tratador, _batismo) {
		setCor_pelo(_cor_pelo);
	}

	// Destrutor padrao
	Mamifero::~Mamifero() {}

	/** @return Cor do pelo do mamifero */
	string Mamifero::getCor_pelo() {
		return cor_pelo;
	}

	/** @param _cor_pelo Cor do pelo do mamifero */
	void Mamifero::setCor_pelo(string _cor_pelo) {
		cor_pelo = _cor_pelo;
	}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	Mamifero::print(std::ostream &o) {
		o << "Identificador: " << id << endl;
		o << "Classe: " << classe << endl; 
		o << "Nome: " << nome << endl;
		o << "Nome cientifico: " << cientifico << endl;
		o << "Sexo: " << sexo << endl;
		o << "Tamanho: " << tamanho << endl;
		o << "Dieta: " << dieta << endl;
		o << "Identificador do veterinario(o valor 0 indica que não existe): " << veterinario.getId() << endl;
		o << "Identificador do tratador(o valor 0 indica que não existe): " << tratador.getId() << endl;
		o << "Nome de batismo: " << batismo << endl;
		o << "Cor do pelo: " << cor_pelo; 
		return o;
	}

	
	// Contrutor padrao
	MamiferoNativo::MamiferoNativo() {}

	/**
	 * @param _id Identificador do animal
	 * @param _classe Classe do animal
	 * @param _nome Nome do animal
	 * @param _cientifico Nome cientifico do animal
	 * @param _sexo Sexo do animal
	 * @param _tamanho Tamanho do animal
	 * @param _dieta Dieta do animal
	 * @param _veterinario Veterinario do animal
	 * @param _tratador Tratador do animal
	 * @param _batismo Nome de batismo do animal
	 * @param _cor_pelo Cor do pelo do mamifero
	 * @param _ibama Identificador do ibama
	 * @param _uf_origem UF de origem do anfibio
	 * @param _autorizacao Autorizacao do anfibio
	 */
	MamiferoNativo::MamiferoNativo(int _id, string _classe, string _nome, string _cientifico, 
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
	string _batismo, string _cor_pelo, string _ibama, string _uf_origem, string _autorizacao): 
	Mamifero(_id, _classe, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario,
	_tratador, _batismo,_cor_pelo), Nativo(_ibama, _uf_origem, _autorizacao) {}

	// Destrutor padrao
	MamiferoNativo::~MamiferoNativo() {}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	MamiferoNativo::print(std::ostream &o) {
		o << "Identificador: " << id << endl;
		o << "Classe: " << classe << endl; 
		o << "Nome: " << nome << endl;
		o << "Nome cientifico: " << cientifico << endl;
		o << "Sexo: " << sexo << endl;
		o << "Tamanho: " << tamanho << endl;
		o << "Dieta: " << dieta << endl;
		o << "Identificador do veterinario(o valor 0 indica que não existe): " << veterinario.getId() << endl;
		o << "Identificador do tratador(o valor 0 indica que não existe): " << tratador.getId() << endl;
		o << "Nome de batismo: " << batismo << endl;
		o << "Cor do pelo: " << cor_pelo; 
		o << "Identificador do ibama: " << ibama << endl;
		o << "Uf de origem: " << uf_origem << endl;
		o << "Autorizacao: " << autorizacao << endl;
		return o;
	}

	// Construtor padrao
	MamiferoExotico::MamiferoExotico() {}

	/**
	 * @param _id Identificador do animal
	 * @param _classe Classe do animal
	 * @param _nome Nome do animal
	 * @param _cientifico Nome cientifico do animal
	 * @param _sexo Sexo do animal
	 * @param _tamanho Tamanho do animal
	 * @param _dieta Dieta do animal
	 * @param _veterinario Veterinario do animal
	 * @param _tratador Tratador do animal
	 * @param _batismo Nome de batismo do animal
	 * @param _cor_pelo Cor do pelo do mamifero
	 * @param _ibama Identificador do ibama
	 * @param _pais_origem Pais de origem do anfibio
	 */
	MamiferoExotico::MamiferoExotico(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
	string _batismo, string _cor_pelo, string _ibama , string _pais_origem) :
	Mamifero(_id, _classe, _nome, cientifico, _sexo, _tamanho, _dieta, _veterinario,
	_tratador, _batismo, _cor_pelo), Exotico(_ibama, _pais_origem) {}

	// Destrutor padrao
	MamiferoExotico::~MamiferoExotico() {}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	MamiferoExotico::print(std::ostream &o) {
		o << "Identificador: " << id << endl;
		o << "Classe: " << classe << endl; 
		o << "Nome: " << nome << endl;
		o << "Nome cientifico: " << cientifico << endl;
		o << "Sexo: " << sexo << endl;
		o << "Tamanho: " << tamanho << endl;
		o << "Dieta: " << dieta << endl;
		o << "Identificador do veterinario(o valor 0 indica que não existe): " << veterinario.getId() << endl;
		o << "Identificador do tratador(o valor 0 indica que não existe): " << tratador.getId() << endl;
		o << "Nome de batismo: " << batismo << endl;
		o << "Cor do pelo: " << cor_pelo; 
		o << "Identificador do ibama: " << ibama << endl;
		o << "Pais de origem: " << pais_origem << endl; 
		return o;
	}
}