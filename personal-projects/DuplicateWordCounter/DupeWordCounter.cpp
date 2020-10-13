// DupeWordCounter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std; 

int main()
{

    vector<string> names;
    vector<int> count;

    ifstream file("words.txt");

    string str;

    if (!file)
    {
        cerr << "Couldn't open the file";
        return 0;
    }

    while (getline(file, str))
    {
        if (str.size() > 0)
        {
            names.push_back(str);

            int num = 0;
            for (vector<string>::iterator i = names.begin(); i != names.end(); ++i)
            {
                if (*i == str) 
                {
                    num++;
                }
            }
            count.push_back(num);
        }
    }

    file.close();



    int pos = 0;
    for (vector<string>::iterator i = names.begin(); i != names.end(); ++i)
    {
        cout << *i << ' ';
        cout << count[pos] << '\n';
        pos++;
    }

    //for (vector<int>::iterator i = count.begin(); i != count.end(); ++i)
    //{
    //    cout << *i << '\n';
    //}

    return 0;
}
