#ifndef SICT__Product_H_
#define SICT__Product_H_
#include <iostream>
#include "general.h"
#include "Streamable.h"

namespace sict{
	class Product{
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;

	public:
		Product();
		Product(const char*, const char*);
		Product(const char*, const char*, double, int, bool = true);
		Product(const Product&);
		Product& operator=(const Product&);
		virtual ~Product();
		bool operator==(const char*);
		int operator+=(int);
		int operator-=(int); 
		//setters
		void sku(const char*);
		void price(double);
		void name(const char*);
		void taxed(bool);
		void quantity(int);
		void qtyNeeded(int);
		//getters
		const char* sku()const;
		double price()const;
		const char* name()const;
		bool taxed()const;
		int quantity()const;
		int qtyNeeded()const;
		double cost()const;
		bool isEmpty()const;
		virtual std::ostream& write(std::ostream& os, bool linear)const = 0;
		virtual std::istream& read(std::istream& is) = 0;
	};
	double operator+=(double&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	std::ostream& operator<<(std::ostream&, const Product&);

}
#endif