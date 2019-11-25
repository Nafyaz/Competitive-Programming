#include<bits/stdc++.h>
using namespace std;
int n, m;
char grid[110][110];
void dfs(int i, int j, int color)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return;
    if(grid[i][j] != '.')
        return;

    color? grid[i][j] = 'W' : grid[i][j] = 'B';
    dfs(i-1, j, (color+1)%2);
    dfs(i+1, j, (color+1)%2);
    dfs(i, j-1, (color+1)%2);
    dfs(i, j+1, (color+1)%2);
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
            dfs(i, j, 0);   // 0 means black, 1 means white
    }

    for(i = 0; i < n; i++)
    {
        printf("%s", grid[i]);
        printf("\n");
    }
}
