#include <iostream>

int main() {

	int age;

	std::cout << "Please enter your current age: ";
	std::cin >> age;

	if (age < 18) {
		std::cout << age << " is too young.\n";
	}
	else if (age > 30) {
		std::cout << age << " is too old.\n";
	} 
	else {
		std::cout << age << " is the right age.\n";
	}

	return 0;

}
