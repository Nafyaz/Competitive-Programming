#include<bits/stdc++.h>
using namespace std;

int p[100009];

int Find(int u)
{
    if(u == p[u])
        return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v)
{
    int x = Find(u), y = Find(v);
    if(x == y)
        return;
    p[x] = y;
}

int main()
{
    int t, i, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i <= n; i++)
            p[i] = i;
        cin >> s >> u >> v;
        if(s == "c")
            Union(u, v);
        if()
    }
}
