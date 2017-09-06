/* EUNSOL LEE
March 22, 2016
029-557-154
*/

#include "Car.h"
namespace sict{

	// sets the speed_ attribute
	void Car::speed(int value){
		if (value > maxSpeed_){
			speed(maxSpeed_);
		} else if (value < 0){
			speed_ = 0;
		} else
			speed_ = value;
	}

	// returns maxSpeed_
	int Car::maxSpeed()const{
		return maxSpeed_;
	}

	// returns speed_
	int Car::speed() const{
		return speed_;
	}

	// constructor
	Car::Car(int max){
		maxSpeed_ = max;
		speed_ = 0;
	}

	std::ostream& operator<< (std::ostream& cout, const Car& c){
		c.display(cout);
		return cout;
	}

}