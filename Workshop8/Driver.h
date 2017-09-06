/* EUNSOL LEE
March 22, 2016
029-557-154
*/


#ifndef SICT_DRIVER_H_
#define SICT_DRIVER_H_
#include "Car.h"
namespace sict{
  class Driver{
	  char name_[31];
	  Car& car_;

  public:
	  Driver(const char*, Car&);
	  void drive();
	  void stop();
	  void showStatus();
	  
  };
}
#endif