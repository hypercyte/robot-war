#include <iostream>
#include <list>

using namespace std;

void scale(double s, list<double>& vs) {
    for (auto &x : vs) {
        x = x * s;
    }
}

int main()
{
    list<double> l = { 1,2,3,4,5,6,7,8 };
    scale(2, l);

    for (auto& x : l) {
        cout << x << '\n';
    }
}