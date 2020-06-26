#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, ans;
    int a[100010], b[100010];
    scanf("%d", &t);
    while(t--)
    {
        ans = -1;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &b[i]);

        a[n] = b[n] = 0;
        for(i = n-1; i >= 0; i--)
        {
            a[i] = a[i] + a[i + 1];
            b[i] = b[i] + b[i + 1];
        }

        for(i = 0; i <= n; i++)
            ans = max(ans, a[0] - a[i] + b[i]);


        printf("%d\n", ans);
    }
}
