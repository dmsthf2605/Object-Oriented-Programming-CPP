// EUNSOL LEE 029-557-154
// compilation safegaurds
/*Weather.h*/

#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_

// sict namespace
namespace sict{

	class Weather{
		// member variables
		char _date[7];
		double _high;
		double _low;

	public:
		// member function
		void set(const char* date_description, double high, double low);
		void display() const;
		const char* date() const;
		double low() const;
	};

} //namesplace

#endif

