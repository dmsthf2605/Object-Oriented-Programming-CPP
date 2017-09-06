/* EUNSOL LEE
March 22, 2016
029-557-154
*/
#include "SportCar.h"

namespace sict{

	// constructors
	SportCar::SportCar() : Car(){
		noOfPassengers_ = 1;
	}
	SportCar::SportCar(int max, int noOfP) : Car(max){
		noOfPassengers_ = noOfP;
	}

	//Adds 40 kilometers
	void SportCar::accelerate(){
		speed(speed() + 40);
	}

	//Redueces the speed by 10 kilometers
	void SportCar::brake(){
		speed(speed() - 10);
	}

	std::ostream& SportCar::display(std::ostream& ostr) const{
		int s = speed();
		if (s > 0){
			ostr << "This sport car is carrying " << noOfPassengers_
				<< " passengers and is traveling at a speed of "
				<< s << " km/h.";
		} else if (s == 0){
			ostr << "This sport car is carrying " << noOfPassengers_
				<< " passengers and is parked.";
		}

		return ostr;
	}


}