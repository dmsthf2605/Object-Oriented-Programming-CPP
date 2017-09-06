// EUNSOL LEE 029-557-154
/*Weather.cpp*/
//  includes go here

#include <iostream>
#include <iomanip>
using namespace std;
#include "Weather.h"

namespace sict{
	// set method 
	void Weather::set(const char* date_description, double high, double low){
		strcpy(_date, date_description);
		_high = high;
		_low = low;
	}

	// date method (query)
	const char* Weather::date() const{
		return _date;
	}

	// low method (query)
	double Weather::low() const{
		return _low;
	}

	// display
	void Weather::display() const{
		cout << fixed << setw(10) << left << setfill('_') << _date
			 << setprecision(1) << setw(6) << right << _high
			 << setw(6) << _low << endl;
	}

} //namespace sict
