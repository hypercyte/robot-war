#include "stats.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <utility>

using namespace std;

void reverse(vector<double>& v) {
	const auto n = v.size(); // n is equal to the number of numbers

	typedef vector<double>::size_type vec_size; // using vec_size = vector<double>::size_type; works too for future ref
	vec_size size = v.size();
	vec_size mid = size / 2;

	for (vec_size i = 0; i < mid; ++i) {
		swap(v[i], v[size - 1 - i]);
	}
}

string longest(vector<string> str) {
	string longest;
	for (vector<string>::size_type i = 1; i <= str.size(); ++i)
		if (str[i].size() > longest.size()) {
			longest = str[i];
		}
	return longest;
}
