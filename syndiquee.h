#ifndef __SYNDIQUEE_H__
#define __SYNDIQUEE_H__

#include <iostream>
#include "employes.h"

class Syndiquee : public Employes {
	private:
		double nbHeures;
		double salHoraire;
	public:
		Syndiquee(std::string nom, int id, double nh, double sal);

		double getNbHeures();
		double getSalHoraire();
		void setNbHeures(double nbHr);
		void setSalHoraire(double salHr);

		double paieBrute();
		double tauxImpotFederal();
		double tauxImpotProvincial();
    double total();
};

#endif // !__SYNDIQUEE_H__

