#ifndef __PONCTUELLE_H__
#define __PONCTUELLE_H__

#include <iostream>
#include "employes.h"

class Ponctuelle : public Employes {
  private:
    double montantUnique;
  public:
    Ponctuelle(std::string nom, int id, double mtUnique);
    int getMontantUnique();
    
    double paieBrute();
    double tauxImpotFederal();
    double tauxImpotProvincial();
    double total();
};

#endif