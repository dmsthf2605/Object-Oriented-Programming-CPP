#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AidApp.h"

using namespace std;
namespace sict{
	// constructor
	AidApp::AidApp(const char* filename){
		strcpy(filename_, filename);
		// sets all the product_ elements to nullptr
		for (int i = 0; i < MAX_NO_RECS; i++){
			product_[i] = nullptr;
		}		
		noOfProducts_ = 0;
		loadRecs();
	}

	// Only accept ENTER key
	void AidApp::pause()const{
		// if user hit any other key, the key in ignored
		cout << "Press Enter to continue..." << endl;
		cin.ignore(1000, '\n');
	}

	// displays the menu and waits for the user to select an option
	int AidApp::menu(){
		int a;
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quantity of purchased products" << endl;
		cout << "6- Update product quantity" << endl;
		cout << "7- Delte product" << endl;
		cout << "8- Sort Products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> a;
		
		// if the selection is valid, menu() will return the selection otherwise it will return -1
		if (a < 0 || a > 8){
			return -1;
		} 
		// there are no characters left in keyboard and wipes it before exit
		cin.clear();
		cin.ignore();
		return a;
	}

	// opens the file for reading, if it does not exist, it will create an empty file and exits
	void AidApp::loadRecs(){
		int readIndex = 0;
		char id = '\0';

		// open file for reading
		datafile_.open(filename_, ios::in); 
		// if the file is in fail state(no file on the disk) then clear the failure, close the file
		if (datafile_.fail()){
			datafile_.clear();
			datafile_.close();
			// open the file for writing to create the file
			datafile_.open(filename_, ios::out);
			//close the file
			datafile_.close();
		} else {
			id = datafile_.get();
			while (!datafile_.fail()){
				// deallocate the memory pointed by product pointer at readIndex
				delete product_[readIndex];
				product_[readIndex] = nullptr;
				// read 1 char character to identify type of prodict into Id character
				if (id == 'P'){
					product_[readIndex] = new AmaPerishable();
					datafile_.ignore(1);
					product_[readIndex] -> load(datafile_);
					readIndex++;
				} else if (id == 'N'){
					product_[readIndex] = new AmaProduct();
					datafile_.ignore(1);
					product_[readIndex] -> load(datafile_);
					readIndex++;
				}
				id = datafile_.get();
			}		
		}

		noOfProducts_ = readIndex;
		datafile_.close();
	}

	// opens the file for writing
	void AidApp::saveRecs(){
		datafile_.open(filename_, ios::out);
		// loops through the product_ array up to noOfProduct_
		// and stores them in the datafile_
		for (int i = 0; i < noOfProducts_; i++){
			product_[i] -> store(datafile_, true);
		}
		datafile_.close();
	}

	// list the products
	void AidApp::listProducts()const{
		int c = 0;
		double total = 0;
		
		cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl;
		cout << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;
		for (int i = 0; i < noOfProducts_; i++){
			cout << fixed << setfill(' ') << right << setw(4) << i + 1 << " | " << *product_[i] << endl;
			c++;

			total += *product_[i]; // double operator+=(double&, const Product&)
			if (c == 10){
				pause();
			}
		} //for()
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Total cost of support: " << fixed << setprecision(2) << "$" << total << endl;
		cout << endl;
	}

	// if a match is found it will return the index of th efound Product in the product_ array
	// oherwise it returns -1
	int AidApp::SearchProducts(const char* sku)const{
		bool found = false;
		int i;
		for (i = 0; i < noOfProducts_; i++){
			if (*product_[i] == sku){ // bool operator==(const char*)
				found = true;
				break;
			} 
		}
		return found ? i : -1;
	}

	// updates the quantity on hand for a product
	// searchs for the Product with the same sku as incoming argument
	void AidApp::addQty(const char* sku){
		int a = SearchProducts(sku);
		int n = 0; // New quantity

		if (a == -1){
			cout << "Not found!" << endl;
		} else {
			// display the Product in non-linear format 
			cout << endl;
			product_[a] -> write(cout, false);
			cout << endl;
			cout << endl;
			// asks for an integer for quauntity purchased
			cout << "Please enter the number of purchased items: ";
			cin >> n;
			//if it can't read the integer
			if (cin.fail()){
				cout << "Invalid quantity value!" << endl;
			} else {
				cin.ignore();
				// the amount is less than or equal to the amount required
				int qn = product_[a]->qtyNeeded();
				int q = product_[a]->quantity();
				int r = qn - q;
				if (n <= r){
					*product_[a] += n; // int operator+=(int)
				} else {
					// only accept the amount required 
					*product_[a] += r;
					cout << "Too many items; only " << r << " is needed, please return the extra "
						 << n - r << " items." << endl;
				}
				cout << endl;
			}
			// save all the records back to the file
			saveRecs();
			cout << "Updated!" << endl;
			cout << endl;
			cin.clear();
		}		
	}

	// depending on the value of the argument being true or false, create a Perishable or Non-perishable Product
	// and get the values from the user and add it to the end of the product_ array and save the records
	void AidApp::addProduct(bool isPerishable){
		if (isPerishable){
			AmaPerishable* a = new AmaPerishable;
			cin >> *a;
			product_[noOfProducts_] = a;

			// if there is an error, display toe Product and exit -< show the error message
			if (cin.fail()){
				a->write(cout, false) << endl;
				cin.clear();
				return;	
			} else {				
				product_[noOfProducts_] -> store(datafile_, true);
				cout << endl;
				noOfProducts_++;
				saveRecs();
				cout << "Product added" << endl;
				cout << endl;
			}
		} else {
			AmaProduct* b = new AmaProduct;
			cin >> *b;
			product_[noOfProducts_] = b;
			if (cin.fail()){
				b->write(cout, false) << endl;
				cin.clear();
				return;	
			} else {
				product_[noOfProducts_]->store(datafile_, true);
				cout << endl;
  				noOfProducts_++;
				saveRecs();
				cout << "Product added" << endl;
				cout << endl;
			}
		}			
	}

	// display the menu and depending on the user's selection, do the actions requested 
	// pauses then it will redisplay the menu until user selects 0 to exit
	int AidApp::run(){
		int s = -10; // user's selection
		int check = 0;
		char sku[MAX_SKU_LEN + 1];
		int qty;

		while (s != 0){
			s = menu();
			cout << endl;
		
			switch (s){
				case 0: // Exit program
					cout << "Goodbye!!" << endl;
					break;
				case 1: // List products
					listProducts();
					pause();
					break;
				case 2: // Display product
					// ask for a sku 
					cout << "Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN, '\n');
					check = SearchProducts(sku);
					if (check == -1){ // not founded
						cout << "Not found!" << endl;
					} else {
						// display in non-liner format
						cout << endl;
						product_[check]->write(cout, false) << endl;
						cout << endl;
						pause();
					}
					break;
				case 3: // Add non-perishable product
					addProduct(false);
					loadRecs();
					cin.ignore();
					break;
				case 4: // Add perishable product
					addProduct(true);
					loadRecs();
					cin.ignore();
					break;
				case 5: // Add to quantity of purchased products
					// Ask for a sku
					cout << "Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN, '\n');					
					addQty(sku);
					break;
				case 6: // Update product quantity
					cout << "Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN, '\n');
					check = SearchProducts(sku);
					if (check == -1){ // not founded
						cout << "Not found!" << endl;
					}
					else {
						// display in form format
						product_[check]->write(cout, true) << endl;
						cout << "Please enter the new item quantity: ";
						cin >> qty;

				
					}
					break;
				case 7: // Delete product
					break;
				case 8: // Sort Products
					break;
				default:
					cout << "===Invalid Selection, try again.===" << endl;
					pause();
					break;
			}
		}
		return 0;
	}
}
