#include "stats.h"
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
	typedef vector<double>::size_type vec_size;

	for (vec_size i = 1; i < n; ++i) {
		if (v[i] > maximum)
		{
			maximum = v[i];
		}
	}	

	return maximum;
}

double min(vector<double> v) {
	const auto n = v.size(); // n is equal to the number of numbers
	if (n == 0)
		throw domain_error("score of an empty vector");

	// sort vector
	sort(v.begin(), v.end());

	double minimum = 0;
	typedef vector<double>::size_type vec_size;

	for (vec_size i = 1; i < n; ++i) {
		if (v[i] < minimum)
		{
			minimum = v[i];
		}
	}

	return minimum;
}