#include<bits/stdc++.h>
using namespace std;

int n, m;
int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};
bool visited[102][102];
int color[102][102];

string grid[102];

int sectorSize(int x, int y)
{
    cout << x << " " << y << "\n";
    int ret = 1;

    visited[x][y] = 1;

    for(int i = 0; i < 4; i++)
    {
        int xNew = x + dirx[i];
        int yNew = y + diry[i];

        if(xNew < 0 || xNew >= n || yNew < 0 || yNew >= m || visited[xNew][yNew] || grid[xNew][yNew] == '#')
            continue;

        ret += sectorSize(xNew, yNew);
    }

    return ret;
}

void conn_comp(int x, int y, int c)
{
    color[x][y] = c;

    for(int i = 0; i < 4; i++)
    {
        int xNew = x + dirx[i];
        int yNew = y + diry[i];

        if(xNew < 0 || xNew >= n || yNew < 0 || yNew >= m || color[xNew][yNew] || grid[xNew][yNew] == '#')
            continue;

        conn_comp(xNew, yNew, c);
    }

    return;
}

int main()
{
    int i, j;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> grid[i];

    memset(visited, 0, sizeof visited);
    cout << sectorSize(0, 0);


    int ans = 0;
    memset(color, 0, sizeof color);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(!color[i][j] && grid[i][j] != '#')
            {
                conn_comp(i, j, ans+1);
                ans++;
            }
        }
    }
}
/*
2 5
..#..
#.#.#
*/
