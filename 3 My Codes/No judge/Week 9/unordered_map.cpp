#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> mp;
//    map<int, int> mp;

    mp[4] = 10;
    mp[700] = 70;
    mp[29] = -6;
    mp[20] = 30;

    for(auto u : mp)
        cout << u.first << " " << u.second << "\n";
}
