#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.back() = 60;
    for(auto u : v)
        cout << u << " ";
}
