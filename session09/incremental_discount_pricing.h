// Task 2/3

#ifndef INCREMENTAL_DISCOUNT_PRICING_H
#define INCREMENTAL_DISCOUNT_PRICING_H

#include "pricing.h"

class incremental_discount_pricing : public pricing {
	double _discount;
public:
	incremental_discount_pricing(double d);

	virtual double cost(const product& p, int n) override;
};

#endif // INCREMENTAL_DISCOUNT_PRICING_H
