#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
namespace sict{
	class Account{
		char name_[41];
		double balance_;

	public:
		Account();
		Account(double balance);
		Account(const char name[], double balance = 0.0);
		void display(bool gotoNewline = true)const;
		Account& operator+=(const Account&);
		Account& operator=(const char* name);
		Account operator+(const Account)const;
		operator double() const;
		double getBal() const;
	};

	//Account operator+(const Account& b, const Account& c);
	std::ostream& operator<<(std::ostream&, const Account&);

};

#endif
