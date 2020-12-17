#include "circle.h"

using namespace std;

circle::circle(const point &c, double r) : centre(c), radius(r) {}

bool circle::contains(const point &p) const {
	return dist(centre, p) <= radius;
}

string circle::description() const {
	return "circle of radius " + to_string(radius) +
		" centred on " + show_point(centre);
}

void circle::scale(double s) {
	centre = point(centre.x() * s, centre.y() * s);
	radius = radius * s;
}
