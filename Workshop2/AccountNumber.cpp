// OOP244 Workshop 2: Compound types and privacy
// File	???????
// Version 1.0
// Date	???????????
// Author	?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// EUNSOL LEE           2/1/2016 
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict{
  // member functions' (methods') definition go here
	void AccountNumber::name(const char name[]){
		strcpy(_name, name);
	}

	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber){
		if (bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE &&
			branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE &&
			accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO){
			_validAccNumber = true;
		}
		else {
			_validAccNumber = false;
		}

		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accountNumber;
	}

	void AccountNumber::display(bool display_name, bool display_number) const{
		if(isValid()){
			if (display_name && display_number){
				cout << "Name: " << _name << ", Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;
			} else if (display_name == false && display_number){
				displayNumber();
				cout << endl;
			} else if (display_name && display_number == false){
				displayName();
				cout << endl;
			} else if (display_name == false && display_number == false){
			
			} 
		} else {
			cout << _name << " does not have a valid account number." << endl;
		}
	}

	bool AccountNumber::isValid() const{
		return _validAccNumber;
	}

	void AccountNumber::displayName() const{
		cout << "Name: " << _name;
	}

	void AccountNumber::displayNumber() const{
		cout << "Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber;
	}

}
