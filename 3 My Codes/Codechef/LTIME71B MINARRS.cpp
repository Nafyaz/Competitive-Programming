#include<bits/stdc++.h>
using namespace std;
int a[32];

void func(int x)
{
    for(int i = 0; x; i++)
    {
        a[i] += x&1;
        x = x >> 1;
    }
}

int main()
{
    int t, n, i, b;
    long long ans;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &b);
            func(b);
        }
        for(i = 31; i >= 0; i--)
        {
            ans = ans << 1;
            ans += min(a[i], n - a[i]);

            a[i] = 0;
        }
        printf("%lld\n", ans);
    }
}
