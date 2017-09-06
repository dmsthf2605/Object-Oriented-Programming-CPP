#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_
#include "PhoneNumber.h"
namespace sict{

	class Contact{
		char name_[41];
		PhoneNumber* phoneNumber_;
		int _noPN;
		void setEmpty();
		void copy(const Contact& C);

	public:
		Contact();
		Contact(const char*, int);
		Contact(const Contact&);
		Contact& operator=(const Contact&);
		~Contact();
		void read();
		void display()const;
		bool isEmpty()const;
	};

}

#endif