#include <iostream>
#include <string>

int main() {

	// Variables
	std::string name; 
	int nameLength; 

	std::cout << "Please enter your first name: "; // Console OUTput (COUT)
	std::cin >> name; // Console INput (CIN)
	std::cout << "\nHello, " << name << '\n' << "======="; // The ======= accounts for the "Hello, ".
	
	// For loop to adjust the number of ==== based on user namelength.
	nameLength = name.size();
	int i;
	for (i = 1; i <= nameLength; i++) {
		std::cout << "=";
	}
	std::cout << '\n'; // Just ending on a new line to keep things clean.

	return 0;

}
