//
//	robot.h
//	Coursework: Robot War
//
//	Created by Mujahid Ahmed, 2020
//
//  1 reminder

#ifndef ROBOT_H
#define ROBOT_H

class robot {
	// robot data members
	int _id;
	int _team;
	int _xpos;
	int _ypos;
	int _distance;
	int _direction;	
	// directions:
	// N, E, S, W
	// 0, 1, 2, 3

public:
	// robot constructor
	robot(int id, int t, int x, int y, int dist, int dir) : 
		_id(id), _team(t), _xpos(x), _ypos(y), _distance(dist), _direction(dir) {}

	int id() const { return _id; }
	int team() const { return _team; }
	int xpos() const { return _xpos; }
	int ypos() const { return _ypos; }
	int distance() { return _distance; }
	int direction() const { return _direction; }
	// REMINDER TO REMOVE ANY UNUSED //

};

#endif // !ROBOT_H
