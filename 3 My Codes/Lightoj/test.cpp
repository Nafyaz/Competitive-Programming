#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> mp;

    mp[5] = 10;
    mp[100] = 50;

    for(int i = 0; i < mp.size(); i++)
        cout << i << ": " << mp[i] << "\n";
}
