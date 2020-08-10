#include <iostream>
#include "employes.h"
#include "syndiquee.h"
#include "contractuelle.h"
#include "ponctuelle.h"

using namespace std;

int answer;
int i = 0;
Employes **es = new Employes*[250];
  
void createSyndiquee() {
  int id;
  std::string nom;
  double nbHeures, salHoraire;
  bool valid = false;

  cout << "Entrez votre nom de Famille:" << endl;
  cin >> nom;

  while(!valid) {
    cout << "Entrez votre id:" << endl;
    cin >> id;

    if (id < 10000 || id > 99999) {
      std::cout << "Erreur! Veuillez entrer un numero d'identification entre 10000 et 99999!" << endl;
      continue;
    }
    
    valid = true;
  }
  
  cout << "Enter number of worked hours:" << endl;
  cin >> nbHeures;

  cout << "Enter salary per hour:" << endl;
  cin >> salHoraire;

  es[i++] = new Syndiquee(nom, id, nbHeures, salHoraire);
}

void createContractuelle() {
  int montant, semaines, id;
  std::string nom;
  bool valid = false;

  cout << "Entrez votre nom de Famille:" << endl;
  cin >> nom;

  while(!valid) {
    cout << "Entrez votre id:" << endl;
    cin >> id;

    if (id < 10000 || id > 99999) {
      std::cout << "Erreur! Veuillez entrer un numero d'identification entre 10000 et 99999!" << endl;
      continue;
    }

    valid = true;
  }

  cout << "Enter fixed amount paid:" << endl;
  cin >> montant;

  cout << "Enter how many weeks worked:" << endl;
  cin >> semaines;

  es[i++] = new Contractuelle(nom, id, montant, semaines);
}

void createPonctuelle() {
  int id;
  std::string nom;
  double montant;
  bool valid = false;

  cout << "Entrez votre nom de Famille:" << endl;
  cin >> nom;

  while(!valid) {
    cout << "Entrez votre id:" << endl;
    cin >> id;

    if (id < 10000 || id > 99999) {
      std::cout << "Erreur! Veuillez entrer un numero d'identification entre 10000 et 99999!" << endl;
      continue;
    }

    valid = true;
  }
  
  cout << "Enter the montant paid:" << endl;
  cin >> montant;

  es[i++] = new Ponctuelle(nom, id, montant);
}

void print() {
  double totauxBrute = 0;
  double totauxCA = 0;
  double totauxQC = 0;

  for(int j = 0; j < i; j++) {
    Employes* e = es[j];
    cout << e->getNom() + " " + std::to_string(e->getId()) << endl;
    cout << " Paie brute de " << e->paieBrute() << " $" << endl;
    cout << " Impots CA de " << e->tauxImpotFederal() << " $" << endl;
    cout << " Impots QC de " << e->tauxImpotProvincial() << " $" << endl;
    cout << " Paie nette de " << e->total() << " $" << endl;

    totauxBrute += e->paieBrute();
    totauxCA += e->tauxImpotFederal();
    totauxQC += e->tauxImpotProvincial();
  }

  cout << "\nTotaux" << endl;
  cout << " Montants totaux verses de " << totauxBrute << " $" << endl;
  cout << " Imports a transferer CA de " << totauxCA << " $" << endl;
  cout << " Imports a transferer QC de " << totauxQC << " $" << endl;
}

void retirerEmployee(int id) {
  for(int j = 0; j < i; ++j) {
    Employes* e = es[j];
    if(e->getId() == id) {
      for(int k = j; k < i; ++k) {
        es[k] = es[k+1];
      }
      delete es[i];
      --i;
      break;
    }
  }
}

void choix() {
  switch (answer) {
    case 1:
      createSyndiquee();
      break;
    case 2:
      createContractuelle();
      break;
    case 3:
      createPonctuelle();
      break;
    case 4:
      print();
      break;
    case 5:
      int id;
      cout << "Entrez l'identifiant à supprimer" << endl;
      cin >> id;
      retirerEmployee(id);
      break;
    default:
      cout << "Vous avez quitté\n";
  }
}
 
int main()
{
  bool choixListe = true;

  while (choixListe)
	{
		cout << "\nChoisissez une option de la liste ci-dessous:\n\n 1. Ajouter unE employéE syndiquéE\n\n 2. Ajouter unE employéE contractuelLE\n\n 3. Ajouter unE employéE ponctuelLE\n\n 4. Afficher le résultat de la paie\n\n 5. Retirer un employé\n\n 6. Quitter" << endl;
		cin >> answer;

		choix();
		
		if (answer < 1 || answer > 6)
			choixListe = false;
		else
			choixListe = true;
	}

  return 0;
} 
