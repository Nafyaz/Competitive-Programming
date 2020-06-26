#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    scanf("%d", &t);
    int i, m, pos;
    long long sum, a[100010];
    long double mean;

    while(t--)
    {
        sum = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            sum += a[i];
        }

        mean = (long double)sum / n;

        if(floor(mean) != ceil(mean))
        {
            printf("Impossible\n");
            continue;
        }
        m = (int)mean;

        int flag = 1;
        for(i = 0; i < n; i++)
        {
            if(flag && a[i] == m)
            {
                printf("%d\n", i+1);
                flag = 0;
            }
        }
        if(flag)
            printf("Impossible\n");
    }
}
