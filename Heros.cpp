using namespace std;
#include "Heros.hpp"




ostream& Heros::afficher(ostream& os) 
{
	
	Personnage::afficher(os);

	os << "Liste d'ali�s :" << endl;

	for (const auto& it : getAlies())
	{
		os << "\t" << it << endl;
	}


	return os;
}

