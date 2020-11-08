#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

bool evenNumber(int x) {
    return x % 2 == 0;
}

void removeEven(list<int>& l) {
    l.erase(remove_if(l.begin(), l.end(), evenNumber), l.end());
}

void removeEvenLambda(list<int>& l) {
    l.erase(remove_if(l.begin(), l.end(), 
        [](int x) { return x % 2 == 0; }),
        l.end());
}

int main() {
    list<int> v = { -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    list<int> vL = { -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    removeEven(v);
    removeEvenLambda(vL);

    cout << "Regular output: \n";
    for (int& i : v) {
        cout << i << '\n';
    }

    cout << "\nLambda expression output: \n";
    for (int& i : vL) {
        cout << i << '\n';
    }

    return 0;
}