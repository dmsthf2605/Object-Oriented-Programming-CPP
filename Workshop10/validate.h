/*
2016-04-10
EUNSOL LEE
029-557-154
*/

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <typeinfo>

namespace sict{
	template <typename T>
	bool validate(const T& minimum, const T& maximum, const T testValue[], int num, bool* validation){
		bool valid = true;

		for (int i = 0; i < num; i++){
			if (testValue[i] >= minimum && maximum >= testValue[i]){
				validation[i] = true;
			} else {
				validation[i] = false;
				valid = false;
			} //for()
		}	
		return valid;
	}

	// template specialization. character validation is not case sensitive
	template <>
	bool validate<char>(const char& minimum, const char& maximum, const char testValue[], int num, bool* validation){
		bool valid = true;
		
		for (int i = 0; i < num; i++){
			char current = toupper(testValue[i]);
			if (current >= minimum && maximum >= current){
				validation[i] = true;
			}
			else {
				validation[i] = false;
				valid = false;
			} //for()
		}
		return valid;
	}

	// template specialization.
	// any license plate that is not 6 letters is tagged as invalid 
	template <>
	bool validate<Car>(const Car& minimum, const Car& maximum, const Car testValue[], int num, bool* validation){
		bool valid = true;
		int c = 0; // check the length of plate

		for (int i = 0; i < num; i++){
			c = strlen(testValue[i]);
			if (testValue[i] >= minimum && maximum >= testValue[i]){
				validation[i] = true;
			} else {
				validation[i] = false;
				valid = false;
			}
			if (c != 6){
				validation[i] = false;
				valid = false;
			}
		} //for()
		return valid;
	}
}
