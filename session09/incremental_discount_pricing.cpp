// Task 2/3

#include "incremental_discount_pricing.h"

using namespace std;

incremental_discount_pricing::incremental_discount_pricing(double d) :
	pricing("incremental discount. 10% additional discount per extra item quantity"), 
	_discount(d) {}

double incremental_discount_pricing::cost(const product& p, int n) {
	double total = p.price();
	if (n > 1) {
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				total *= 1 - _discount;
			}
		}
	}
	return total;
}