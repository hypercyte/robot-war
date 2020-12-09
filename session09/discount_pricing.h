#ifndef DISCOUNT_PRICING_H
#define DISCOUNT_PRICING_H

#include "pricing.h"

class discount_pricing : public pricing {
	int _threshold;
	double _discount;
public:
	discount_pricing(int n, double d);

	virtual double cost(const product& p, int n) override;
};

#endif // !DISCOUNT_PRICING_H
