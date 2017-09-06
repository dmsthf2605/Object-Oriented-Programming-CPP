#ifndef SICT_SUPERHERO_H__
#define SICT_SUPERHERO_H__
#include <iostream>
#include "Hero.h"

namespace sict{

	class SuperHero : public Hero{
		double multi_;

	public:
		SuperHero();
		SuperHero(const char*, double, double);
		SuperHero(const SuperHero&);
		double getStrength();
		void operator*=(SuperHero &);
		void display(std::ostream&) const;
	};

}
#endif
