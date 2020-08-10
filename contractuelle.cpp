#include <string>
#include "contractuelle.h"
#include <iostream>

Contractuelle::Contractuelle(std::string nom, int id, int mt, int nbSem) : Employes(nom, id) {
	this->montant = mt;
	this->nbSemaines = nbSem;
}

int::Contractuelle::getMontant() {
	return this->montant;
}

int::Contractuelle::getNbSemaines() {
	return this->nbSemaines;
}

double::Contractuelle::paieBrute() {
	return montant / nbSemaines;
}

double Contractuelle::tauxImpotFederal() {
	return paieBrute() * impotFederal;
}

double Contractuelle::tauxImpotProvincial() {
	return paieBrute() * impotProvincial;
}

double Contractuelle::total() {
	return paieBrute() - (tauxImpotFederal() + tauxImpotProvincial());
}