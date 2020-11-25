#include "sack.h"
#include "item.h"
#include <iostream>

using namespace std;

int main() {
	sack s;
	item i1("Nintendo Switch", 300);
	item i2("HP ENVY x360 13-ay0500", 740);
	item i3("Nintendo Switch", 300);
	item i4("Logitech MX Master", 60);
	s.add_item(i1);
	s.add_item(i2);
	s.add_item(i3);
	s.add_item(i4);
	s.print_value();

	string query = "HP ENVY x360 13-ay0500";
	cout << "There is " << s.check_item(query) << " item(s) that match the search query: '" << query << "'\n";

	if (s.check_expensive(100)) {
		cout << "There are " << s.count_expensive(100) << " expensive items in the sack." << '\n';
	}
	else {
		cout << "There are no expensive items in the sack." << '\n';
	}
	return 0;
}
