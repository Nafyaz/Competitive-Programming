#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    scanf("%d", &n);

    int s[n], r[n], h[n], c[n], maxsum = 0, maxi;

    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &s[i], &r[i], &h[i], &c[i]);
        if(maxsum < s[i] + r[i] + h[i] + c[i])
        {
            maxsum = s[i] + r[i] + h[i] + c[i];
            maxi = i;
        }
    }

    int mini, mincost = 1100;
    for(i = 0; i < n ; i++)
    {
        if(s[i] >= s[maxi] && r[i] >= r[maxi] && h[i] >= h[maxi])
        {
            if(mincost > c[i])
            {
                mincost = c[i];
                mini = i;
            }
        }
    }
    printf("%d", mini + 1);
}
