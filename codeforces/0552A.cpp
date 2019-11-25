#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i <= b; i++)
int a[110][110];
int main()
{
    int n, x1, y1, x2, y2, i, j, sum = 0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        FORAB(i, x1, x2)
        {
            FORAB(j, y1, y2)
                a[i][j]++;
        }
    }
    FORAB(i, 1, 102)
    {
        FORAB(j, 1, 102)
            sum += a[i][j];
    }
    printf("%d\n", sum);
}

