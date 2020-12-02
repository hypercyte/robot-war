#ifndef ONEPOUND_H
#define ONEPOUND_H

#include "product.h"
#include <string>

class onepound : public product {
	//const std::string _name;

public:
	onepound(const std::string& n, int p);

	virtual std::string description() const override;

	virtual ~onepound() {}
};

#endif // !ONEPOUND_H
