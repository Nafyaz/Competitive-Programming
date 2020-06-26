#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i;
    cin >> n >> m;

    string u, v;
    map <string, string> mp;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        mp[u] = v;
    }

    for(i = 0; i < n; i++)
    {
        cin >> u;
        if(mp[u].size() < u.size())
            cout << mp[u] << " ";
        else
            cout << u << " ";
    }
}
