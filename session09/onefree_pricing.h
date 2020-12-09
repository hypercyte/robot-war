// Task 1

#ifndef ONEFREE_H
#define ONEFREE_H

#include "pricing.h"

class onefree_pricing : public pricing {
public:
	onefree_pricing();

	virtual double cost(const product& p, int n) override;
};

#endif // ONEFREE_H
