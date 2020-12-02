#include "product.h"
#include "book.h"
#include "cd.h"
#include "onepound.h"
#include <iostream>

using namespace std;

int main() {
	product p1("Hobnobs", 133);
	book p2("Effective C++", 3167, "0-321-33487-6");
	cd p4("Wadachi", 499, "SPYAIR");
	onepound p5("Book cover", 100);
	print_product(cout, p1);
	print_product(cout, p2);
	product p3 = p2;
	print_product(cout, p3); // All "book" methods excluded
	print_product(cout, p4);
	print_product(cout, p5);
	return 0;
}