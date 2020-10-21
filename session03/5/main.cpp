#include "stats.h"
#include "vector_util.h"
#include <iostream>
#include <vector>

using namespace std;


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
