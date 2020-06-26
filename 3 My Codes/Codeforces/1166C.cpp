#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, ans = 0;
    scanf("%lld", &n);
    long long a[n];
    for(i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] = abs(a[i]);
    }
    sort(a, a+n);

    for(i = 0; i < n - 1; i++)
       ans += upper_bound(a+i, a+n, 2*a[i]) - a - i - 1;

    printf("%lld", ans);
}
