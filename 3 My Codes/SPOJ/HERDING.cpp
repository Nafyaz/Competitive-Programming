#include<bits/stdc++.h>
using namespace std;

int n, m;
string grid[1009];

int color[1009][1009], ans;

int dfs(int i, int j)
{
    if(color[i][j] == -1)
        return color[i][j] = ++ans;
    else if(color[i][j] != 0)
        return color[i][j];

    color[i][j] = -1;

    if(grid[i][j] == 'N')
        return color[i][j] = dfs(i-1, j);
    else if(grid[i][j] == 'S')
        return color[i][j] = dfs(i+1, j);
    else if(grid[i][j] == 'E')
        return color[i][j] = dfs(i, j+1);
    else
        return color[i][j] = dfs(i, j-1);
}

int main()
{
    int i, j;

    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> grid[i];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(color[i][j] == 0)
                dfs(i, j);
        }
    }

    cout << ans;
}

