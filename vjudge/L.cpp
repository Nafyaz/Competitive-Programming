#include<bits/stdc++.h>
using namespace std;

int n, m;
int dirx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diry[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_inside(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return 0;
    return 1;
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
    bool adj[110] = {0};
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(a[i][j] == -1 || adj[a[i][j]])
                continue;
            for(int x = 0; x < 8; x++)
            {
                if(is_inside(i+dirx[x], j+diry[x]) && a[i][j] == a[i+dirx[x]][j+diry[x]])
                    adj[a[i][j]] = 1;
            }
        }
    }

    int total = 0;
    for(i = 0; i < 110; i++)
        total += adj[i];
    printf("%d", total);
}
