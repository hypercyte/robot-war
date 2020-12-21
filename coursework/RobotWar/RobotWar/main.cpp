//
//	main.cpp
//	Coursework: Robot War
//
//	Created by Mujahid Ahmed, 2020
//

#include "robot.h"

#include <iostream>
#include <fstream>
#include <memory>
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
vector<int> seperate(const string& s) {
	vector<int> v; // empty vector of type int
	auto space = find(s.cbegin(), s.cend(), ' '); // find the first instance of a space character
	v.push_back(stoi(string(s.cbegin(), space))); // convert first string to int and push it into vector v
	// continue till the end
	while (space != s.cend()) { 
		auto start = ++space;
		space = find(start, s.cend(), ' ');
		v.push_back(stoi(string(start, space)));
	}
	return v; // return the vector with separated ints
}

/*=========
main
==========*/
int main() {
	vector<string> start; // empty vector of strings
	vector<shared_ptr<robot>> robots; // empty vector of pointers to robot objects
	input_data(start, "start.txt"); // input data from start.txt into the start vector

	// for every element of vector start
	for (const auto& s : start) {
		auto v = seperate(s); // separate words and push into vector v
		robots.push_back(make_shared<robot>(v[0], v[1], v[2], v[3], 0, 0)); // create a robot object for each line
	}

	for (const auto& v : robots) {
		cout << "Robot #" << v->id() << " from team " << v->team() << " is currently located at ("
			<< v->xpos() << ", " << v->ypos() << "), facing " << v->direction() << '.' << '\n';
	}

	return 0;
}
