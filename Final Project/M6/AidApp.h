#ifndef SICT_AIDAPP_H__
#define SICT_AIDAPP_H__
#include "Product.h"
#include "AmaPerishable.h"
#include "AmaProduct.h"

namespace sict{

	class AidApp{
	private:
		//private member  variables:
		char filename_[256];
		Product* product_[MAX_NO_RECS];
		std::fstream datafile_;
		int noOfProducts_;
		
		//copy and assignment prevention
		AidApp(const AidApp&);
		AidApp& operator=(const AidApp&);

		//private member functions:
		void pause()const;
		int menu();
		void loadRecs();
		void saveRecs();
		void listProducts()const;
		int SearchProducts(const char*)const;
		void addQty(const char*);
		void addProduct(bool);

	public:
		AidApp(const char*);		
		int run();

	};
}
#endif
