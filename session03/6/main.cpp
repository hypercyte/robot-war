#include "stats.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// read numbers from an input stream
// and return them in a vector
vector<string> read_vector(istream& in) {
	vector<string> v;
	string x;
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
		// TESTING THE FUNCTION
		cout << longest(values) << '\n';
	}
	return 0;
}
