#include"Vilain.hpp"
using namespace std;



ostream& Vilain::afficher(ostream& os) {
	

	Personnage::afficher(os);

	os << "objectif: " << objectif_ << endl;

	


	return os;
}