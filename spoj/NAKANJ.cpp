#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

bool vis[8][8];
int dis[8][8];
int dirx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int diry[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int x, int y, int a, int b)
{
//    cout << x << " " << y << endl << a << " " << b << endl;
    vis[x][y] = 1;
    dis[x][y] = 0;

    queue<pair<int, int>> q;
    pair<int, int> p;
    q.push({x, y});

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p.ff == a && p.ss == b)
            return dis[a][b];
        for(int i = 0; i < 8; i++)
        {
            int u = p.ff + dirx[i];
            int v = p.ss + diry[i];
            if(u >= 0 && u < 8 && v >= 0 && v < 8 && !vis[u][v])
            {
                q.push({u, v});
                vis[u][v] = 1;
                dis[u][v] = dis[p.ff][p.ss] + 1;
            }
        }
    }
}

int main()
{
    int t, i, j;
    string a, b;
    cin >> t;
    while(t--)
    {
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        cin >> a >> b;
        cout << bfs(a[0]-'a', a[1]-'1', b[0]-'a', b[1]-'1') << endl;
    }
}
