#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

vector <pair<int, pair<int, int>> > lakes;
int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};
int n, m, vis[60][60], is_lake, lake_size;
char grid[60][60];

void find_lake(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == 1 || grid[i][j] == '*')
        return;

    if(i == 0 || i == n-1 || j == 0 || j == m-1)
            is_lake = 0;

    lake_size ++;
    vis[i][j] = 1;

    for(int k = 0; k < 4; k++)
        find_lake(i+dirx[k], j+diry[k]);
}

void fillup(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m  || grid[i][j] == '*')
        return;

    grid[i][j] = '*';

    for(int k = 0; k < 4; k++)
        fillup(i+dirx[k], j+diry[k]);

}

int main()
{
    int k, i, j;
    scanf("%d %d %d", &n, &m, &k);

    for(i = 0; i < n; i++)
        scanf("%s", grid[i]);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(vis[i][j] == 0 && grid[i][j] == '.')
            {
                is_lake = 1;
                lake_size = 0;
                find_lake(i, j);

                if(is_lake == 1)
                    lakes.push_back({lake_size, {i, j}});
            }
        }
    }

    sort(lakes.begin(), lakes.end());

    i = 0;
    int ans = 0;
    while(k != lakes.size())
    {
        ans += lakes[i].ff;
        k++;
        fillup(lakes[i].ss.ff, lakes[i].ss.ss);
        i++;
    }

    printf("%d\n", ans);
    for(i = 0; i < n; i++)
        printf("%s\n", grid[i]);
}
