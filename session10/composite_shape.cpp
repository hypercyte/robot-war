#include "composite_shape.h"

#include <string>

using namespace std;

composite_shape::composite_shape(shared_ptr<shape> s1, shared_ptr<shape> s2) :
	shape(s1), shape2(s2) {}

bool composite_shape::contains(const point& p) const {
	return shape->contains(p) || shape2->contains(p);
}

string composite_shape::description() const {
	return "composite shape made up of " + shape->description() + " and " + shape2->description();
}

void composite_shape::scale(double s) {
	shape->scale(s);
	shape2->scale(s);
}