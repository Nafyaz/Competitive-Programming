#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, pair<int, int> > pii;

int grid[109][109], vis[109][109];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, i, j, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if(i == 0 || j == 0 || i == n - 1|| j == m - 1)
                    pq.push({grid[i][j], {i, j}});
                vis[i][j] = 0;
            }
        }

        pii p;
        int ans = 0, h, x, y, dirx[4] = {-1, 0, 1, 0}, diry[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        pair<int, int> p2;
        while(!pq.empty())
        {
            p = pq.top();
            pq.pop();
            h = p.ff;
            x = p.ss.ff;
            y = p.ss.ss;
            vis[x][y] = 1;
            q.push({x, y});
            while(!q.empty())
            {
//            cout << "lol";
                p2 = q.front();
                q.pop();
                x = p2.ff;
                y = p2.ss;

                for(i = 0; i < 4; i++)
                {
                    int u = x + dirx[i];
                    int v = y + diry[i];
                    if(u >= 0 && u < n && v >= 0 && v < m)
                    {
                        if(!vis[u][v] && grid[u][v] < h)
                        {
                            q.push({u, v});
                            ans += h - grid[u][v];
                            vis[u][v] = 1;
                        }
                        else if(!vis[u][v])
                        {
                            pq.push({grid[u][v], {u, v}});
                            vis[u][v] = 1;
                        }

                    }

                }
            }
        }

        cout << ans << endl;
    }
}
