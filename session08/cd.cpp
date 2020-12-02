#include "cd.h"
#include <string>

using namespace std;

cd::cd(const string& n, int p, const string& a)
	: product(n, p), _artist(a) {}

string cd::description() const {
	return "CD: " + _artist + " - " + product::description();
}