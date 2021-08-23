#include<bits/stdc++.h>
using namespace std;

int n;
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};

string grid[35];

int vis[35][35];

int dfs(int x, int y)
{
    if(vis[x][y])
        return 0;

    vis[x][y] = 1;

    int i, x2, y2, ret = 0;
    for(i = 0; i < 4; i++)
    {
        x2 = x + dirx[i];
        y2 = y + diry[i];

        if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= n || grid[x2][y2] == '#')
        {
            ret++;
            continue;
        }

        ret += dfs(x2, y2);
    }

    return ret;
}

int main()
{
    int i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> grid[i];

    cout << (dfs(0, 0) + dfs(n-1, n-1) - 4) * 9 << "\n";
}
