// Task 4

#include "average_pricing.h"
#include <algorithm>

using namespace std;

// average of the two pricing schemes

average_pricing::average_pricing(pricing& p1, pricing& p2) :
	pricing("average of " + p1.name() + " and " + p2.name()),
	policy1(p1), policy2(p2) {}

double average_pricing::cost(const product& p, int n) {
	return (policy1.cost(p, n) + policy2.cost(p, n)) / 2;
}