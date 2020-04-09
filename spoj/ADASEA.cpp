#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, vis[1009][1009];
string grid[1009];
ll dirx[4] = {-1, 0, 1, 0};
ll diry[4] = {0, -1, 0, 1};

ll dfs(ll i, ll j)
{
    ll ret = 1;
    vis[i][j] = 1;
    for(ll k = 0; k < 4; k++)
    {
        ll x = i + dirx[k];
        ll y = j + diry[k];

        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '~' || vis[x][y])
            continue;

        ret += dfs(x, y);
    }

    return ret;
}

int main()
{
    ll t, i, j, p, q, g, sz;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        memset(vis, 0, sizeof vis);

        for(i = 0; i < n; i++)
            cin >> grid[i];

        p = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == '#' && vis[i][j] == 0)
                {
                    sz = dfs(i, j);
                    p = p + sz*sz;
                }
            }
        }
        q = n*m;

        g = __gcd(p, q);
        p = p/g;
        q = q/g;

        if(q == 1)
            cout << p << endl;
        else
            cout << p << " / " << q << endl;
    }
}
