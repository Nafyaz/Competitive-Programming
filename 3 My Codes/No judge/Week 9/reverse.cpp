#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);

    for(auto u : v)
        cout << u << " ";
    cout << "\n\n";
//
    reverse(v.begin(), v.end());
    for(auto u : v)
        cout << u << " ";
    cout << "\n";
}
