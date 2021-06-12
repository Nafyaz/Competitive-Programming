#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcdae";
    set<char> schar;

    for(auto u : s)
        schar.insert(u);

    for(auto u : schar)
        cout << u << " ";
}
