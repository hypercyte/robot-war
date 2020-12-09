// Task 1

#include "onefree_pricing.h"

using namespace std;

onefree_pricing::onefree_pricing() :
	pricing("buy 1 get 1 free!") {}

double onefree_pricing::cost(const product& p, int n) {
	double total = p.price() * n;
	if (n > 1) {
		total -= p.price();
	}
	return total;
}