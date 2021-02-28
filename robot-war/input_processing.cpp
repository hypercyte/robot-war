//
//	input_processing.cpp
//	Coursework: Robot War
//
//	Created by Mujahid Ahmed, 2020
//

#include "input_processing.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*=====================================
read input files and separate the lines
=======================================*/
void input_data(vector<string>& v, const string& dir) {
	ifstream file(dir); // load file
	string s; // init string
	while (getline(file, s)) {
		v.push_back(s); // push each line into vector
	}
}

/*=====================================
separate words at every space character
=======================================*/
bool find_space(char c) {
	return isspace(c);
}

vector<string> seperate(const string& s) {
	vector<string> v; // empty vector of type int
	auto space = find_if(s.cbegin(), s.cend(), find_space); // find the first instance of a space character
	v.push_back(string(s.cbegin(), space)); // convert first string to int and push it into vector v
	// continue till the end
	while (space != s.cend()) {
		auto start = ++space;
		space = find_if(start, s.cend(), find_space);;
		v.push_back(string(start, space));
	}
	return v; // return the vector with separated ints
}
