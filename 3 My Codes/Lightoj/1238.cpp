#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int loop[4] = {-1, 0, 1, 0};
int n, m, vis[25][25];
char grid[25][25];

bool push_this(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == -1 && grid[i][j] != '#')
        return 1;
    return 0;
}

int bfs(int i, int j)
{
    pair<int, int> point, point2;
    queue <pair<int, int> > q;
    q.push({i, j});
    vis[i][j] = 0;

    while(!q.empty())
    {
        point = q.front();
//        printf("%d %d\n", point.ff, point.ss);
        q.pop();

        if(grid[point.ff][point.ss] == 'h')
            return vis[point.ff][point.ss];

        for(int i = 0; i < 4; i++)
        {
            point2.ff = point.ff + loop[i];
            point2.ss = point.ss + loop[(i+1)%4];

            if(push_this(point2.ff, point2.ss))
            {
                q.push(point2);
                vis[point2.ff][point2.ss] = vis[point.ff][point.ss] + 1;
            }
        }
    }
}

int main()
{
    int i, j, t, caseno = 0, ax[3], ay[3];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
        {
            scanf("%s", grid[i]);
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == 'm')
                    grid[i][j] = '#';
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'c')
                {
                    ax[grid[i][j] - 'a'] = i;
                    ay[grid[i][j] - 'a'] = j;

                    grid[i][j] = '.';
                }
            }
        }
        int mx = -1, temp;
        for(i = 0; i < 3; i++)
        {
            memset(vis, -1, sizeof(vis));
//            printf("%d\n", i);
            int temp = bfs(ax[i], ay[i]);
            mx = max(mx, temp);
//            printf("%d\n", temp);
        }
        printf("Case %d: %d\n", ++caseno, mx);
    }
}
