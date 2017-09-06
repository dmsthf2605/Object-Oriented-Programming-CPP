#include "AmaPerishable.h"
using namespace std;

namespace sict{
	// default constructor
	// invokes the AmaProduct constructor passing the value 'P' for the fileTag argument
	AmaPerishable::AmaPerishable() : AmaProduct('P'){
		
	}

	// getter
	const Date& AmaPerishable::expiry()const{
		return expiry_;
	}

	// setter
	void AmaPerishable::expiry(const Date& value){
		expiry_ = value;
	}

	//re-implements all four virtual methods of the AmaProduct
	fstream& AmaPerishable::store(fstream& file, bool addNewLine)const{
		//Calls the parent's store passing the file and "false" as arguments
		AmaProduct::store(file, false);
		// writes comma and the expiry date in the file
		file << "," << expiry();
		//if addNewLine is ture add a newline
		if (addNewLine == true)
			file << endl;
		return file; // returns file
	}
	
	fstream& AmaPerishable::load(fstream& file){
		// calls the parent's load apssing the file as the argument
		AmaProduct::load(file);
		// calls the read methods of the expiry_ object passing the file as the argument
		expiry_.read(file);
		// ignores one character
		file.ignore();

		return file; // returns file
	}
	
	ostream& AmaPerishable::write(ostream& ostr, bool linear)const{
		// calls the write of the parent passing ostr and linear as arguments
		AmaProduct::write(ostr, linear);
		// if err_ is celar and product is not empty
		if (err_.isClear() && !isEmpty()){
			if (linear == true){
				ostr << expiry();
			} else {
				// go to newline first
				ostr << endl;
				ostr << "Expiry date: " << expiry();
				// NO NEW LINE
			}		
		}
		return ostr; // returns the ostr argument
	}
	
	istream& AmaPerishable::read(istream& istr){
		// temporary Date object
		Date d; 
		
		// calls parent's read passing istr as argument
		AmaProduct::read(istr);
		if (err_.isClear()){ // if err_ is clear
			cout << "Expiry date (YYYY/MM/DD): ";
			istr >> d;

			// if expiry (date) entry fails, set the error messgae in err_
			// depends on the error code stored in the Date object
			// call "istr.setstate(ios::failbit)" function to set the istr to failure mode
			if (d.errCode() == CIN_FAILED){
				err_.message("Invalid Date Entry");
				istr.setstate(ios::failbit);
				return istr;
			} else if(d.errCode() == YEAR_ERROR){
				err_.message("Invalid Year in Date Entry");
				istr.setstate(ios::failbit);
				return istr;
			} else if (d.errCode() == MON_ERROR){
				err_.message("Invalid Month in Date Entry");
				istr.setstate(ios::failbit);
				return istr;
			} else if (d.errCode() == DAY_ERROR){
				err_.message("Invalid Day in Date Entry");
				istr.setstate(ios::failbit);
				return istr;
			} else 
				// set the expiry date of the object to the emporary Date object
				// read from the console  
				expiry(d);
		}
		return istr; // returns istr argument
	}
}
