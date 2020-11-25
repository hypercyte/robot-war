#ifndef ITEM_H
#define ITEM_H

#include <string>

class item {
	const std::string _desc;
	const int _value;

public:
	item(const std::string& d, const int val) :
		_desc(d), _value(val) {}

	const std::string& desc() const { return _desc; }
	int value() const { return _value; }
};

#endif // !ITEM_H
