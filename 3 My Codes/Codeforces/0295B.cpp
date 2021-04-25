#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll adj[509][509];
ll x[509];
ll ans[509];
bool vis[509];

int main()
{
    ll i, j, k, p, n;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cin >> adj[i][j];
    }

    for(i = 1; i <= n; i++)
        cin >> x[i];

    for(p = n; p >= 1; p--)
    {
        k = x[p];
        vis[k] = 1;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

                if(vis[i] && vis[j])
                    ans[p] += adj[i][j];
            }
        }
    }

    for(p = 1; p <= n; p++)
        cout << ans[p] << " ";
}
