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
	vector<string> start; // empty vector of strings
	vector<string> commands;
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


	cout << '\n' << "Command input:" << '\n' << '\n';

	for (const auto& c : commands) {
		auto v = seperate(c); // separate for additional params
		if (v.size() > 1) {
			auto validation = find_if(robots.cbegin(), robots.cend(), [&robots, &v](shared_ptr<robot> r) { return r->id() == stoi(v[1]); });
			if (validation == robots.cend()) {
				break;
			}
		}
		if (v[0] == "show") {
			cout << "show" << '\n';
			print_robots(robots, 0);
		}
		else if (v[0] == "travelled") {
			cout << "travelled" << '\n';
			print_robots(robots, 1);
		}
		else if (v[0] == "within") {
			cout << "within -> " << stoi(v[1]) << "m" << '\n';
			within(robots, stoi(v[1]));
		}
		else if (v[0] == "turnleft") {
			cout << "turnleft -> #" << stoi(v[1]) << '\n';
			turn(robots, stoi(v[1]), 0);
		}
		else if (v[0] == "turnright") {
			cout << "turnright -> #" << stoi(v[1]) << '\n';
			turn(robots, stoi(v[1]), 1);
		}
		else { // else as we can expect no formatting errors, so no if none of the above, must be move.
			cout << "move -> #" << stoi(v[1]) << '\n';
			move(robots, stoi(v[1]));
		}
	}

	cout << "Robot input:" << '\n' << '\n';

	for (const auto& r : robots) {
		cout << "Robot #" << r->id() << " from team " << r->team() << " is currently located at ("
			<< r->xpos() << ", " << r->ypos() << "), facing " << r->direction() << '.' << '\n';
	}

	return 0;
}
