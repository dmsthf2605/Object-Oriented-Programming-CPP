#include <cstring>
#include "Hero.h"

namespace sict{

	Hero::Hero(){
		name_[0] = 0;
		strength_ = -100;
	}

	Hero::Hero(const char* name, double str){
		if(str < 0 || strlen(name) > 20 ){
			name_[0] = 0;
			strength_ = -100;
		} else {
			strncpy(name_, name, 20);
			name_[20] = '\0';
			strength_ = str;
		}
	}

	bool Hero::isEmpty() const{
		return name_[0] == 0;
	}

	double Hero::getStrength() const{
		if (isEmpty()){
			return 0.0;
		} else {
			return strength_;
		}
	}

	void Hero::display(std::ostream& os) const{
		os << name_ << " - " << strength_ << std::endl;
	}

	void Hero::operator-=(double strength){
		if (strength > strength_){
			strength_ = 0.0;
		} else {
			strength_ -= strength;
		}
	}

	void Hero::operator+=(double strength){
		strength_ += strength;
	}
	
	bool operator<(const Hero& a, const Hero& b){
		return a.getStrength() < b.getStrength();
	}
}
