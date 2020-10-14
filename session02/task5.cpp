#include <iostream>
#include <deque>

using namespace std;

/*=========================
Task 5: Reversing the input
==========================*/

int main()
{
    // input
    deque<string> str;
    string x;
    while (cin >> x)
    {   
        // pushing front so output will appear reversed
        str.push_front(x);
    }

    // output
    cout << "Input reversed:\n";
    for (auto i = str.begin(); i != str.end(); i++) {
        cout << *i << '\n';
    }

    return 0;
}