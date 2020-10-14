#include <iostream>
#include <vector>

using namespace std;

/*=====================================
Task 4: Output the longest word inputted
=======================================*/

int main()
{
    // input
    vector<string> str;
    string x;
    int max = 0;
    while (cin >> x) 
    {
        // if inputted string has more characters than the last
        if (x.length() > max) 
        {   
            // remove previous element (if there is one)
            if (str.size() != 0)
            {
                str.pop_back();
            }
            // add new element
            str.push_back(x);
            // set new maximum char count
            max = x.length();
        }
    }

    // output
    cout << "Longest word: ";
    for (auto i = str.begin(); i != str.end(); i++) {
        cout << *i;
    }

    return 0;
}