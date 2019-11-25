#include<bits/stdc++.h>
using namespace std;

int h, w;
char grid[600][600];

void scadoosh(int i, int j)
{
    int x;
    for(x = i+1; x < h && grid[x][j] == '*'; x++)
        grid[x][j] = '.';
    for(x = i-1; x >= 0 && grid[x][j] == '*' ; x--)
        grid[x][j] = '.';
    for(x = j+1; x < w && grid[i][x] == '*'; x++)
        grid[i][x] = '.';
    for(x = j-1; x >= 0 && grid[i][x] == '*' ; x--)
        grid[i][x] = '.';

    grid[i][j] = '.';
}

int main()
{
    int i, j, found = 0;
    scanf("%d %d", &h, &w);
    getchar();
    for(i = 0; i < h; i++)
        gets(grid[i]);

    for(i = 1; i < h-1; i++)
    {
        for(j = 1; j < w-1; j++)
        {
            if(grid[i][j] == '*')
            {
                if(grid[i-1][j] == '*' && grid[i+1][j] == '*' && grid[i][j-1] == '*' && grid[i][j+1] == '*')
                {
                    scadoosh(i, j);
                    found = 1;
                }
            }
            if(found)
                break;
        }
        if(found)
            break;
    }

    for(i = 0; i < h; i++)
    {
        if(!found)
            break;
        for(j = 0; j < w; j++)
        {
            if(grid[i][j] == '*')
            {
                found = 0;
                break;
            }
        }
    }

    found? printf("YES") : printf("NO");

}
