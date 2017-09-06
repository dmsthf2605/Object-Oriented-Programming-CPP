/* EUNSOL LEE
March 22, 2016
029-557-154
*/

#include <iostream>
#include <cstring>
#include "Driver.h"
using namespace std;
namespace sict{

	// sets the name of the driver and initialize car_ with cRef
	Driver::Driver(const char* name, Car& cRef) : car_(cRef){
		std::strncpy(name_, name, 30);
		name_[30] = '\0';
	}
	
	void Driver::drive(){
		car_.accelerate();
		car_.brake();
		showStatus();
	}

	void Driver::stop(){
		while (car_.speed() > 0){
			car_.brake();
		}
		showStatus();
	}

	void Driver::showStatus(){
		cout << name_ << " is driving this car." << std::endl;
		cout << car_ << std::endl;
	}



}