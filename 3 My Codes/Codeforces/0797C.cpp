#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main()
{
    int i, j, k;
    string s, t, u, temp;
    cin >> s;

    map <char, int> mp;

    for(auto u : s)
        mp[u]++;

    for(auto u : mp)
    {
        if(u.ss == 0)
            continue;
        for(i = 0; i < s.size(); i++)
        {
            mp[u]--;
            if(s[i] == u.ff)
            {
                temp = s.substr(0, i + 1);
                t = t +  ;
                break;
            }
        }
    }

}
