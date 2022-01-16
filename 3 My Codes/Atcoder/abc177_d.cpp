#include<bits/stdc++.h>
using namespace std;

int par[200005];
int sz[200005];

int Find(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x == y)
        return;

    if(sz[x] > sz[y])
    {
        par[y] = x;
        sz[x] += sz[y];
    }
    else
    {
        par[x] = y;
        sz[y] += sz[x];
    }
}

int main()
{
    int n, m, i, a, b, ans;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;
        Union(a, b);
    }

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        if(par[i] == i)
            ans = max(ans, sz[i]);
    }

    cout << ans;
}

