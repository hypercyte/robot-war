#ifndef SIMPLE_PRICING_H
#define SIMPLE_PRICING_H

#include "pricing.h"

class simple_pricing : public pricing {
public:
	simple_pricing();

	virtual double cost(const product& p, int n) override;
};

#endif // SIMPLE_PRICING_H
