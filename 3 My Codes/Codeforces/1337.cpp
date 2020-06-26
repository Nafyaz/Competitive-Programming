#include<bits/stdc++.h>
using namespace std;

char grid[505][505];
int vis1[505][505], vis2[505][505];
int crystal, m, n;

void dfs1(int x, int y)
{

    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#' || vis1[x][y] == 1)
        return;

    if(grid[x][y] == 'C')
        crystal++;

    vis1[x][y] = 1;

//    printf("%d %d\n\n", x, y);
//    for(int i = 0; i < m; i++)
//    {
//        for(int j = 0; j < n; j++)
//            printf("%d", vis2[i][j]);
//        printf("\n");
//    }
//    printf("\n");


    dfs1(x+1, y);
    dfs1(x-1, y);
    dfs1(x, y+1);
    dfs1(x, y-1);
}

void dfs2(int x, int y)
{

    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#' || vis2[x][y] != -1)
        return;

    vis2[x][y] = crystal;

    dfs2(x+1, y);
    dfs2(x-1, y);
    dfs2(x, y+1);
    dfs2(x, y-1);
}

int main()
{
    int i, j, k, q, t, caseno = 0, x, y;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d %d\n", &m, &n, &q);
        for(i = 0; i < m; i++)
            scanf("%s", grid[i]);

        printf("Case %d:\n", ++caseno);

        memset(vis1, -1, sizeof(vis1));
        memset(vis2, -1, sizeof(vis2));

        for(i = 0; i < q; i++)
        {
            scanf("%d %d", &x, &y);

            if(vis1[x-1][y-1] == 1)
            {
                printf("%d\n", vis2[x-1][y-1]);
                continue;
            }
            crystal = 0;
            dfs1(x-1, y-1);
            dfs2(x-1, y-1);

//            for(j = 0; j < m; j++)
//            {
//                for(k = 0; k < n; k++)
//                    printf("%d", vis1[j][k]);
//                printf("\n");
//            }
//            printf("\n");
//
//            for(j = 0; j < m; j++)
//            {
//                for(k = 0; k < n; k++)
//                    printf("%d", vis2[j][k]);
//                printf("\n");
//            }
//            printf("\n");


            printf("%d\n", crystal);
        }
    }
}
