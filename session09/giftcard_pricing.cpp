// Task 5

#include "giftcard_pricing.h"

using namespace std;

giftcard_pricing::giftcard_pricing(double g) :
	pricing("giftcard balance: " + to_string(g) + " pounds."), _giftcard(g) {}

double giftcard_pricing::cost(const product& p, int n) {
	double total = p.price() * n;
	if (_giftcard > 0) {
		total -= _giftcard;
		_giftcard = 0;
		if (total < 0) {
			_giftcard = -total;
			total = 0;
		}
	}
	return total;
}