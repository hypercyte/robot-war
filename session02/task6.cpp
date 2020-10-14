#include <iostream>
#include <iomanip>

using namespace std;

/*======================================
TASK 6: O(1) space, O(n) time attempt (?)
========================================*/

int main()
{
    double x;
    double min = 0;
    double max = 0;
    double count = 0;
    double total = 0;
    while (cin >> x)
    {
        if (x < min) 
        {
            min = x;
        }
        else if (x > max) 
        {
            max = x;
        }
        ++count;
        total += x;
    }

    // output
    auto avg = 0;
    avg = (total - min - max) / (count - 2);
    cout << "average = " << setprecision(3) << avg << '\n';

    return 0;
}

/* notes:
 
* so for O(1) space, we could get input, add it to a variable then remove it

* store lowest value and highest value using if statements
* store count too

* space overall should stay constant that way i think?

* after that, we can use that var to find average using count var*/

