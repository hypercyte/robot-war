#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int count_longer(const vector<string>& v, int n) {
    return count_if(v.cbegin(), v.cend(),
        [n](string x) { return x.size() > n; });
}

int main()
{
    vector<string> str = { "hello", " ", "how", "do", "you", "do", "here is a rly long string!!!!!", "wooooooo", "dont" };
    int length = 4;

    int count = count_longer(str, length);
    
    cout << "The number of words with more than " << length << " charatcers is: " << count << '\n';
}
