#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

string grid[1009];
int dis[1009][1009], n, m;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

void init()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            dis[i][j] = INT_MAX;
    }
}

void dijkstra()
{
    init();

    dis[0][0] = 0;
    pair<int, int> p;
    queue<pair<int, int> > q;
    q.push({0, 0});

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int x = p.ff+dirx[i];
            int y = p.ss+diry[i];

            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;

            if(dis[x][y] > dis[p.ff][p.ss] + 1 && grid[x][y] != grid[p.ff][p.ss])
            {
                dis[x][y] = dis[p.ff][p.ss] + 1;
                q.push({x, y});
            }
            else if(dis[x][y] > dis[p.ff][p.ss] && grid[x][y] == grid[p.ff][p.ss])
            {
                dis[x][y] = dis[p.ff][p.ss];
                q.push({x, y});
            }
        }
    }
}

int main()
{
    freopen("out.txt", "w", stdout);
    int t, caseno = 0, i, j;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i = 0; i < n; i++)
            cin >> grid[i];
        dijkstra();

        cout << "Case " << ++caseno << ": " << dis[n-1][m-1] << endl;
    }
}
