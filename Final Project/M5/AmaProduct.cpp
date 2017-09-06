#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AmaProduct.h"

using namespace std;
namespace sict{

	// if value is not provided, it will use 'N' as the default value
	AmaProduct::AmaProduct(char file){
		fileTag_ = file;
	}

	// returns a constant pointer to the unit_
	const char* AmaProduct::unit()const{
		return unit_;
	}

	// copies the passed value but NOT copy the size of unit_ array
	void AmaProduct::unit(const char* value){
		strcpy(unit_, value);
	}

	// implements all 4 pure virtual methods of the calss Streamable:
	// using the operator<< of ostream.
	fstream& AmaProduct::store(fstream& file, bool addNewLine) const{
		// writes the fileTag_ and a comma into t he file argument,
		// then without any formatting or spaces writes all the member variables
		file << fileTag_ << "," << sku() << "," << name() << "," << price() 
			 << "," << taxed() << "," << quantity() << "," << unit() << ","
			 << qtyNeeded();
		
		// if addNewLine is true, end with a new line
		if (addNewLine == true)
			file << endl;

		// return the file argument out
		return file;
	}

	// using the operator>>, ignore, and getline methods of istream
	fstream& AmaProduct::load(fstream& file){
		// use temporary variables
		char s[MAX_SKU_LEN + 1]; //SKU
		char n[20]; //Name
		double p; //Price
		int t = 0; //Taxed
		int q; //Quantity
		char u[11]; //Unit
		int qn; //Quantity Needed

		// read the fields one by one, skipping the commas
		// after each read, set the member variables using stter methods
		// the filetag_ is not included -> starts the reading from the SKU
		file.getline(s, MAX_SKU_LEN, ',');
		sku(s);

		file.getline(n, 20, ',');
		name(n);

		file >> p;
		file.ignore();
		price(p);

		file >> t;
		file.ignore();
		if (t){
			taxed(true);
		} else {
			taxed(false);
		}

		file >> q;
		file.ignore();
		quantity(q);

		file.getline(u, 11, ',');
		unit(u);

		file >> qn;
		file.ignore();
		qtyNeeded(qn);

		return file; //returns the file arguement
	}
	
	ostream& AmaProduct::write(ostream& os, bool linear)const{
		if (!err_.isClear()){ // err_ member variable is not clear
			return os << err_;
		} else if(err_.isClear()){ // No error
			if (linear){ // Linear is ture
				// prints the product values separated by Bar "|"
				os << fixed << left << setfill(' ') << setw(MAX_SKU_LEN) << sku() << "|"
					<< setw(20) << name() << "|"
					<< right << setw(7) << setprecision(2) << cost() << "|"
					<< setw(4) << quantity() << "|"
					<< left << setw(10) << unit() << "|"
					<< right << setw(4) << qtyNeeded() << "|";
					//NO NEW LINE
			} else { // Linear is false
				os << "Sku: " << sku() << endl;
				os << "Name: " << name() << endl;
				os << "Price: " << price() << endl;
				if (taxed()){
					os << "Price after tax: " << cost() << endl;
				} else { // the product is not taxed
					os << "Price after tax: N/A" << endl;
				}
				os << "Quantity On Hand: " << quantity() << " " << unit() << endl;
				os << "Quantity Needed: " << qtyNeeded();
				//NO NEW LINE
			}
		}
		return os; // returns the os argument		
	}
	
	// receives the values using istream 
	// at any stage istr fails, err_ should be set to the proper error message
	// and the rest of the entry is skipped and nothing is set in the Product
	// also NO error message is dispalyed
	istream& AmaProduct::read(istream& istr){
		// use temporary variables
		char s[MAX_SKU_LEN + 1]; //SKU
		char n[20]; //Name
		double p; //Price
		char t; //Taxed
		int q; //Quantity
		char u[11]; //Unit
		int qn; //Quantity Needed

		// if istr is in a fail state, return istr
		if (!istr.fail()){
			err_.clear();

			cout << "Sku: ";
			istr >> s;
			if (istr.fail()){
				return istr;
			} else {
				sku(s);
			}
			
			cout << "Name: ";
			istr >> n;
			if (istr.fail()){
				return istr;
			} else {
				name(n);
			}

			cout << "Unit: ";
			istr >> u;
			if (istr.fail()){
				return istr;
			} else {
				unit(u);
			}
			
			cout << "Taxed? (y/n): ";
			istr >> t;
			// if it is one of 'Y', 'y', 'N', or 'n' then clear(flush) the keyboard
			if (t == 'Y' || t == 'y'){
				istr.clear();
				taxed(true);
			} else if (t == 'N' || t == 'n'){
				istr.clear();
				taxed(false);
			} else {
				err_.message("Only (Y)es or (N)o are acceptable");
				// call the "istr.setstate(ios::failbit)" function for the error handling
				istr.setstate(ios::failbit);
				return istr;
			}				

			cout << "Price: ";
			istr >> p;
			if (istr.fail()){
				err_.message("Invalid Price Entry");
				return istr;
			} else {
				price(p);
			}

			cout << "Quantity On hand: ";
			istr >> q;
			if (istr.fail()){
				err_.message("Invalid Quantity Entry");
				return istr;
			} else {
				quantity(q);
			}

			cout << "Quantity Needed: ";
			istr >> qn;
			if (istr.fail()){
				err_.message("Invalid Quantity Needed Entry");
				return istr;
			} else {
				qtyNeeded(qn);
			}
		}
		return istr;
	}
}