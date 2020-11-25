#include "sack.h"
#include "item.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void sack::add_item(const item& i) {
	items.push_back(i);
}

void sack::print_value() const {
	int sum = 0;
	for (const auto& x : items) {
		sum += x.value();
	}
	cout << "Total sack value: " << sum << '\n';
}

int sack::check_item(const std::string& desc) const {
	return count_if(items.cbegin(), items.cend(),
		[&desc](const item& i) { return i.desc() == desc; });
}

int sack::count_expensive(int x) const {
	return count_if(items.cbegin(), items.cend(),
		[&x](const item& i) { return i.value() > x; });
}

bool sack::check_expensive(int x) const {
	auto count = count_if(items.cbegin(), items.cend(),
		[&x](const item& i) { return i.value() > x; });
	if (count != 0) {
		return true;
	}
	else {
		return false;
	}
}