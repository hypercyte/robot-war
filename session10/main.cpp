#include "point.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	point pt(2, 3);

	circle s1(point(1, 3), 5);
	rectangle s2(point(6, 2), 4, 3);

	vector<shared_ptr<shape>> scene;

	cout << s1.description() << '\n';
	cout << s2.description() << '\n';

	// Task 1
	for (int i = 0; i <= 10; i++) {
		scene.push_back(make_shared<circle>(point(i, 1), 10)
		);
	}
	
	for (const shared_ptr<shape>& p : scene) {
		if (p->contains(point(5,8))) {
			cout << p->description() << '\n';
		}
	}

	return 0;
}
