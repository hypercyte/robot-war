#include "student.h"
#include "stats.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const double exam_weight = 0.7;
const double pass_mark = 40;

// Initialize student info
student::student(const string &name, double e) : n(name), exam(e) {}

// Add a task mark
void student::add_task(double m) {
	tasks.push_back(m);
}

double student::mark() const {
	return exam_weight*exam + (1 - exam_weight)*coursework();
}

double student::coursework() const {
	if (tasks.size() == 0)
		return 0;
	vector<double> topThree = tasks;
	sort(topThree.begin(), topThree.end(), greater<double>());
	while (topThree.size() > 3) {
		topThree.pop_back();
	}
	return average(topThree);
}

bool passed(const student& s) {
	return s.mark() >= pass_mark;
}

bool compare_names(const student& x, const student& y) {
	return x.name() < y.name();
}