#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, w, i, prev = 0, x, mx = -1000010, mn = 1000010;

    scanf("%lld %lld", &n, &w);
    for(i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        prev += x;
        mx = max(prev, mx);
        mn = min(prev, mn);
    }
    if(mn < 0)
        mx -= mn;
    printf("%lld", max(0LL, w - mx + 1));
}
