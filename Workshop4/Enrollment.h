/* Feb 15/2016(Mon)
workshop 4 at_home
EUNSOL LEE
029-557-154
*/

#ifndef SICT_ENROLLMENT_H
#define SICT_ENROLLMENT_H

namespace sict{
	
	class Enrollment{
	private:
		char name_[31];
	   	char code_[11];
	   	int year_;
	    int semester_;
	    int slot_;
		bool enrolled_;
	
	public:
		Enrollment();
		Enrollment(const char*, const char*, int, int, int);
	    void display(bool nameOnly = false)const;
	    bool isValid()const;
	    void setEmpty();
	    bool isEnrolled() const;
		bool hasConflict(const Enrollment &other) const;
		void withdraw();
		int enrol(const Enrollment* enrollments, int size);
		void set(const char* name, const char* code, int year, int semester, int time, bool enrolled = false);
	};
}

#endif

