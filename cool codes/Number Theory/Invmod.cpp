#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bigmod(ll a, ll p, ll m)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%m;
    ll x = 1;
    if(p&1)
        x = a%m;
    ll y = bigmod(a, p/2, m);
    return ((y*y)%m*x)%m;
}

ll invmod(ll a, ll m)
{
    return bigmod(a, m-2, m);
}
