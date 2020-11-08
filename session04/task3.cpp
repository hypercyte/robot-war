#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

double max(vector<double> v) {
	const auto n = v.size(); // n is equal to the number of numbers
	if (n == 0)
		throw domain_error("score of an empty vector");

	// sort vector
	sort(v.begin(), v.end());

	double maximum = 0;

	for (auto &x : v) {
		if (v[x] > maximum)
		{
			maximum = v[x];
		}
	}

	return maximum;
}

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
	}
	return 0;
}
