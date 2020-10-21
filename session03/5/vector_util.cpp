#include "vector_util.h"
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

// read numbers from an input stream
// and return them in a vector
vector<double> read_vector(istream& in) {
	vector<double> v; 
	double x;
	while (in >> x)
		v.push_back(x);
	return v;
}

// using this to output vector (task 4)
void vector_out(ostream& out, const vector<double>& v) {
	for (double d : v) {
		out << d << ' ';
	}
	out << '\n';
}