#include<bits/stdc++.h>
using namespace std;

int w, h;
char grid[100][100];

void dfs(int i, int j)
{
    if(i < 0 || i >= h || j < 0 || j >= w)
        return;
    if(grid[i][j] == '#' || grid[i][j] == '@')
        return;

    grid[i][j] = '@';

    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int main()
{
    int t, caseno = 0, i, j, posi, posj;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &w, &h);
        for(i = 0; i < h; i++)
        {
            getchar();
            for(j = 0; j < w; j++)
            {
                scanf("%c", &grid[i][j]);
                if(grid[i][j] == '@')
                {
                    posi = i;
                    posj = j;
                }
            }
        }

        grid[posi][posj] = '.';
        dfs(posi, posj);

        int ans = 0;

        //printf("%d %d\n", w, h);
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < w; j++)
            {
                //printf("%c", grid[i][j]);
                if(grid[i][j] == '@')
                    ans++;
            }
            //printf("\n");
        }
        printf("Case %d: %d\n", ++caseno, ans);
    }
}
