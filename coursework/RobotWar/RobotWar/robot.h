//
//	robot.h
//	Coursework: Robot War
//
//	Created by Mujahid Ahmed, 2020
//
//	1 reminder

#ifndef ROBOT_H
#define ROBOT_H

class robot {
	// robot data members
	int _id;
	int _team;
	int _xpos;
	int _ypos;
	int _distance = 0;
	int _direction = 0;	
	// directions:
	// N, E, S, W
	// 0, 1, 2, 3

public:
	// robot constructor
	robot(int id, int t, int x, int y) : 
		_id(id), _team(t), _xpos(x), _ypos(y) {}

	int id() const { return _id; }
	int team() const { return _team; }
	int xpos() const { return _xpos; }
	int ypos() const { return _ypos; }
	int distance() const { return _distance; }
	int direction() const { return _direction; }
	// REMINDER TO REMOVE ANY UNUSED //

	void increment_distance();

	void change_direction(int i); // i: 0 = left, 1 = right

	void make_move();

	void undo_move();

};

#endif // !ROBOT_H
