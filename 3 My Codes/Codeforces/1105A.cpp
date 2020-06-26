#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i, j, cost, mini, mincost = 1000000;
    scanf("%d", &n);
    int a[n];
    FORAB(i, 0, n)
        scanf("%d", &a[i]);

    sort(a, a+n);
    FORAB(i, a[0], a[n - 1] + 1)
    {
        cost = 0;
        FORAB(j, 0, n)
        {
            if(a[j] < i)
                cost = cost + i - 1 - a[j];
            else if(a[j] > i)
                cost = cost + a[j] - (i + 1);
        }
        if(cost < mincost)
        {
            mincost = cost;
            mini = i;
        }
    }
    printf("%d %d", mini, mincost);
}
