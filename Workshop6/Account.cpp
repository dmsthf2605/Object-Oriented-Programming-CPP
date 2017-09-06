#include <iomanip>
#include <cstring>
#include "Account.h"
using namespace std;
namespace sict{
	Account::Account(){
		name_[0] = 0;
		balance_ = 0;
	}

	Account::Account(double balance){
		name_[0] = 0;
		balance_ = balance;
	}

	Account::Account(const char* name, double balance){
		strncpy(name_, name, 40);
		name_[40] = 0;
		balance_ = balance;
	}

	void Account::display(bool gotoNewline)const{
		cout << (name_[0] ? name_ : "No Name") << ": $" << setprecision(2) << fixed << balance_;
		if (gotoNewline) cout << endl;
	}

	Account::operator double() const{
		return balance_;
	}

	Account& Account::operator+=(const Account& c){
		balance_ += c.balance_;
		return *this;
	}

	Account& Account::operator=(const char* name){
		strncpy(this->name_, name, 40);
		name_[40] = 0;
		return *this;
	}

	/*Account operator+(const Account& b, const Account& c){
		double a;
		a = b.getBal() + c.getBal();
		return a;		
	}*/

	Account Account::operator+(const Account a) const{
		Account A;
		A.balance_ = balance_ + a.balance_;
		return A;
	}

	double Account::getBal() const{
		return balance_;
	}

	std::ostream& operator<<(std::ostream& cout, const Account& a){
		a.display(false);
		return cout;
	}
}