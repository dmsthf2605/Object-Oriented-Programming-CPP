// OOP244 Workshop 3: Dynamic Memory
// File	w3_at_home.cpp
// Version 1.0
// Date Feb 8, 2016	
// Author EUNSOL LEE	
// Description
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Weather.h"
using namespace std;
using namespace sict;
double findLow(const char* date, const Weather *data, int dataSize);

int main(){
	int i; //  loop counter
  	int n; //the count of days worth of weather
  	// create the weather pointer here
  	Weather* weather = nullptr;

  	cout << "Weather Data\n";
  	cout << "=====================" << endl;
  	cout << "Days of Weather: ";
  	cin >> n;
  	cin.ignore();

  	// allocate dynamic memory here
  	weather = new Weather[n];
  
	for (i = 0; i < n; i++){
    		char date_description[7];
    		double high;
    		double low;

  		// ... add code to accept user input for weather
		cout << "Enter date: ";
		cin >> date_description;
		cout << "Enter high: ";
		cin >> high;
		cout << "Enter low : ";
		cin >> low;

		weather[i].set(date_description, high, low);
  	}//for()

  	cout << endl
    	<< "Weather report:" << endl
    	<< "Date        high  low" << endl
    	<< "======================" << endl;

  	for (i = 0; i < n; i++){
    		weather[i].display();
  	}
  	cin.ignore();

  	//accept user input for the date to find 
  	//(in this example stored in char query[7])
  	// and display the found low temprature.
  	char query[7];
  	cout << endl << "Enter the date you are looking for: ";
  	cin.getline(query, 7, '\n');

  	double low = findLow(query, weather, n);
  	cout << "Low temperature: " << low << endl;

  	// deallocate dynamic memory here
  	delete[] weather;
  	weather = nullptr;

  	return 0;

} //main()

double findLow(const char* date, const Weather *data, int dataSize){
	for (int i = 0; i < dataSize; i++){
		//matching
		if (strcmp(data[i].date(), date) == 0){
			return data[i].low();
		}
	} //for()
	//retrun 0.0 if the date is not found in the data
	return 0.0;
}

