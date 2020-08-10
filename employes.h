#ifndef __EMPLOYES_H__
#define __EMPLOYES_H__

#include <string>

class Employes {
public:
  const double impotFederal = 0.15;
  const double impotProvincial = 0.15;
  int id;
  int getId();
  std::string nom;
  std::string getNom();

  Employes(std::string nom, int id);
  virtual ~Employes() = default;

  virtual double paieBrute() = 0;
  virtual double tauxImpotFederal() = 0;
  virtual double tauxImpotProvincial() = 0;
  virtual double total() = 0;
};

#endif