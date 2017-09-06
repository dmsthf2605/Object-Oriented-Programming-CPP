#include "ErrorMessage.h"
#include <cstring>
namespace sict{

	//Sets the message_ to nullptr
	ErrorMessage::ErrorMessage(){
		message_ = nullptr;
	}

	//Sets the message_ to nullptr and then uses the message() to set the errorMessage
	ErrorMessage::ErrorMessage(const char* errorMessage){
		message_ = nullptr;
		message(errorMessage);
	}

	//Sets the message_ to the errorMessage and returns to current object
	ErrorMessage& ErrorMessage::operator=(const char* errorMessage){
		clear();
		message(errorMessage);
		return *this;
	}

	//De-allocates the memory pointed by message_
	ErrorMessage::~ErrorMessage(){
		delete[] message_;
	}

	//de-allocates the memory pointed by message_ and then sets message_ to nullptr
	void ErrorMessage::clear(){
		delete[] message_;
		message_ = nullptr;
	}

	//Returns true if message_ is nullptr
	bool ErrorMessage::isClear()const{
		return message_ == nullptr;
	}

	//Sets the message_ of the ErrorMessage object to a new value
	void ErrorMessage::message(const char* value){
		delete[] message_;
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);
	}

	//return the address kept in message_
	const char* ErrorMessage::message()const{
		return message_;
	}

	//of ErrorMessage isClear, nothing should be printed, otherwise the c-string pointed by message_ is printed
	std::ostream& operator<<(std::ostream& os, const ErrorMessage& E){
		if (E.isClear()){
			return os;
		} else {
			return os << E.message();
		}
	}


}