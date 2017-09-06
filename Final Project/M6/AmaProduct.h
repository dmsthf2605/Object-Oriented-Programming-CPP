#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
#include "Product.h"
#include "ErrorMessage.h"

namespace sict{

	class AmaProduct : public Product{
	  private:
		  char fileTag_;
		  char unit_[11];

	  protected:
		  ErrorMessage err_;

	  public:
		  AmaProduct(char file = 'N');
		  const char* unit()const;
		  void unit(const char* value);
		  // implementations of Streamable's pure virtual methods
		  virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		  virtual std::fstream& load(std::fstream& file);
		  virtual std::ostream& write(std::ostream& os, bool linear)const;
		  virtual std::istream& read(std::istream& is);

  };
}
#endif


