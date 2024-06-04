#include "VilainHeros.hpp"
using namespace std;




ostream&  VilainHeros::afficher(ostream& os)
{
	
	Personnage::afficher(os);
	
	os << "l'objectif: " << getObjectif() << endl << "l'ennemi: " << getEnnemi() << endl << "la liste d'ali�s:" << endl;

	
	for (const auto& it: getAlies())
	{
		os << "\t" << it << endl;
	}

	os << "la mission sp�ciale est : " << missionSpeciale_ << endl;



	return os;

}