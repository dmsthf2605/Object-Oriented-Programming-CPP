#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"
#include "general.h"

namespace sict{

	//returns value is used to compare two dates
	int Date::value()const{
		return year_ * 372 + mon_ * 31 + day_;
	}

	//returns the day of the month
	int Date::mdays()const{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}

	//sets the _readErrorCode member variable to one of the possible values
	void Date::errCode(int errorCode){
		readErrorCode_ = errorCode;
	}

	//validate the range and set the readErrorCode_
	void Date::validate(){
		if (year_ < MIN_YEAR || year_ > MAX_YEAR){
			readErrorCode_ = YEAR_ERROR;
		} else if (mon_ < 1 || mon_ > 12){
			readErrorCode_ = MON_ERROR;
		} else if (day_ < 1 || day_ > mdays()){
			readErrorCode_ = DAY_ERROR;
		} else {
			readErrorCode_ = NO_ERROR;
		}
	}

	//No argument constructor
	Date::Date(){
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;
	}

	Date::Date(int year, int mon, int day){
		year_ = year;
		mon_ = mon;
		day_ = day;		
		readErrorCode_ = NO_ERROR;
	}

	bool Date::operator==(const Date& D)const{
		return value() == D.value();
	}

	bool Date::operator!=(const Date& D)const{
		return value() != D.value();
	}

	bool Date::operator<(const Date& D)const{
		return value() < D.value();
	}

	bool Date::operator>(const Date& D)const{
		return value() > D.value();
	}

	bool Date::operator<=(const Date& D)const{
		return value() <= D.value();
	}

	bool Date::operator>=(const Date& D)const{
		return value() >= D.value();
	}

	int Date::errCode() const { 
		return readErrorCode_; 
	}

	bool Date::bad()const { 
		return readErrorCode_ != 0;
	}

	//YYYY?MM?DD e.g.2016/03/24 or 2016-03-24
	std::istream& Date::read(std::istream& istr){
		char c; //store ? e.g. "/" or "-"
		istr >> year_;
		istr >> c;
		if (istr.fail()){
			readErrorCode_ = CIN_FAILED;
			return istr;
		} 
		istr >> mon_;
		istr >> c;
		if (istr.fail()){
			readErrorCode_ = CIN_FAILED;
			return istr;
		}
		istr >> day_;
		//when the numbers are successfully read in
		validate();
		return istr;
	}

	//YYYY/MM/DD 
	std::ostream& Date::write(std::ostream& ostr)const{
		ostr << year_ << "/";
		if (mon_ < 10){
			ostr << "0";
		}
		ostr << mon_ << "/";
		if (day_ < 10){
			ostr << "0";
		}
		ostr << day_;
		return ostr;
	}

	std::istream& operator>>(std::istream& is, Date& d){
		return d.read(is);
	}

	std::ostream& operator<<(std::ostream& os, const Date& d){
		return d.write(os);
	}

}
