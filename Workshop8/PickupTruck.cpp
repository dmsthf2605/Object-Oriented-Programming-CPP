/* EUNSOL LEE
March 22, 2016
029-557-154
*/

#include <cstring>
#include "PickupTruck.h"
namespace sict{

	// constructor
	PickupTruck::PickupTruck(){
		loadAmount_ = 0;
		loadedMaterial_[0] = 0;
	}
	
	// sets the two correspoiding attributes
	void PickupTruck::load(const char* loadedMaterial, int loadAmount){
		loadAmount_ = loadAmount;
		std::strncpy(loadedMaterial_, loadedMaterial, 30);
		loadedMaterial_[30] = '\0';
	}
	
	// sets the loadAmmount_ to zero
	void PickupTruck::unload(){ 
		loadAmount_ = 0; 
	}
	
	// returns true if the loadAmmount_ is zero
	bool PickupTruck::isEmpty()const{ 
		return loadAmount_ == 0;
	}
	
	//Adds 20 kilometers
	void PickupTruck::accelerate(){
		speed(speed() + 20);
	}
	//Redueces the speed by 5 kilometers
	void PickupTruck::brake(){
		speed(speed() - 5);
	}

	std::ostream& PickupTruck::display(std::ostream& ostr) const{
		int s = speed();

		if (isEmpty()){
			ostr << "This pickup truck is not carrying any load";
		} else {
			ostr << "This pickup truck is carrying " << loadAmount_
				 << " kgs of " << loadedMaterial_;
		}

		if (s > 0){
			ostr << ", traveling at the speed of " << s
				<< " km/h.";
		} else if (s == 0){
			ostr << " and is parked.";
		}

		return ostr;
	}



}