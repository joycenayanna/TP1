#include <iostream>
#include <string>
#include "syndiquee.h"

Syndiquee::Syndiquee(std::string nom, int id, double nh, double sal) : Employes(nom, id) {
	this->nbHeures = nh;
	this->salHoraire = sal;
}

// Implémentation du "getter"
double::Syndiquee::getNbHeures() {
	return this->nbHeures;
}

// Implémentation du "getter"
double::Syndiquee::getSalHoraire() {
	return this->salHoraire;
}

void::Syndiquee::setNbHeures(double nbHr) {
	this-> nbHeures = nbHr;
}

void::Syndiquee::setSalHoraire(double salHr) {
	this-> salHoraire = salHr;
}

double::Syndiquee::paieBrute() {
	double payeBrute = nbHeures * salHoraire;
	return payeBrute;
}

double Syndiquee::tauxImpotFederal() {
	return paieBrute() * impotFederal;
}

double Syndiquee::tauxImpotProvincial() {
	return paieBrute() * impotProvincial;
}

double Syndiquee::total() {
	return paieBrute() - (tauxImpotFederal() + tauxImpotProvincial());
}