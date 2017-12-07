/** 
 * @file	animal.c
 * @brief	Implementacao da classe Animal para representar
 *			um animal
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	03/12/2017
 * @date 	07/12/2017
 */	


#include "animal.h"

#include <string>
using std::string;


namespace PetFera {

	// Construtor padrao
	Animal::Animal() {}

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
	 */
	Animal::Animal(int _id, string _classe, string _nome, string _cientifico,
	char _sexo, float _tamanho, string _dieta, Veterinario _veterinario,
	Tratador _tratador, string _batismo) {
		setId(_id);
		setClasse(_classe);
		setNome(_nome);
		setCientifico(_cientifico);
		setSexo(_sexo);
		setTamanho(_tamanho);
		setDieta(_dieta);
		setVeterinario(_veterinario);
		setTratador(_tratador);
		setBatismo(_batismo);
	}

	//	Destrutor padrao
	Animal::~Animal() {}

	/** @return Identificador do animal */
	int Animal::getId() {
		return id;
	}

	/** @return Classe do animal */
	string Animal::getClasse() {
		return classe;
	}

	/** @return Nome do animal */
	string Animal::getNome() {
		return nome;
	}

	/** @return Nome cientifco do animal */
	string Animal::getCientifico() {
		return cientifico;
	}

	/** @return Sexo do animal */
	char Animal::getSexo() {
		return sexo;
	}

	/** @return Tamanho do animal */
	float Animal::getTamanho() {
		return tamanho;
	}

	/** @return Dieta do animal */
	string Animal::getDieta() {
		return dieta;
	}

	/** @return Veterinario do animal */
	Veterinario Animal::getVeterinario() {
		return veterinario;
	}

	/** @return Dieta do animal */
	Tratador Animal::getTratador() {
		return tratador;
	}

	/** @return Nome de batismo do animal */
	string Animal::getBatismo() {
		return batismo;
	}

	/** @param _id Identificador do animal */
	void Animal::setId(int _id) {
		id = _id;
	}

	/** @param _classe Classe do animal */
	void Animal::setClasse(string _classe) {
		classe = _classe;
	}

	/** @param _nome Nome do animal */
	void Animal::setNome(string _nome) {
		nome = _nome;
	}

	/** @param _cientifico Nome cientifco do animal */
	void Animal::setCientifico(string _cientifico) {
		cientifico = _cientifico;
	}

	/** @param _sexo Sexo do animal */
	void Animal::setSexo(char _sexo) {
		sexo = _sexo;
	}

	/** @param _tamanho Tamanho do animal */
	void Animal::setTamanho(float _tamanho) {
		tamanho = _tamanho;
	}

	/** @param _dieta Dieta do animal */
	void Animal::setDieta(string _dieta) {
		dieta = _dieta;
	}
	
	/** @param _veterinario Veterinario do animal */
	void Animal::setVeterinario(Veterinario _veterinario) {
		veterinario = _veterinario;
	}
	
	/** @param _tratador Tratador do animal */
	void Animal::setTratador(Tratador _tratador) {
		tratador = _tratador;
	}

	/** @param _batismo Nome de batismo do animal */
	void Animal::setBatismo(string _batismo) {
		batismo = _batismo;
	}

	/** 
 	 * @param o Referencia para stream de saida
 	 * @param p Referencia para um objeto Animal
 	 * @return Referencia para stream de saida
 	 */
	std::ostream& operator<< (std::ostream &o, Animal &a) {
		return a.print(o);
	}

	/** 
 	 * @param p Referencia para um objeto Animal
  	 * @return True ou false 
 	 */
	bool Animal::operator==(const Animal &a) {
		if(id == a.id) {
			return true;
		}
		else {
			return false;
		}
	}
}