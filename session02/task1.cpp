#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*================================
Task 1: Compute average separately
==================================*/

int main() {

	cout << "Please enter a series of numbers\n";

	// read numbers from the standard input
	// and store them in a vector
	vector<double> v;
	double x;
	while (cin >> x)
		v.push_back(x);

	// compute and output results
	auto n = v.size();
	cout << n << " numbers\n";
	if (n > 0) {
		// sort the whole vector
		sort(v.begin(), v.end());
		// find the middle value
		auto middle = n / 2;
		double median;
		if (n % 2 == 1) // size is odd
			median = v[middle];
		else // size is even
			median = (v[middle - 1] + v[middle]) / 2;
		cout << "median = " << median << '\n';
	}

	// ================================
	// TASK 1: Compute average separately
	// ================================
	float avg = 0;
	if (n != 0) {
		avg = accumulate( v.begin(), v.end(), 0 ) / n;
		cout << "average = " << avg << '\n';
	}
	
	return 0;
}
