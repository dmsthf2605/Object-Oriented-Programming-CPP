/* EUNSOL LEE
March 22, 2016
029-557-154
*/

#ifndef SICT_CAR_H_
#define SICT_CAR_H_
#include "Vehicle.h"

namespace sict{
  class Car : public Vehicle{
	  int speed_;
	  int maxSpeed_;

  protected:
	  void speed(int value);
	  int maxSpeed()const;
  
  public:
	  int speed() const;
	  Car(int max = 100);
  }; 

  std::ostream& operator<< (std::ostream&, const Car&);

}

#endif