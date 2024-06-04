using namespace std;
#include <iostream>
#include <vector>
#include "Personnage.hpp"




class Heros : virtual public Personnage 
{

public:

	Heros(const string& nom, const string& jeuParution, const string& ennemi, vector<string> alies) : Personnage(nom, jeuParution), ennemi_(ennemi), alies_(alies) {};


	const string& getEnnemi() const {
		return ennemi_;
	};

	
	vector<string> getAlies() const {
		return alies_;
	}

	
	ostream& afficher(ostream& os);

private:

	string ennemi_;
	vector<string> alies_;

};


