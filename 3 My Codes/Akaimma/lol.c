#include<stdio.h>
int main()
{
    freopen("C:/Users/NAFIS/Desktop/10000.txt", "r", stdin);
    long long n, i, j, m, mn, mx;
    scanf("%lld", &n);
    long long a[n+1];
    a[0] = 0;
    if(n < 500000)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            a[i] += a[i - 1];
        }
        for(i = 1; i < n+1; i++)
        {
            if(i == 1)
            {
                m = a[i];
                continue;
            }
            for(j = 0; j < i; j++)
            {
                if(m < a[i] - a[j])
                    m = a[i] - a[j];
            }
        }
        printf("%lld", m);

    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            a[i] += a[i - 1];
        }
        for(i = 0; i < n+1; i++)
        {
            if(i == 0)
            {
                mn = a[i];
                mx = a[i];
                continue;
            }
            if(a[i] > mx)
                mx = a[i];
            if(a[i] < mn)
                mn = a[i];
        }
        printf("%lld", mx - mn);
    }
}

