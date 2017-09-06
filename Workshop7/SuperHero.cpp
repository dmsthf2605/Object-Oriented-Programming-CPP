#include <cstring>
#include "SuperHero.h"

namespace sict{

	SuperHero::SuperHero(){
		multi_ = -100;
	}

	SuperHero::SuperHero(const char* name, double str, double multi) : Hero(name, str){
		if (multi < 0){
			multi_ = -100;
		} else {
			multi_ = multi;
		}	
	}

	SuperHero::SuperHero(const SuperHero& sh){
		std::strncpy(name_, sh.name_, 20);
		name_[20] = '\0';
		strength_ = sh.strength_;
		multi_ = sh.multi_;
	}

	double SuperHero::getStrength(){
		return strength_ * multi_;
	}

	void SuperHero::operator*=(SuperHero & sh){
		if (strength_ > sh.strength_){
			strength_ += sh.strength_;
			sh.strength_ = -100;			
		} else {		
			sh.strength_ += strength_;
			strength_ = -100;
		}
	}

	void SuperHero::display(std::ostream& os) const{
		if (strength_ <= 0){
			os << " the decreased superhero!" << std::endl;
		} else {
			os << "living superhero!";
			Hero::display(os);
		}
	}
}