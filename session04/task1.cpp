#include <iostream>
#include <vector>

using namespace std;

double average(const vector<double>& v) {
	const auto n = v.size();
	if (n == 0)
		throw domain_error("average of an empty vector");
	double sum = 0;
	for (auto i = v.cbegin(); i != v.cend(); ++i) {
		sum += *i;
	}
	return sum / n;
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
		cout << "average = " << average(values) << '\n';
	}
	return 0;
}
