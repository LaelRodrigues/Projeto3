/** 
 * @file	ave.cpp
 * @brief	Implementacao das classe Ave, AveNativa e
 *			AveExotica
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	02/12/2017
 * @date 	02/12/2017
 */	


#include "ave.h"

#include <string>
using std::string;

#include <iostream>
using std::endl;

namespace PetFera {

	// Construtor padrao
	Ave::Ave() {}

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
	 * @param _tamanho_bico Tamanho do bico da ave
	 * @param _envergadura Envergadura da ave
	 */
	Ave::Ave(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
	Tratador _tratador, string _batismo, float _tamanho_bico, float _envergadura): 
	Animal(_id, _classe, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario,
	_tratador, _batismo) {
		setTamanho_bico(_tamanho_bico);
		setEnvergadura(_envergadura);
	}

	// Destrutor padrao
	Ave::~Ave() {}

	/** @return Tamanho do bico da ave */
	float Ave::getTamanho_bico() {
		return tamanho_bico;
	}

	/** @return Envergadura da ave */
	float Ave::getEnvergadura() {
		return envergadura;
	}

	/** @param _tamanho_bico Tamanho do bico da ave */
	void Ave::setTamanho_bico(float _tamanho_bico) {
		tamanho_bico = _tamanho_bico;
	}

	/** @param _envergadura Envergadura da ave */
	void Ave::setEnvergadura(float _envergadura) {
		envergadura = _envergadura;
	}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	Ave::print(std::ostream &o) {
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
		o << "Tamanho do bico: " << tamanho_bico << endl;
		o << "Envergadura: "<< envergadura << endl; 
		return o;
	}

	
	// Contrutor padrao
	AveNativa::AveNativa() {}


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
	 * @param _tamanho_bico Tamanho do bico da ave
	 * @param _envergadura Envergadura da ave
	 * @param _ibama Identificador do ibama
	 * @param _uf_origem UF de origem do anfibio
	 * @param _autorizacao Autorizacao do anfibio
	 */
	AveNativa::AveNativa(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
	Tratador _tratador, string _batismo, float _tamanho_bico, float _envergadura, 
	string _ibama, string _uf_origem, string _autorizacao): Ave(_id, _classe, _nome,
	_cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador, _batismo,
	_tamanho_bico, _envergadura), Nativo(_ibama,_uf_origem, _autorizacao) {}

	// Destrutor padrao
	AveNativa::~AveNativa() {}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	AveNativa::print(std::ostream &o) {
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
		o << "Tamanho do bico: " << tamanho_bico << endl;
		o << "Envergadura: "<< envergadura << endl; 
		o << "Identificador do ibama: " << ibama << endl;
		o << "Uf de origem: " << uf_origem << endl;
		o << "Autorizacao: " << autorizacao << endl; 
		return o;
	}	

	// Construtor padrao
	AveExotica::AveExotica() {}

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
	 * @param _tamanho_bico Tamanho do bico da ave
	 * @param _envergadura Envergadura da ave
	 * @param _ibama Identificador do ibama
	 * @param _pais_origem Pais de origem do anfibio
	 */
	AveExotica::AveExotica(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
	Tratador _tratador, string _batismo, float _tamanho_bico, float _envergadura, 
	string _ibama , string _pais_origem): Ave(_id, _classe, _nome, cientifico, _sexo,
	_tamanho, _dieta, _veterinario, _tratador, _batismo, _tamanho_bico, _envergadura), 
	Exotico(_ibama, _pais_origem) {}

	// Destrutor padrao
	AveExotica::~AveExotica() {}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	AveExotica::print(std::ostream &o) {
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
		o << "Tamanho do bico: " << tamanho_bico << endl;
		o << "Envergadura: "<< envergadura << endl; 
		o << "Identificador do ibama: " << ibama << endl;
		o << "Pais de origem: " << pais_origem << endl; 
		return o;
	}	
}