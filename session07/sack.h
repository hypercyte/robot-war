#ifndef SACK_H
#define SACK_H

#include "item.h"
#include <string>
#include <vector>

class sack {
	// vector containing objects of "item" class.
	std::vector<item> items;

public:
	// add an item to the sack
	void add_item(const item& i);

	// print total value of the sack
	void print_value() const;

	// return bool whether sack contains item of said description
	int check_item(const std::string& desc) const;

	// return the number of items with a value greater than x
	int count_expensive(int x) const;

	// return bool whether there is an expensive item or not in the sack
	bool check_expensive(int x) const;
	
};

#endif // !SACK_H
