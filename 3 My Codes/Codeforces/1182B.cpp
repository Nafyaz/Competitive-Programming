#include<bits/stdc++.h>
using namespace std;

bool found = 0;
char grid[600][600];
int h, w, l, r, u, d, cx, cy;

int rayl(int i, int j)
{
    //printf("%d %d %c\n", i, j, grid[i][j]);
    if(grid[i][j] == '*' && j > 0)
        return rayl(i, j-1);
    else if(grid[i][j] == '*')
        return j;
    else
        return j+1;
}

int rayr(int i, int j)
{
    if(grid[i][j] == '*' && j < w-1)
        return rayr(i, j+1);
     else if(grid[i][j] == '*')
        return j;
    else
        return j-1;
}

int rayu(int i, int j)
{
    if(grid[i][j] == '*' && i > 0)
        return rayu(i-1, j);
    else if(grid[i][j] == '*')
        return i;
    else
        return i+1;
}

int rayd(int i, int j)
{
    if(grid[i][j] == '*' && i < h-1)
        return rayd(i+1, j);
    else if(grid[i][j] == '*')
        return i;
    else
        return i-1;
}

bool ray()
{
    l = rayl(cy, cx);
    r = rayr(cy, cx);
    u = rayu(cy, cx);
    d = rayd(cy, cx);

    if(l == cx || r == cx || u == cy || d == cy)
        return 0;
    return 1;
}

int main()
{
    int i, j;
    scanf("%d %d", &h, &w);
    for(i = 0; i < h; i++)
    {
        getchar();
        for(j = 0; j < w; j++)
            scanf("%c", &grid[i][j]);
    }
    /*for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
            printf("%c", grid[i][j]);
        printf("\n");
    }*/
    for(i = 1; i < h-1; i++)
    {
        for(j = 1; j < w-1; j++)
        {
            if(grid[i][j] == '*')
            {
                cx = j;
                cy = i;
                found = ray();
            }
            if(found)
                break;
        }
        if(found)
            break;
    }

    //printf("%d %d %d %d %d %d\n", cx, cy, l, r, u, d);

    if(!found)
    {
        printf("NO");
        return 0;
    }

    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(grid[i][j] == '*')
            {
                if(i != cy && j != cx)
                {
                    printf("NO");
                    return 0;
                }
                if(i == cy && (j < l || j > r))
                {
                    printf("NO");
                    return 0;
                }
                if(j == cx && (i < u || i > d))
                {
                    //printf("%d %d\n", i, j);
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("YES");
}
