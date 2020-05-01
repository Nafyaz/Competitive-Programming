#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, a, b, c, p[200009], csum[200009];
ll dis[200009][3];
bool vis[200009][3];
vector<ll> adj[200009];

void bfs(ll s, ll i)
{
    vis[s][i] = 1;
    queue<ll> q;
    dis[s][i] = 0;
    q.push(s);

    ll p;

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(auto u : adj[p])
        {
            if(vis[u][i])
                continue;
            dis[u][i] = dis[p][i] + 1;
            vis[u][i] = 1;
            q.push(u);
        }
    }
}

int main()
{
    ll t, i, j, u, v;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> a >> b >> c;

        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            for(j = 0; j < 3; j++)
            {
                dis[i][j] = 0;
                vis[i][j] = 0;
            }
        }


        for(i = 1; i <= m; i++)
            cin >> p[i];
        sort(p+1, p+m+1);
        for(i = 1; i <= m; i++)
        {
            csum[i] = csum[i-1] + p[i];
//            cout << csum[i] << " ";
        }


        for(i = 0; i < m; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(a, 0);
        bfs(b, 1);
        bfs(c, 2);

        ll ans = LLONG_MAX, x, y;
        for(i = 1; i <= n; i++)
        {
            x = dis[i][1];
            y = dis[i][0] + dis[i][1] + dis[i][2];

//            cout << i << ": " << x << " " << y << " " << csum[x] + csum[y] << endl;

            if(y <= m)
                ans = min(ans, csum[x] + csum[y]);
        }

        cout << ans << endl;
    }
}
