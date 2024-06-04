#pragma once
#include <string>
#include "Affichable.hpp"
#include <iostream>
using namespace std;

class Personnage : public  Affichable 
{

public:

	const string& getNom() const {
		return nom_;
	};

	const string& getjeuParution() const {
		return jeuParution_;
	};

	Personnage(const string& nom, const string& jeuParution) : nom_(nom), jeuParution_(jeuParution) {};

	virtual ostream& afficher(ostream& os);
	virtual ostream& changerCouleur(ostream& os, string couleur);

private:

	string nom_;
	string jeuParution_;

};
