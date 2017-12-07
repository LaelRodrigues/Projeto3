/** 
 * @file	reptil.cpp
 * @brief	Implementacao das classes Reptil, ReptilNativo e
 *			ReptilExotico
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	06/12/2017
 * @date 	07/12/2017
 */	


#include "reptil.h"

#include <string>
using std::string;

#include <iostream>
using std::endl;

namespace PetFera {

	// Construtor padrao
	Reptil::Reptil() {}

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
	 * @param _venenoso Indicacao se o reptil e venenoso ou nao
	 * @param _tipo_veneno Tipo de veneno do reptil
	 */
	Reptil::Reptil(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
	Tratador _tratador, string _batismo, bool _venenoso, string _tipo_veneno): 
	Animal(_id, _classe, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario,
	_tratador, _batismo) {
		setVenenoso(_venenoso);
		setTipo_veneno(_tipo_veneno);
	}

	// Destrutor padrao
	Reptil::~Reptil() {}

	/** @return true se o reptil e venenoso e false caso contrario */
	bool Reptil::getVenenoso() {
		return venenoso;
	}

	/** @return O tipo de veneno do reptil */
	string Reptil::getTipo_veneno() {
		return tipo_veneno;
	}

	/** @param _venenoso Indicacao se o reptil e venenoso ou nao */
	void Reptil::setVenenoso(bool _venenoso) {
		venenoso = _venenoso;
	}

	/** @param _tipo_veneno Tipo de veneno do reptil */
	void Reptil::setTipo_veneno(string _tipo_veneno) {
		tipo_veneno = _tipo_veneno;
	}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	Reptil::print(std::ostream &o) {
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
		o << "venenoso: ";
		if(venenoso == true) o << "sim" << endl;
		else o << "nao" << endl;
		o << "Tipo do veneno" << tipo_veneno << endl;
		return o;
	}


	// Contrutor padrao
	ReptilNativo::ReptilNativo() {}

	/**
	 * @param _id Identificador do animal
	 * @param _classe Classe do animal
	 * @param _nome Nome do animal
	 * @param _cientifico Nome cientifico do animal
	 * @param _sexo Sexo do animal
	 * @param _tamanho Tamanho do animal
	 * @param _dieta Dieta do animal
	 * @param _batismo Nome de batismo do animal
	 * @param _veterinario Veterinario do animal
	 * @param _tratador Tratador do animal
	 * @param _venenoso Indicacao se o reptil e venenoso ou nao
	 * @param _tipo_veneno Tipo de veneno do reptil
	 * @param _ibama Identificador do ibama
	 * @param _uf_origem UF de origem do reptil
	 * @param _autorizacao Autorizacao do reptil
	 */
	ReptilNativo::ReptilNativo(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
	string _batismo, bool _venenoso, string _tipo_veneno, string _ibama, string _uf_origem,
	string _autorizacao) : Reptil(_id, _classe, _nome, _cientifico, _sexo, _tamanho, _dieta,
	_veterinario, _tratador, _batismo, _venenoso, _tipo_veneno), Nativo(_ibama,_uf_origem, _autorizacao) {}

	// Destrutor padrao
	ReptilNativo::~ReptilNativo() {}	

	// Construtor padrao
	ReptilExotico::ReptilExotico() {}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	ReptilNativo::print(std::ostream &o) {
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
		o << "venenoso: ";
		if(venenoso == true) o << "sim" << endl;
		else o << "nao" << endl;
		o << "Tipo do veneno" << tipo_veneno << endl;
		o << "Identificador do ibama: " << ibama << endl;
		o << "Uf de origem: " << uf_origem << endl;
		o << "Autorizacao: " << autorizacao << endl; 
		return o;
	}


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
	 * @param _venenoso Indicacao se o reptil e venenoso ou nao
	 * @param _tipo_veneno Tipo de veneno do reptil
	 * @param _ibama Identificador do ibama
	 * @param _pais_origem Pais de origem do reptil
	 */
	ReptilExotico::ReptilExotico(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
	string _batismo, bool _venenoso, string _tipo_veneno, string _ibama , string _pais_origem):
	Reptil(_id, _classe, _nome, cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador,
	_batismo,_venenoso, _tipo_veneno), Exotico(_ibama, _pais_origem) {}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	ReptilExotico::print(std::ostream &o) {
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
		o << "venenoso: ";
		if(venenoso == true) o << "sim" << endl;
		else o << "nao" << endl;
		o << "Tipo do veneno" << tipo_veneno << endl;
		o << "Identificador do ibama: " << ibama << endl;
		o << "Pais de origem: " << pais_origem << endl; 
		return o;
	}

	// Destrutor padrao
	ReptilExotico::~ReptilExotico() {}
}