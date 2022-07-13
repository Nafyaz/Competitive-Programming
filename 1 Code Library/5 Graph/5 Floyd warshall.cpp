ll n;
vector <pair<ll, ll>> adj[MAXN];
ll dis[MAXN][MAXN];

void floyd_warshall()
{
    ll i, j, k;

    memset(dist, -1, sizeof dist);
    for(i = 1; i <= n; i++)
    {
        dist[i][i] = 0;

        for(auto u : adj[i])
        {
            if(dist[i][u.ss] == -1)
                dist[i][u.ss] = dist[u.ss][i] = c;
            else
                dist[i][u.ss] = dist[u.ss][i] = min(dist[i][u.ss], u.ff);
        }
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(dist[i][k] != -1 && dist[k][j] != -1)
                {
                    if(dist[i][j] == -1)
                        dist[i][j] = dist[i][k] + dist[k][j];
                    else
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}