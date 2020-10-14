#include <iostream>
#include <vector>

using namespace std;

/*=================
Task 3: Word count
===================*/

int main()
{
    // input
    vector<string> str;
    string x;
    while (cin >> x)
        str.push_back(x);

    // present input + count words
    int count = 0;
    cout << "Your input: ";
    for (auto i = str.begin(); i != str.end(); i++) {
        cout << *i << ' ';
        ++count;
    }

    // present word count
    cout << "\nWord count: " << count << endl;

    return 0;
}