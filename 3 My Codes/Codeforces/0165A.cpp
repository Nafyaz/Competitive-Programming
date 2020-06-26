#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)
bool grid[2004][2004];

void print_grid();
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


    //print_grid();
    FORAB(i, 0, n)
    {
        c = 0;
        FORAB(j, 0, y[i] + 1002)//down
        {
            if(grid[x[i] + 1002][j] == 1)
            {
                c++;
                break;
            }
        }
        FORAB(j, y[i] + 1003, 2004)//up
        {
            if(grid[x[i] + 1002][j] == 1)
            {
                c++;
                break;
            }
        }
        FORAB(j, 0, x[i] + 1002)//left
        {
            if(grid[j][y[i] + 1002] == 1)
            {
                c++;
                break;
            }
        }
        FORAB(j, x[i] + 1003, 2004)//right
        {
            if(grid[j][y[i] + 1002] == 1)
            {
                c++;
                break;
            }
        }

        if(c == 4)
        {
            ans++;
        }

    }
    printf("%d", ans);

}
void print_grid()
{
    int i, j;
    for(i = 1006; i >= 1000; i--)
    {
        FORAB(j, 1000, 1007)
        {
            printf("%d ", grid[j][i]);
        }
        printf("\n");
    }
}
