#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, i, j, ans = 0, n1, m1;
    scanf("%lld %lld", &n, &m);
    long long b[n], g[m];
    for(i = 0; i < n; i++)
    {
        scanf("%lld", &b[i]);
        ans += b[i];
    }
    ans *= m;
    for(i = 0; i < m; i++)
        scanf("%lld", &g[i]);

    sort(b, b+n);
    sort(g, g+m);
    n1 = n;
    m1 = m;
    int flag = 0;
    for(i = m-1; i >=0; i--)
    {
        if(g[i] < b[n1 - 1])
        {
            printf("-1");
            return 0;
        }
        if(g[i] == b[n1 - 1])
        {
            flag = 1;
        }

        if(flag == 0 && i == 0)
        {
            n1--;
            if(g[i] < b[n1 - 1])
            {
                printf("-1");
                return 0;
            }
        }
        ans += g[i] - b[n1 - 1];
    }
    printf("%lld", ans);
}
