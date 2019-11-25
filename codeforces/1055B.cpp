#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, l, i, x, p, d, c = 0;
    scanf("%lld %lld %lld", &n, &m, &l);
    int a[n+2], b[n+2];

    for(i = 0; i < n+2; i++)
        b[i] = 0;

    for(i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if(a[i] > l)
        {
            b[i] = 1;
            c++;
        }
        if(b[i-1] == 1)
            c--;
    }

    while(m--)
    {
        scanf("%lld", &x);
        if(!x)
        {
            printf("%lld\n", c);
            continue;
        }

        scanf("%lld %lld", &p, &d);
        a[p] += d;
        if(b[p] == 0 && a[p] > l)
        {
            b[p] = 1;
            c++;

            if(b[p - 1] == 1 || b[p+1] == 1)
                c--;
            if(b[p-1] == 1 && b[p+1] == 1)
                c--;
        }
    }
}
