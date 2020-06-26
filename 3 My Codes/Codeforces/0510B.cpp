#include<bits/stdc++.h>
using namespace std;

int n, m, vis[100][100], flag = 0;
char grid[100][100];

void dfs(char c, int x, int y, int xdir, int ydir)
{
    if(flag)
        return;
    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != c)
        return;

    if(vis[x][y])
    {
        flag = 1;
        return;
    }

    vis[x][y] = 1;

    if(!(xdir == -1 && ydir == 0))
        dfs(c, x+1, y, 1, 0);
    if(!(xdir == 1 && ydir == 0))
        dfs(c, x-1, y, -1, 0);
    if(!(xdir == 0 && ydir == -1))
        dfs(c, x, y+1, 0, 1);
    if(!(xdir == 0 && ydir == 1))
        dfs(c, x, y-1, 0, -1);
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);

    for(i = 0; i < n; i++)
        scanf("%s", grid[i]);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(vis[i][j] == 0)
                dfs(grid[i][j], i, j, 0, 0);

            if(flag)
            {
                printf("Yes");
                return 0;
            }
        }
    }

    printf("No");
}
