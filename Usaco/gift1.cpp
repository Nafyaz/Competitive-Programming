/*
ID: nafis.f1
TASK: gift1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int n, i, j, g, x, m;
    string s, name[15];
    map<string, int> mp;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> s;
        mp[s] = 0;
        name[i] = s;
    }

    for(i = 0; i < n; i++)
    {
        cin >> s >> m >> g;
        if(g != 0)
            mp[s] += -m + m%g;
        for(j = 0; j < g; j++)
        {
            cin >> s;
            mp[s] += m/g;
        }
    }

    for(j = 0; j < n; j++)
        cout << name[j] << " " << mp[name[j]] << endl;

}
