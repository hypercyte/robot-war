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
vector<string> seperate(const string& s) {
	vector<string> v; // empty vector of type int
	auto space = find(s.cbegin(), s.cend(), ' '); // find the first instance of a space character
	v.push_back(string(s.cbegin(), space)); // convert first string to int and push it into vector v
	// continue till the end
	while (space != s.cend()) { 
		auto start = ++space;
		space = find(start, s.cend(), ' ');
		v.push_back(string(start, space));
	}
	return v; // return the vector with separated ints
}

/*=========
main
==========*/
int main() {
	vector<string> start; // empty vector of strings
	vector<string> commands;
	vector<shared_ptr<robot>> robots; // empty vector of pointers to robot objects
	input_data(start, "start.txt"); // input data from start.txt into the start vector
	input_data(commands, "commands.txt");

	// for every element of vector start
	for (const auto& s : start) {
		auto v = seperate(s); // separate words and push into vector v
		robots.push_back(make_shared<robot>(stoi(v[0]), stoi(v[1]), stoi(v[2]), stoi(v[3]), 0, 0)); // create a robot object for each line
	}

	cout << "Robot input:" << '\n' << '\n';

	for (const auto& r : robots) {
		cout << "Robot #" << r->id() << " from team " << r->team() << " is currently located at ("
			<< r->xpos() << ", " << r->ypos() << "), facing " << r->direction() << '.' << '\n';
	}

	cout << '\n' << "Command input:" << '\n' << '\n';

	for (const auto& c : commands) {
		auto v = seperate(c); // separate for additional params
		if (v[0] == "show") {
			cout << "show" << '\n';
			// show implementation
		}
		else if (v[0] == "travelled") {
			cout << "travelled" << '\n';
			// travelled implementation
		}
		else if (v[0] == "within") {
			cout << "within -> " << stoi(v[1]) << "m" << '\n';
			// within implementation
		}
		else if (v[0] == "turnleft") {
			cout << "turnleft -> #" << stoi(v[1]) << '\n';
			// turn left implementation
		}
		else if (v[0] == "turnright") {
			cout << "turnright -> #" << stoi(v[1]) << '\n';
			// turn right implementation
		}
		else { // else as we can expect no formatting errors, so no if none of the above, must be move.
			cout << "move -> #" << stoi(v[1]) << '\n';
			// move implementation
		}
	}

	return 0;
}
