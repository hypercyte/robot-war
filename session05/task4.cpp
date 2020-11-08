#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// Counting empty strings
int count_empty(const vector<string>& v) {
    return count(v.cbegin(), v.cend(), "");
}

vector<string> sep_words(const string& s) {

    vector<string> v;

    // Push the first word...
    auto end = find(s.cbegin(), s.cend(), ',');
    v.push_back(string(s.begin(), end));

    // ...and the rest of them!
    while (end != s.cend()) {
        auto start = ++end;
        auto newEnd = find(start, s.cend(), ',');
        v.push_back(string(start, newEnd));
        end = newEnd;
    }

    return v;
}

int main()
{
    string str = "hello!,,,, ,how, ,are, ,you?,,";

    vector<string> v = sep_words(str);

    int emptyCount = count_empty(v);

    // &s is referencing every value of v (per loop)
    for (const auto& s : v) {
        cout << s << '\n';
    }

    cout << "Number of empty strings: " << emptyCount << '\n';
}

