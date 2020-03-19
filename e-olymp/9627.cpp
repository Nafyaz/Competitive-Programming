#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll bigmod(ll a, ll p, ll m)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%m;
    ll x = 1, y;
    if(p&1)
        x = a%m;
    y = bigmod(a, p/2, m);

    return (((y*y)%m) * x)%m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, a, b, c, p;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        p = bigmod(b, c, mod-1);
        printf("%lld\n", bigmod(a, p, mod));
    }
}

