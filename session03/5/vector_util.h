#ifndef GUARD_vectorutil_h
#define GUARD_vectorutil_h

#include <vector>
#include <iostream>

// reading the contents of vector of dobules
vector<double> read_vector(istream& in);

// output vector
void vector_out(ostream& out, const vector<double>& v);


#endif