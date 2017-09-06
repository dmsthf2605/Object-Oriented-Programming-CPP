#include <iostream>
#include <cstring>
#include "Product.h"

namespace sict{
	// sets the Product to a safe empty state. all number values are set to zero
	Product::Product(){
		price_ = 0.0;
		quantity_ = 0;
		qtyNeeded_ = 0;
		name_ = nullptr;
		sku_[0] = 0;
		taxed_ = false;
	}

	Product::Product(const char* sku, const char* name){
		std::strncpy(sku_, sku, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN] = '\0';
		name_ = new char[strlen(name) + 1];
		std::strcpy(name_, name);
		price_ = 0.0;
		quantity_ = 0;
		qtyNeeded_ = 0;
		taxed_ = false;
	}

	// five argument constructor
	Product::Product(const char* sku, const char* name, double price, int qtyN, bool taxed){
		std::strncpy(sku_, sku, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN] = '\0';
		// allocates enough memory to hold the name in the name_ pointer and then copies
		name_ = new char[strlen(name) + 1];
		std::strcpy(name_, name);
		quantity_ = 0;
		price_ = price;
		qtyNeeded_ = qtyN;
		// if value for taxed is not provided, it will set the taxed_ flag to the dafulat(true)
		taxed_ = taxed;

	}

	// copy constructor
	Product::Product(const Product& p){
		//shadow copy
		price_ = p.price_;
		quantity_ = p.quantity_;
		qtyNeeded_ = p.qtyNeeded_;
		taxed_ = p.taxed_;
		std::strncpy(sku_, p.sku_, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN] = '\0';

		if (p.name_ != nullptr){
			name_ = new char[strlen(p.name_) + 1];
			std::strcpy(name_, p.name_);
		} else
			name_ = nullptr;
	}

	// assignment operator
	Product& Product::operator=(const Product& p){
		if (this != &p){
			price_ = p.price_;
			quantity_ = p.quantity_;
			qtyNeeded_ = p.qtyNeeded_;
			taxed_ = p.taxed_;
			std::strncpy(sku_, p.sku_, MAX_SKU_LEN);
			sku_[MAX_SKU_LEN] = '\0';

			delete[] name_;
			if (p.name_ != nullptr){
				name_ = new char[strlen(p.name_) + 1];
				std::strcpy(name_, p.name_);
			} else
				name_ = nullptr;

		}
		return *this;
	}

	// setters:
	void Product::sku(const char* sku){ 
		std::strncpy(sku_, sku, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN] = '\0';
	}
	void Product::price(double price){
		price_ = price; 
	}
	void Product::quantity(int qty){ 
		quantity_ = qty; 
	}
	void Product::qtyNeeded(int qtyN){ 
		qtyNeeded_ = qtyN; 
	}
	void Product::taxed(bool taxed){ 
		taxed_ = taxed; 
	}
	void Product::name(const char* name){
		name_ = new char[strlen(name) + 1];
		std::strcpy(name_, name);
	}

	//getters: CANNOT modify the owner -> const
	const char* Product::sku()const{
		return sku_; 
	}
	double Product::price()const{ 
		return price_; 
	}
	const char* Product::name()const{ 
		return name_; 
	}
	bool Product::taxed()const{ 
		return taxed_; 
	}
	int Product::quantity()const{ 
		return quantity_; 
	}
	int Product::qtyNeeded()const{ 
		return qtyNeeded_; 
	}

	// if the product is not taxed, return the same value as price_
	double Product::cost()const{ 
		return taxed_ ? price_ + price_ * TAX : price_; 
	}

	// returns true if the product is in a sfe empty state
	bool Product::isEmpty()const{ 
		return name_ == nullptr; 
	}

	// member operators:
	// compares the received constant character pointer to the SKU of the product
	bool Product::operator==(const char* sku){ 
		return strcmp(sku_, sku) == 0; 
	}

	// add the received integer value to the quantity of the product
	int Product::operator+=(int qty){ 
		return quantity_ += qty;	
	}
	
	// reduce the quantity of the product by the integer value
	int Product::operator -= (int qty){	
		return quantity_ -= qty; 
	}
	
	// Non-member operator overload:
	// adds the total cost of the product on hand then returns total(cost * quantity)
	double operator+=(double& d, const Product& p){
		d += p.cost() * p.quantity();
		return d;
	}
	
	// Non-member IO operator overloads:
	std::istream& operator>>(std::istream& cin, Product& p){
		return p.read(cin);
	}
	std::ostream& operator<<(std::ostream& cout, const Product& p){
		return p.write(cout, true);
	}

	// virtual destructor. memory allocated by name_ is freed when product is destroyed
	Product::~Product(){ 
		delete[] name_; 
	}
	
}