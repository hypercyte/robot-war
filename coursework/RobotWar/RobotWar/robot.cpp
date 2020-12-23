//
//	robot.cpp
//	Coursework: Robot War
//
//	Created by Mujahid Ahmed, 2020
//

#include "robot.h"

void robot::increment_distance() {
	_distance++;
}

void robot::change_direction(int i) {
	switch (i)
	{
	case 0: // turn left
		_direction = (_direction - 1) % 4;
		break;
	case 1: // turn right
		_direction = (_direction + 1) % 4;
		break;
	}
}

void robot::make_move() {
	switch (_direction)
	{
	case 0: // North y++
		_ypos++;
		break;
	case 1: // East x++
		_xpos++;
		break;
	case 2: // South y--
		_ypos--;
		break;
	case 3: // West x--
		_xpos--;
		break;
	}
}

void robot::undo_move() {
	switch (_direction)
	{
	case 0: // North y++
		_ypos--;
		break;
	case 1: // East x++
		_xpos--;
		break;
	case 2: // South y--
		_ypos++;
		break;
	case 3: // West x--
		_xpos++;
		break;
	}
}


// define member functions
