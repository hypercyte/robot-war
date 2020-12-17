#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

// an abstract two-dimensional shape
class shape {
public:
	// Is the point p inside the shape?
	virtual bool contains(const point &p) const = 0;

	virtual std::string description() const = 0;

	virtual ~shape() {}

	virtual void scale(double s) = 0;
};

#endif
