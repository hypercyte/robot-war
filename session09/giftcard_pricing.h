// Task 5

#ifndef GIFTCARD_PRICING_H
#define GIFTCARD_PRICING_H

#include "pricing.h"

class giftcard_pricing : public pricing {
	double _giftcard;
public:
	giftcard_pricing(double g);


	virtual double cost(const product& p, int n) override;
};

#endif // GIFTCARD_PRICING_H
