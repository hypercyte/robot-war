//
//	main.cpp
//	Coursework: Robot War
//
//	Created by Mujahid Ahmed, 2020
//

#include "robot.h"
#include "command_helper.h"
#include "input_processing.h"
#include <iostream>
#include <string>

using namespace std;

/*===========
main program
=============*/
int main() {
	vector<string> start; // empty vector of strings for start.txt
	vector<string> commands; // empty vector of string for commands.txt
	vector<shared_ptr<robot>> robots; // empty vector of pointers to robot objects
	input_data(start, "start.txt"); // input data from start.txt into the start vector
	input_data(commands, "commands.txt");

	// for every element of vector start
	for (const auto& s : start) {
		auto v = seperate(s); // separate words and push into vector v
		robots.push_back(make_shared<robot>(
			stoi(v[0]),
			stoi(v[1]),
			stoi(v[2]),
			stoi(v[3]))
		); // create a robot object for each line
	}

	for (const auto& c : commands) {
		auto v = seperate(c); // separate for additional params
		if (v.size() > 1 && v[0] != "within") { // validate robot exists, if not we silently ignore and move on
			auto validation = find_if(robots.cbegin(), robots.cend(), [&v](shared_ptr<robot> r) { return r->id() == stoi(v[1]); });
			if (validation == robots.cend()) {
				continue;
			}
		}
		if (v[0] == "show") {
			print_robots(robots, 0);
		}
		else if (v[0] == "travelled") {
			print_robots(robots, 1);
		}
		else if (v[0] == "within") {
			within(robots, stoi(v[1]));
		}
		else if (v[0] == "turnleft") {
			turn(robots, stoi(v[1]), 0);
		}
		else if (v[0] == "turnright") {
			turn(robots, stoi(v[1]), 1);
		}
		else { // else as we can expect no formatting errors, so no if none of the above, must be move.
			move(robots, stoi(v[1]));
		}
	}

	return 0;
}
