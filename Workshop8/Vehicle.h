/* EUNSOL LEE
March 22, 2016
029-557-154
*/

#ifndef SICT_VEHICLE_
#define SICT_VEHICLE_
#include <iostream>

namespace sict{
  class Vehicle  {
  public:
	  virtual void accelerate() = 0;
	  virtual void brake() = 0;
	  virtual std::ostream& display(std::ostream& ostr) const = 0;
  };
}
#endif