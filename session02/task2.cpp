#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

/*=================================================
Task 2: Average excluding the first and last inputs
===================================================*/

int main()
{
    deque<double> v;
    double x;
    while (cin >> x)   
        v.push_back(x);
    
    auto n = v.size();
    
    if (n > 0) 
    {
        // sorting the vector
        sort(v.begin(), v.end());

        // remove highest and lowest values
        v.pop_back();
        v.pop_front();

        // compute average of remaining results
        auto n2 = v.size();
        float avg = 0;
        avg = accumulate(v.begin(), v.end(), 0) / n2;
        cout << "average = " << setprecision(3) << avg << '\n';
    }

    return 0;
}

