#include <string>
#include "ponctuelle.h"
#include <iostream>

Ponctuelle::Ponctuelle(std::string nom, int id, double mtUnique) : Employes(nom, id) {
	this->montantUnique = mtUnique;
}

double::Ponctuelle::paieBrute() {
	return this->montantUnique;
}

double Ponctuelle::tauxImpotFederal() {
	return paieBrute() * impotFederal;
}

double Ponctuelle::tauxImpotProvincial() {
	return paieBrute() * impotProvincial;
}

double Ponctuelle::total() {
	return paieBrute() - (tauxImpotFederal() + tauxImpotProvincial());
}
