#include "student.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Split a string containing comma-separated values
vector<string> split_csv(const string& s) {
	vector<string> v;
	auto comma = find(s.cbegin(), s.cend(), ',');
	v.push_back(string(s.cbegin(), comma));
	while (comma != s.cend()) {
		auto start = ++comma;
		comma = find(start, s.cend(), ',');
		v.push_back(string(start, comma));
	}
	return v;
}

int main() {
	vector<student> students;

	// read and store the data
	string line;
	while (cin >> line) {
		auto v = split_csv(line);
		students.push_back(student(v[0], stod(v[1])));
		student& s = students.back();
		for (vector<string>::size_type i = 2; i < v.size(); ++i)
			s.add_task(stod(v[i]));
	}

	// arrange the student records in alphaetical order
	sort(students.begin(), students.end(), compare_names);

	cout << "Passing students: " << '\n';
	// write the names and total marks
	streamsize prec = cout.precision();
	for (const student& s : students) {
		if (passed) {
			cout << s.name() << ": " <<
				setprecision(3) << s.mark() <<
				setprecision(prec) << '\n';
		}
	}

	cout << '\n' << "Failed students: " << '\n';
	// write the names and total marks
	for (const student& s : students) {
		if (!passed) {
			cout << s.name() << ": " <<
				setprecision(3) << s.mark() <<
				setprecision(prec) << '\n';
		}
	}

	cout << count_if(students.cbegin(), students.cend(), passed) <<
		" passed out of " << students.size() << '\n';

	return 0;
}