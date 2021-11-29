#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100007
ll inv[N];

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
ll bigmod2(ll a, ll b, ll mod)
{
    ll res = 1%mod;
    while (b)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

ll invmod(ll a, ll m)  //only if m is prime and gcd(a, m) = 1
{
    return bigmod(a, m-2, m);
}

ll egcd(ll a, ll m, ll& x, ll& y)
{
    if(m == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = egcd(m, a%m, x1, y1);

    x = y1;
    y = x1 - y1*(a/m);

    return d;
}

ll invmod2(ll a, ll m)  //when gcd(a, m) = 1
{
    ll x, y;
    egcd(a, m, x, y);

    return (x%m + m) % m;
}

void allinvmod()  //when N is prime
{
    ll i;
    inv[1] = 1;
    for(i = 2; i < N; i++)
        inv[i] = ((-N/i*inv[N%i]) % N + N) % N;
}

int main()
{
//    cout << bigmod2(17, 9, 55);
    cout << invmod(12, 1000000007);
}
