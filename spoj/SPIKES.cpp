#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, m, j, dis[50][50];
string grid[50];

void init()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            dis[i][j] = 100000;
    }
}

void dijkstra(int x, int y)
{
    init();

    pair<int, pair<int, int> > p;
    priority_queue<pair<int, pair<int, int> >> pq;
    pq.push({0, {x, y}});
    dis[x][y] = 0;

    int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, 1, 0, -1};

    while(!pq.empty())
    {
        p = pq.top();
        pq.pop();

        for(int i = 0; i < 4; i++)
        {
            x = p.ss.ff + dirx[i];
            y = p.ss.ss + diry[i];
            if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#')
                continue;

            if(grid[x][y] == 's' && dis[x][y] > dis[p.ss.ff][p.ss.ss] + 1)
            {
                dis[x][y] = dis[p.ss.ff][p.ss.ss] + 1;
                pq.push({dis[x][y], {x, y}});
            }
            else if((grid[x][y] == '.' || grid[x][y] == 'x') && dis[x][y] > dis[p.ss.ff][p.ss.ss])
            {
                dis[x][y] = dis[p.ss.ff][p.ss.ss];
                pq.push({dis[x][y], {x, y}});
            }
        }
    }
}

int main()
{
    int i, j, x, y, s, p, q;
    cin >> n >> m >> s;

    for(i = 0; i < n; i++)
    {
        cin >> grid[i];
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == '@')
            {
                x = i;
                y = j;
            }
            else if(grid[i][j] == 'x')
            {
                p = i;
                q = j;
            }
        }
    }

//    cout << x << " " << y << endl << p << " " << q << endl;

    dijkstra(x, y);

//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < m; j++)
//            cout << setw(10) << dis[i][j] << " ";
//        cout << endl;
//    }

    cout << (2*dis[p][q] <= s? "SUCCESS" : "IMPOSSIBLE") << endl;
}
/*
2 3 0
@sx
...
*/
