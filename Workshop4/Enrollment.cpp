/* Feb 15/2016(Mon)
workshop 4 at_home
EUNSOL LEE
029-557-154
*/

#include <iostream>
#include <cstring>
#include "Enrollment.h"
using namespace std;

namespace sict{

	Enrollment::Enrollment(){ // sets the object to a safe empty state
		setEmpty();
	}

	Enrollment::Enrollment(const char* name, const char* code, int year, int semester, int time){
		set(name, code, year, semester, time);
	}

	bool Enrollment::isValid()const{
		return name_ && name_[0];
	}

	void Enrollment::setEmpty(){
		name_[0] = 0;
		code_[0] = 0;
		year_ = 0;
		semester_ = 0;
		slot_ = 0;
		enrolled_ = false;
	}

	bool Enrollment::isEnrolled() const{
		return enrolled_;
	}

	void Enrollment::display(bool nameOnly)const{
		if (isValid()){
			cout << name_;
			if (!nameOnly){
				cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
				cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
			}
		}
		else{
			cout << "Invalid enrollment!" << endl;
		}
	}

	void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled){
		if (name == 0 || code == 0 || name[0] == 0 || code[0] == 0 || year < 2015 || semester <= 0 || semester >= 4 || time <= 0 || time >= 6){
			setEmpty();
		}
		else {
			strcpy(name_, name);
			strcpy(code_, code);
			year_ = year;
			semester_ = semester;
			slot_ = time;
			enrolled_ = enrolled;
		}
	}

	bool Enrollment::hasConflict(const Enrollment &other) const{
		if (isValid() || other.isValid()){
			if (year_ == other.year_ && semester_ == other.semester_ && slot_ == other.slot_){
				return true;
			}
		}
		return false;
	}

	void Enrollment::withdraw(){
	// withdraws the student from the course and display an appropriate message
		enrolled_ = false;	
	}

	int Enrollment::enrol(const Enrollment* enrollments, int size){
		for(int i = 0; i < size; i++){
			if(hasConflict(enrollments[i]) == true){
				enrolled_ = false;
				return i + 1;
			}
		}

		enrolled_ = true;
		return 0;
	}
}
