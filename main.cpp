#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include "bibliotheque_cours.hpp"
#include <vector>
#include "VilainHeros.hpp"
#include <iostream>
using namespace std;

ifstream ouvrirFichierBinaire(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	return fichier;
}

void testsPourCouvertureLectureBinaire()
{
	istringstream iss("\xA0\x12\xA1\x21\x43\xA2\x98\xBA\xDC\xFE");
	assert(lireUintTailleVariable(iss) == 0x12);
	assert(lireUintTailleVariable(iss) == 0x4321);
	assert(lireUintTailleVariable(iss) == 0xFEDCBA98);
}


Vilain lireVilain(ifstream& fichierBinaire) 
{
	string nom = lireString(fichierBinaire);
	string jeuParution = lireString(fichierBinaire);
	string objectif = lireString(fichierBinaire);



	Vilain vilain(nom, jeuParution, objectif);
	return vilain;
}

void vilain(vector<Vilain>& vVilain, ifstream& fichierBinaire) 
{

	int taille = lireUintTailleVariable(fichierBinaire);

	for (int i= 0; i < taille; i++) {
		vVilain.push_back(lireVilain(fichierBinaire));
	}
}


Heros lireHeros(ifstream& fichierBinaire) 
{
	vector <string> alies;
	string nom= lireString(fichierBinaire);
	string jeuParution= lireString(fichierBinaire);
	string ennemi= lireString(fichierBinaire);
	
	int nAlies= lireUintTailleVariable(fichierBinaire);

	
	
	for (int i= 0; i < nAlies; i++) 
	{
		alies.push_back(lireString(fichierBinaire));
	}

	Heros hero(nom,jeuParution,ennemi,alies);

	return hero;
}



void heros(vector<Heros>& vHeros, ifstream& fichierBinaire) 
{
	
	int taille = lireUintTailleVariable(fichierBinaire);

	for (int i = 0; i < taille; i++) {
		heros.push_back(lireHeros(fichierBinaire));
	}
}




int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	testsPourCouvertureLectureBinaire();

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros("heros.bin" , ios::binary);
	ifstream fichierVilains("vilains.bin" , ios::binary);

	//TODO: Votre code pour le main commence ici (mais vous pouvez aussi ajouter/modifier du code avant si nécessaire)
	
	vector <Heros> vHeros;
	vector <Vilain> vVilain;
	vector <shared_ptr <Personnage> > vPersonnage;
	


	vilain(vVilain, fichierVilains);
	heros(vHeros, fichierHeros);
	
	VilainHeros vilainHeros(vHeros[5], vVilain[2]);
	




	for (int i = 0; i < vHeros.size(); i++) 
	{
		vHeros[i].changerCouleur(cout, "32");
		vHeros[i].afficher(cout);
		vHeros[i].changerCouleur(cout, "0");
		cout << "═══════════════════════════════════════════════════════════════"<< "\n";
			
	}


	for (int i = 0; i < vVilain.size(); i++) 
	{
		vVilain[i].changerCouleur(cout, "95");
		vVilain[i].afficher(cout);
		vVilain[i].changerCouleur(cout, "0");
		cout << "═══════════════════════════════════════════════════════════════" << "\n";
	}

	
	

	
	
	
	
	for (int i = 0; i < vHeros.size(); i++) 
	{
		vPersonnage.push_back(make_unique <Heros> (vHeros[i]));
	}
	
	
	for (int i = 0; i < vVilain.size(); i++) 
	{
		vPersonnage.push_back(make_unique <Vilain> (vVilain[i]));
	}


	vPersonnage.push_back(make_unique <VilainHeros> (vilainHeros));
	

	
	for (int i = 0; i < vPersonnage.size(); i++) 
	{

		vPersonnage[i]->afficher(cout);

	}

}
