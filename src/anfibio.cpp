/** 
 * @file	anfibio.cpp
 * @brief	Implementacao das classe Anfibio, AnfibioNativo e
 *			AnfibioExotico
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	04/12/2017
 * @date 	07/12/2017
 */	


#include "anfibio.h"

#include <string>
using std::string;

#include <iostream>
using std::endl;


namespace PetFera {

	// Construtor padrao
	Anfibio::Anfibio() {}

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
	 * @param _total_mudas Total de mudas do anfibio
	 * @param _ultima_muda Ultima muda do anfibio
	 */
	Anfibio::Anfibio(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, 
	Tratador _tratador, string _batismo, int _total_mudas,string _ultima_muda): 
	Animal(_id, _classe, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario,
	_tratador, _batismo) {
		setTotal_mudas(_total_mudas);
		setUltima_muda(_ultima_muda);
	}

	// Destrutor padrao
	Anfibio::~Anfibio() {}

	/** @return Total de mudas do anfibio */
	int Anfibio::getTotal_mudas() {
		return total_mudas;
	}

	/** @return A ultima muda do anfibio */
	string Anfibio::getUltima_muda() {
		return ultima_muda;
	}

	/** @param _total_mudas Total de mudas do anfibio */
	void Anfibio::setTotal_mudas(int _total_mudas) {
		total_mudas = _total_mudas;
	}

	/** @param _ultima_muda Ultima muda do Anfibio */
	void Anfibio::setUltima_muda(string _ultima_muda) {
		ultima_muda = _ultima_muda;
	}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	Anfibio::print(std::ostream &o) {
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
		o << "Total mudas: " << total_mudas << endl;
		o << "Ultima muda: " << ultima_muda << endl; 
		return o;
	}

	
	// Contrutor padrao
	AnfibioNativo::AnfibioNativo() {}


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
	 * @param _total_mudas Total de mudas do anfibio
	 * @param _ultima_muda Ultima muda do anfibio
	 * @param _ibama Identificador do ibama
	 * @param _uf_origem UF de origem do anfibio
	 * @param _autorizacao Autorizacao do anfibio
	 */
	AnfibioNativo::AnfibioNativo(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
	string _batismo, int _total_mudas, string _ultima_muda, string _ibama, string _uf_origem, 
	string _autorizacao): Anfibio(_id, _classe, _nome, _cientifico, _sexo, _tamanho, _dieta,
	_veterinario, _tratador, _batismo,_total_mudas, _ultima_muda), Nativo(_ibama, _uf_origem, _autorizacao) {}

	// Destrutor padrao
	AnfibioNativo::~AnfibioNativo() {}

	/** 
	 * @param o Referencia para stream de saida
	 * @return Referencia para Stream de saida
	 */
	std::ostream& 
	AnfibioNativo::print(std::ostream &o) {
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
		o << "Total mudas: " << total_mudas << endl;
		o << "Ultima muda: " << ultima_muda << endl; 
		o << "Identificador do ibama: " << ibama << endl;
		o << "Uf de origem: " << uf_origem << endl;
		o << "Autorizacao: " << autorizacao << endl; 
		return o;
	}


	// Construtor padrao
	AnfibioExotico::AnfibioExotico() {}

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
	 * @param _total_mudas Total de mudas do anfibio
	 * @param _ultima_muda Ultima muda do anfibio
	 * @param _ibama Identificador do ibama
	 * @param _pais_origem Pais de origem do anfibio
	 */
	AnfibioExotico::AnfibioExotico(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario, Tratador _tratador,
	string _batismo, int _total_mudas, string _ultima_muda, string _ibama , string _pais_origem) :
	Anfibio(_id, _classe, _nome, cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador,
	_batismo, _total_mudas, ultima_muda), Exotico(_ibama, _pais_origem) {}

	// Destrutor padrao
	AnfibioExotico::~AnfibioExotico() {}

	std::ostream& 
	AnfibioExotico::print(std::ostream &o) {
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
		o << "Total mudas: " << total_mudas << endl;
		o << "Ultima muda: " << ultima_muda << endl; 
		o << "Identificador do ibama: " << ibama << endl;
		o << "Pais de origem: " << pais_origem << endl; 
		return o;
	}
}