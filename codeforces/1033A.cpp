#include<bits/stdc++.h>
using namespace std;
int n, grid[1010][1010], found = 0, cx, cy;

void print_grid()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
void dfs(int x, int y)
{
    if(found)
        return;
    if(x < 1 || x > n || y < 1 || y > n)
        return;

    if(grid[x][y] == 1)
        return;
    grid[x][y] = 1;


    if(x == cx && y == cy)
    {
        found = 1;
        return;
    }


    dfs(x-1, y-1);
    dfs(x-1, y);
    dfs(x-1, y+1);
    dfs(x, y-1);
    dfs(x, y+1);
    dfs(x+1, y-1);
    dfs(x+1, y);
    dfs(x+1, y+1);
}

int main()
{
    int i, j;
    scanf("%d", &n);

    int ax,ay, bx, by;
    scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == ax || j == ay || abs(ax - i) == abs(ay - j))
                grid[i][j] = 1;
        }
    }

    //print_grid();
    dfs(bx, by);
    if(found)
        printf("YES");
    else
        printf("NO");
}
