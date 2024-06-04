using namespace std; 
#include <string>
#include "Personnage.hpp"



ostream& Personnage::afficher(ostream& os) 
{
	os << "Nom : " << getNom() << endl << "jeu de parution : " << getjeuParution() << endl;

	return os;
}



ostream& Personnage::changerCouleur(ostream& os, string couleur)
{
	string affichageCouleur = "\033[" + couleur + "m"; //couleur est un string qui contient le code de la couleur \033[xm
	
	os << affichageCouleur;

	return sortie;

};