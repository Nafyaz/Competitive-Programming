#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)
bool grid[2004][2004];
int main()
{
    int n, i, j, k, c, ans = 0;
    scanf("%d", &n);
    int x[n], y[n], xmin = 1002, xmax = -1002, ymin = 1002, ymax = -1002;
    FORAB(i, 0, n)
    {
        scanf("%d %d", &x[i], &y[i]);
        grid[x[i] + 1002][y[i] + 1002] = 1;
    }
    FORAB(i, 0, n)
    {
        c = 0;
        FORAB(j, 0, x[i] + 1002)//down
        {
            if(grid[x[i] + 1002][j] == 1)
            {
                c++;
                break;
            }
        }
        FORAB(j, x[i] + 1003, 2004)//up
        {
            if(grid[x[i] + 1002][j] == 1)
            {
                c++;
                break;
            }
        }
        FORAB(j, 0, x[i] + 1002)//left
        {
            if(grid[j][x[i] + 1002] == 1)
            {
                c++;
                break;
            }
        }
        FORAB(j, x[i] + 1003, 2004)//right
        {
            if(grid[j][x[i] + 1002] == 1)
            {
                c++;
                break;
            }
        }
        if(c == 4)
        {
            ans++;
            printf("%d %d\n", x[i], y[i]);
        }

    }
    printf("%d", ans);

}
