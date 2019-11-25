#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i, ans = 0, gcd = -1, total = 0, prev = 0;
    scanf("%d %d", &n, &k);
    int a[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(gcd == -1)
        {
            gcd = a[i];
            ans = max(ans, 1);
            total = 1;
            i = prev;
            prev++;
            continue;
        }

        gcd = __gcd(gcd, a[i]);
        if(gcd >= k)
        {
            total ++;
            ans = max(ans, total);
        }
        else
        {
            gcd = -1;
            total = 0;
        }
    }

    printf("%d", ans);
}
