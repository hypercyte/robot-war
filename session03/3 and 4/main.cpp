#include "stats.h"
#include <iostream>
#include <vector>

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

int main() {
	cout << "Please enter a series of numbers\n";
	// read numbers from the standard input
	// and store them in a vector
	auto values = read_vector(cin);
	// compute and output results
	const auto n = values.size();
	cout << n << " numbers\n";
	if (n > 0) {
		// TESTING THE FUNCTION
		vector_out(cout, values); // original set of values
		reverse(values);
		vector_out(cout, values); // reversed set of values
	}
	return 0;
}
