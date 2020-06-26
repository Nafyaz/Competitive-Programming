#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0, n, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int x[n + 1][2], y[n + 1][2], z[n + 1][2];
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d", &x[i][0], &y[i][0], &z[i][0]);
            scanf("%d %d %d", &x[i][1], &y[i][1], &z[i][1]);
            sort(x[i], x[i] + 2);
            sort(y[i], y[i] + 2);
            sort(z[i], z[i] + 2);

            if(i == 0)
            {
                x[n][0] = x[i][0]; x[n][1] = x[i][1];
                y[n][0] = y[i][0]; y[n][1] = y[i][1];
                z[n][0] = z[i][0]; z[n][1] = z[i][1];
            }
            else
            {
                if(x[n][0] < x[i][0])
                    x[n][0]= x[i][0];
                if(x[n][0] >= x[n][1])
                    x[n][0] = 0;

                if(x[n][1] > x[i][1])
                    x[n][1] = x[i][1];
                if(x[n][1] <= x[n][0])
                    x[n][1] = 0;

                if(y[n][0] < y[i][0])
                    y[n][0]= y[i][0];
                if(y[n][0] >= y[n][1])
                    y[n][0] = 0;

                if(y[n][1] > y[i][1])
                    y[n][1] = y[i][1];
                if(y[n][1] <= y[n][0])
                    y[n][1] = 0;

                if(z[n][0] < z[i][0])
                    z[n][0]= z[i][0];
                if(z[n][0] >= z[n][1])
                    z[n][0] = 0;

                if(z[n][1] > z[i][1])
                    z[n][1] = z[i][1];
                if(z[n][1] <= z[n][0])
                    z[n][1] = 0;
            }
        }
        printf("Case %d: %d\n", ++caseno,  (x[n][1] - x[n][0]) * (y[n][1] - y[n][0]) * (z[n][1] - z[n][0]) );
    }
}

