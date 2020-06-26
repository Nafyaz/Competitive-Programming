#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, ans;
    scanf("%lld", &n);
    long long a[n];

    for(i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    sort(a, a+n);

    long long x = upper_bound(a, a+n, a[0]) - a;
    long long y = n - (lower_bound(a, a+n, a[n-1]) - a);

    ans = (a[n-1] == a[0]? n*(n-1)/2 : x*y);
    printf("%lld %lld", a[n-1] - a[0], ans);
}
