#ifndef __CONTRACTUELLE_H__
#define __CONTRACTUELLE_H__

#include <iostream>
#include "employes.h"

class Contractuelle : public Employes {
  private:
    int montant;
    int nbSemaines;
  public:
    Contractuelle(std::string nom, int id, int mt, int nbSem);
    int getMontant();
    int getNbSemaines();

    double paieBrute();
    double tauxImpotFederal();
    double tauxImpotProvincial();
    double total();
};

#endif