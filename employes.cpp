
#include <iostream>
#include <string>
#include "employes.h"

Employes::Employes(std::string nom, int id) {
	this->nom = nom;
	this->id = id;
}

std::string Employes::getNom() {
	return this->nom;
}

int Employes::getId() {
	return this->id;
}
