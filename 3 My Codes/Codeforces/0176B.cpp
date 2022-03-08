#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

map<string, ll> mp;
ll adjM[1003][1003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string st, ed, temp;
    ll i, k, cnt = 0;

    cin >> st >> ed >> k;

    if(mp.find(st) == mp.end())
        mp[st] = ++cnt;
    if(mp.find(ed) == mp.end())
        mp[ed] = ++cnt;

    temp = st;
    for(i = 1; i < n; i++)
    {
        rotate(temp.begin(), temp.end());
        if(mp.find(temp) == mp.end())
            mp[temp] = ++cnt;
    }

    for(auto u : mp)
    {
        temp = u.ff;
        for(i = 1; i < n; i++)
        {
            rotate(temp.begin(), temp.end());
            adjM[mp[u.ff]][temp]++;
        }
    }


}
