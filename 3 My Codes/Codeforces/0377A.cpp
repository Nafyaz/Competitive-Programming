#include<bits/stdc++.h>
using namespace std;

int n, m, k, vis[505][505];
char grid[505][505];

void dfs(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || vis[x][y] == 1)
        return;

    vis[x][y] = 1;

    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);

    if(k)
    {
        grid[x][y] = 'X';
        k--;
    }
}

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &m, &k);

    for(i = 0; i < n; i++)
        scanf("%s", grid[i]);

    int flag = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == '.')
            {
                dfs(i, j);
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%c", grid[i][j]);
        printf("\n");
    }
}
