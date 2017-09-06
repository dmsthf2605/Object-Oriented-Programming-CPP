#ifndef SICT_HERO_H__
#define SICT_HERO_H__
#include <iostream>

namespace sict{
	class Hero{
	protected:
		char name_[21];
		double strength_;

	public:
		Hero();
		Hero(const char*, double);
		bool isEmpty() const;
		double getStrength() const;
		void display(std::ostream&) const;		
		void operator-=(double strength);
		void operator+=(double strength);
	};
	
	bool operator<(const Hero&, const Hero&);
}
#endif
