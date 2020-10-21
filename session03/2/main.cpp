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

int main() {
	cout << "Please enter a series of numbers\n";
	// read numbers from the standard input
	// and store them in a vector
	auto values = read_vector(cin);
	// compute and output results
	const auto n = values.size();
	cout << n << " numbers\n";
	if (n > 0) {
		cout << "maximum value = " << max(values) << '\n';
		cout << "minimum value = " << min(values) << '\n';
	}
	return 0;
}
