#include <string>
#include "Personnage.hpp"
#include <vector>
using namespace std;


class Vilain: virtual public Personnage {

public:
	Vilain(string nom, const string& jeuParution,const string& objectif) : Personnage(nom, jeuParution), objectif_(objectif) {}

	const string& getObjectif() const 
	{
		return objectif_;
	}

	ostream& afficher(ostream& os) 
	{
		Personnage::afficher(os);
		os << "objectif: " << objectif_ << endl;

		return os;
	}



private:

	string objectif_;
};