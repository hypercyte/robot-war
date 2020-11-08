#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

bool isZero(double x) {
    return x == 0;
}

int countZeroes(const list<double>& l) {

    // Finding the position where the first 1 occurs. This returns the position of the first instance of the number 1.
    auto findOne = find(l.cbegin(), l.cend(), 1);
    return count(l.cbegin(), findOne, 0);
}

int main() {
    list<double> v = { 2, 0, 0, 2, 4, 6, 0, 3, 0, 0, 0, 1, 4, 0, 1 };
    cout << countZeroes(v) << "\n";
    return 0;
}