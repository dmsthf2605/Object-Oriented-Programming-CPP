#include <cstring>
#include <iostream>
#include "Contact.h"
using namespace std;

namespace sict{

	Contact::Contact(){
		setEmpty();
	}

	Contact::Contact(const char* name, int noPN){
		phoneNumber_ = new PhoneNumber[noPN];
		int i;
		for (i = 0; name[i] != '\0' && i < 40; i++){
			name_[i] = name[i];
		}
		name_[i] = '\0';
		_noPN = noPN;
	}

	//private member function
	void Contact::copy(const Contact& C){
		if (!C.isEmpty()){
			//copy name
			strncpy(name_, C.name_, 40);
			name_[40] = '\0';
			_noPN = C._noPN;
			
			//allocate dynamic memory
			phoneNumber_ = new PhoneNumber[_noPN];
			for (int i = 0; i < _noPN; i++){
				phoneNumber_[i] = C.phoneNumber_[i];
			}
		} else {
			this->setEmpty();
		}
	}

	//copy constructor
	Contact::Contact(const Contact& C){
			copy(C);
	}

	//Assignmnet Operator
	Contact& Contact::operator=(const Contact& C){
		if (this != &C){
			//deallocate previously allocated dynamic memory
			delete[] phoneNumber_;
			copy(C);	
		} 
		return *this;
	}

	void Contact::display()const{
		//display the name and go to new line
		cout << name_ << endl;

		// loop through elements of phoneNumber_ up to _noPN and display them one by one
		for (int i = 0; i < _noPN; i++){
			phoneNumber_[i].display(); 
		}

		// draw a 40 char line using '-' and go to new line
		cout << "----------------------------------------" << endl;
	}

	void Contact::read(){
		cout << "Contact Name: ";
		cin.getline(name_, 41, '\n');
		cout << "Please enter " << _noPN << " phone numbers: " << endl;
		for (int i = 0; i < _noPN; i++){
			cout << i + 1 << ": ";
			phoneNumber_[i].read();
		}
	}
	
	bool Contact::isEmpty()const{
		return phoneNumber_ == nullptr;
	}

	void Contact::setEmpty(){
		name_[0] = 0;
		_noPN = 0;
		phoneNumber_ = nullptr;// same as phoneNumber_ = (PhoneNumber*)0;
	}

	//deallocate the memory
	Contact::~Contact(){
		delete[] phoneNumber_;
	}
 
}