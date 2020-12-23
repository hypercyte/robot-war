//
//	command_helper.h
//	Coursework: Robot War
//
//	Created by Mujahid Ahmed, 2020
//

#ifndef COMMAND_HELPER
#define COMMAND_HELPER

#include "robot.h"
#include <vector>
#include <memory>

// command helpers
void sort_robots(std::vector<std::shared_ptr<robot>>& robots, int& sort_by);
void print_robots(std::vector<std::shared_ptr<robot>>& robots, int sort_by);
auto lookup(const std::vector<std::shared_ptr<robot>>& robots, int& robot_id);

// command actions
void within(const std::vector<std::shared_ptr<robot>>& robots, int n);
void turn(const std::vector<std::shared_ptr<robot>>& robots, int robot_id, int direction);
void move(std::vector<std::shared_ptr<robot>>& robots, int robot_id);


#endif // !COMMAND_HELPER


