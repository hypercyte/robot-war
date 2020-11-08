#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

bool negativeNumber(double x) {
    return x < 0;
}

int negativeCount(const list<double>& l) {
    return count_if(l.cbegin(), l.cend(), negativeNumber);
}

int negativeCountLambda(const list<double>& l) {
    return count_if(l.cbegin(), l.cend(),
        [](double x) { return x < 0; });
}

int main() {
    list<double> v = { -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    cout << "Without lambda expression: \n" << negativeCount(v) << "\n\n";
    cout << "Lambda expression: \n" << negativeCountLambda(v) << "\n\n";
    return 0;
}