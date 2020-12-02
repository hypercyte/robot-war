#include "onepound.h"
#include <string>

using namespace std;

//onepound::onepound(const string& n)
//	: product(n) {}

onepound::onepound(const string& n, int p) 
	: product(n, p) {}

string onepound::description() const {
	return '"' + product::description() + '"' + ", (1 pound)";
}