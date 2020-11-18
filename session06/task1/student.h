#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

// record of a student's marks in a module
class student {
	std::string n; // student name
	double exam; // exam mark
	std::vector<double> tasks; // marks for coursework tasks

public:
	// Initialize student info
	student(const std::string& name, double e);
	// The name of the student
	const std::string& name() const { return n; }
	// Add a task mark
	void add_task(double m);
	// The total mark for the module
	double mark() const;

private:
	// The coursework mark for the module
	double coursework() const;
};

// Has the student passed the module?
bool passed(const student& s);

// Less-than comparison of student names
bool compare_names(const student& x, const student& y);

#endif
