//
//	commands.cpp
//	Coursework: Robot War
//
//	Created by Mujahid Ahmed, 2020
//

#include "command_helper.h"
#include <algorithm>
#include <iostream>
#include <vector>

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
printing implemenation // 
(used for show and travelled commands)
sort_by: [
	0 = sort by id
	1 = sort by distance travelled
]
======================================*/
void print_robots(vector<shared_ptr<robot>>& robots, int sort_by) {
	sort_robots(robots, sort_by);
	for (auto& r : robots) {
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

// robot lookup function
auto lookup(const vector<shared_ptr<robot>>& robots, int& robot_id) {
	auto lookup_robot = find_if(robots.cbegin(), robots.cend(),
		[robot_id](shared_ptr<robot> r) {return r->id() == robot_id; }); // returns iterator poiting to robot with matching id
	return *lookup_robot;
}

// turnleft / turnright command(s)
void turn(const vector<shared_ptr<robot>> & robots, int robot_id, int direction) {
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

// move command
void move(vector<shared_ptr<robot>>& robots, int robot_id) {
	auto r = lookup(robots, robot_id);

	r->increment_distance();
	r->make_move();

	auto check_pos = find_if(robots.begin(), robots.end(),
		[&r](shared_ptr<robot> r2) {
			return (r2->id() != r->id()) && (r2->xpos() == r->xpos()) && (r2->ypos() == r->ypos());
		}
	);

	if (check_pos != robots.cend()) {
		cout << '\n' << "MATCH FOUND" << '\n' << '\n';
		robots.erase(check_pos);
	}
	cout << r->id() << ' ' << r->distance() << '\n';
}

// within command
void within(const vector<shared_ptr<robot>>& robots, int n) {
	auto count = count_if(robots.cbegin(), robots.cend(),
		[&n](shared_ptr<robot> r) { return (abs((r->xpos())) + abs((r->ypos()))) <= n; }
	);
	cout << count << '\n';
}

