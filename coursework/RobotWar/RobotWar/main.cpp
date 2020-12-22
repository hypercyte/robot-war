//
//	main.cpp
//	Coursework: Robot War
//
//	Created by Mujahid Ahmed, 2020
//

#include "robot.h"
#include "input_processing.h"

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*=================
sorting functions
sort_by: [
	0 = sort by id
	1 = sort by distance travelled
]
==================*/
void sort_robots(vector<shared_ptr<robot>>& robots, int& sort_by) {
	sort(robots.begin(), robots.end(),
		[&sort_by](shared_ptr<robot> a, shared_ptr<robot> b) {
			switch (sort_by) {
				case 0:
					return a->id() < b->id();
					break;
				case 1:
					return a->distance() < b->distance();
					break;
			}
		}
	);
}

/*====================================
printing implemenation // (used for show and travelled commands)
sort_by: [
	0 = sort by id
	1 = sort by distance travelled
]
======================================*/
void print_robots(vector<shared_ptr<robot>>& robots, int sort_by) {
	sort_robots(robots, sort_by);
	for (auto &r : robots) {
		switch (sort_by)
		{
		case 0: // command: show
			cout << r->id() << ' ' << r->team() << ' ' << r->xpos() << ' ' << r->ypos() << '\n';
			break;
		case 1: // command: travelled
			cout << r->id() << ' ' << r->distance() << '\n';
			break;
		default:
			break;
		}
	}
}

auto lookup(const vector<shared_ptr<robot>>& robots, int& robot_id) {
	auto lookup_robot = find_if(robots.cbegin(), robots.cend(),
		[robot_id](shared_ptr<robot> r) {return r->id() == robot_id; }); // returns iterator poiting to robot with matching id
	return *lookup_robot;
}

/*=============================
direction change implementation
===============================*/
void turn(const vector<shared_ptr<robot>>& robots, int robot_id, int direction) {
	auto r = lookup(robots, robot_id);
	switch (direction)
	{
	case 0: // turn left
		r->change_direction(0);
		cout << r->direction() << '\n';
		break;
	case 1: // turn right
		r->change_direction(1);
		cout << r->direction() << '\n';
		break;
	}
}

/*==================
move implemenation
===================*/
void move(const vector<shared_ptr<robot>>& robots, int robot_id) {
	auto r = lookup(robots, robot_id);
	r->increment_distance();
	r->make_move();
	cout << r->id() << ' ' << r->distance() << '\n';
}

/*=====================
within implemention
=====================*/
void within(const vector<shared_ptr<robot>>& robots, int n) {
	auto count = count_if(robots.cbegin(), robots.cend(),
		[&n](shared_ptr<robot> r) { return (abs((r->xpos())) + abs((r->ypos()))) <= n; }
	);
	cout << count << '\n';
}

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
			// within implementation
			within(robots, stoi(v[1]));
			// possible alg: find_if(), lambda?
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
			// move implementation
		}
	}

	cout << "Robot input:" << '\n' << '\n';

	for (const auto& r : robots) {
		cout << "Robot #" << r->id() << " from team " << r->team() << " is currently located at ("
			<< r->xpos() << ", " << r->ypos() << "), facing " << r->direction() << '.' << '\n';
	}

	return 0;
}
