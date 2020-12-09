// Task 4

#ifndef AVERAGE_PRICING_H
#define AVERAGE_PRICING_H

#include "pricing.h"

class average_pricing : public pricing {
	pricing& policy1;
	pricing& policy2;

public:
	average_pricing(pricing& p1, pricing& p2);

	double cost(const product& p, int n) override;
};

#endif // !AVERAGE_PRICING_H
