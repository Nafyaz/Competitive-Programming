#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v, u;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    u = v + 1;

    for(auto x : u)
        cout << x;
}
