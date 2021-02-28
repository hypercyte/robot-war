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
		_direction = (--_direction % 4 + 4) % 4;
		break;
	case 1: // turn right
		_direction = (++_direction % 4 + 4) % 4;
		break;
	}
}

void robot::make_move() {
	switch (_direction)
	{
	case 0: // N y++
		_ypos++;
		break;
	case 1: // E x++
		_xpos++;
		break;
	case 2: // S y--
		_ypos--;
		break;
	case 3: // W x--
		_xpos--;
		break;
	}
}

void robot::undo_move() {
	switch (_direction)
	{
	case 0: // N 
		_ypos--;
		break;
	case 1: // E 
		_xpos--;
		break;
	case 2 :// S 
		_ypos++;
		break;
	case 3: // W 
		_xpos++;
		break;
	}
}
