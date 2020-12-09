#include "product.h"
#include "pricing.h"
#include "simple_pricing.h"
#include "discount_pricing.h"
#include "cheaper_pricing.h"
#include "onefree_pricing.h" // Task 1
#include "incremental_discount_pricing.h" // Task 2/3
#include "average_pricing.h" // Task 4
#include "giftcard_pricing.h" // Task 5
#include <iostream>
#include <string>

using namespace std;

void print_bill(pricing &policy) {
	string nm;
	double p;
	int n;
	cout << "pricing policy: " << policy.name() << '\n';
	while (cin >> nm >> p >> n) {
		product item(nm, p);
		cout << n << " x " << nm << ": " << policy.cost(item, n) << '\n';
	}
}

int main() {
	simple_pricing policy_a;
	discount_pricing policy_b(10, 0.20);
	cheaper_pricing policy_c(policy_a, policy_b);
	onefree_pricing policy_d; // Task 1 of exercises. Buy 1 Get 1 free. Tested.
	incremental_discount_pricing policy_e(0.4); // Task 2/3 of exercises. Increasing discount based on no of items. Tested.
	average_pricing policy_f(policy_d, policy_e); // Task 4 of exercises. Average of two pricing policies. Tested.
	giftcard_pricing policy_g(10); // Task 5 of exercises. Preset amount of deduction (giftcard). Tested.
	cout << "Enter product price quanity\n";
	print_bill(policy_g);
	return 0;
}
